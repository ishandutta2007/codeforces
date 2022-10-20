using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;

using static util;
using P = pair<int, int>;

using Binary = System.Func<System.Linq.Expressions.ParameterExpression, System.Linq.Expressions.ParameterExpression,
                           System.Linq.Expressions.BinaryExpression>;
using Unary = System.Func<System.Linq.Expressions.ParameterExpression, System.Linq.Expressions.UnaryExpression>;

class Program
{
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
    static Scan sc = new Scan();
    const int M = 1000000007;
    const int M2 = 998244353;
    const long LM = (long)1e18;
    const double eps = 1e-11;
    static readonly int[] dd = { 0, 1, 0, -1, 0 };
    const string dstring = "RDLU";
    static void Main()
    {
        int h, w;
        sc.Multi(out h, out w);
        var s = new char[h][];
        for (int i = 0; i < h; i++)
        {
            s[i] = sc.Str.ToCharArray();
        }
        var a = calc(s);
        var b = calc(trans(s));
        // Prt(Math.Max(a.v1, b.v1));
        if (a.v1 >= b.v1) {
            foreach (var item in a.v2)
            {
                Prt(new string(item));
            }
        }
        else {
            var ss = trans(b.v2);
            foreach (var item in ss)
            {
                Prt(new string(item));
            }
        }
        sw.Flush();
    }
    static char[][] trans(char[][] s) {
        int h = s.Length, w = s[0].Length;
        var ret = new char[w][];
        for (int i = 0; i < w; i++)
        {
            ret[i] = new char[h];
            for (int j = 0; j < h; j++)
            {
                ret[i][j] = s[j][i];
            }
        }
        return ret;
    }
    static pair<int, char[][]> calc(char[][] s) {
        int h = s.Length, w = s[0].Length;
        string atgc = "ATGC";
        var cnt = new int[h][][];
        for (int i = 0; i < h; i++)
        {
            cnt[i] = new int[2][];
            for (int j = 0; j < 2; j++)
            {
                cnt[i][j] = new int[4];
            }
            for (int j = 0; j < w; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (s[i][j] == atgc[k]) {
                        ++cnt[i][j % 2][k];
                    }
                }
            }
        }
        int[][] map = { new int[]{ 0, 1, 2, 3 },
                        new int[]{ 0, 2, 1, 3 },
                        new int[]{ 0, 3, 1, 2 },
                        new int[]{ 1, 2, 0, 3 },
                        new int[]{ 1, 3, 0, 2 },
                        new int[]{ 2, 3, 0, 1 }};

        int max = -1;
        var ret = new char[h][];
        foreach (var mp in map)
        {
            int sum = 0;
            var tmp = new char[h][];
            for (int i = 0; i < h; i++)
            {
                tmp[i] = new char[2];
                if (i % 2 == 0) {
                    int a = cnt[i][0][mp[0]] + cnt[i][1][mp[1]];
                    int b = cnt[i][0][mp[1]] + cnt[i][1][mp[0]];
                    if (a >= b) {
                        tmp[i][0] = atgc[mp[0]];
                        tmp[i][1] = atgc[mp[1]];
                        sum += a;
                    }
                    else {
                        tmp[i][0] = atgc[mp[1]];
                        tmp[i][1] = atgc[mp[0]];
                        sum += b;
                    }
                }
                else {
                    int a = cnt[i][0][mp[2]] + cnt[i][1][mp[3]];
                    int b = cnt[i][0][mp[3]] + cnt[i][1][mp[2]];
                    if (a >= b) {
                        tmp[i][0] = atgc[mp[2]];
                        tmp[i][1] = atgc[mp[3]];
                        sum += a;
                    }
                    else {
                        tmp[i][0] = atgc[mp[3]];
                        tmp[i][1] = atgc[mp[2]];
                        sum += b;
                    }
                }
            }
            if (sum > max) {
                max = sum;
                for (int i = 0; i < h; i++)
                {
                    ret[i] = new char[w];
                    for (int j = 0; j < w; j++)
                    {
                        ret[i][j] = tmp[i][j % 2];
                    }
                }
            }
        }
        return make_pair(max, ret);
    }

    static void DBG(string a) => Console.WriteLine(a);
    static void DBG<T>(IEnumerable<T> a) => DBG(string.Join(" ", a));
    static void DBG(params object[] a) => DBG(string.Join(" ", a));
    static void Prt(string a) => sw.WriteLine(a);
    static void Prt<T>(IEnumerable<T> a) => Prt(string.Join(" ", a));
    static void Prt(params object[] a) => Prt(string.Join(" ", a));
}
class pair<T, U> : IComparable<pair<T, U>>
{
    public T v1;
    public U v2;
    public pair(T v1, U v2) {
        this.v1 = v1;
        this.v2 = v2;
    }
    public int CompareTo(pair<T, U> a) {
        int c = Comparer<T>.Default.Compare(v1, a.v1);
        return c != 0 ? c : Comparer<U>.Default.Compare(v2, a.v2);
    }
    public override string ToString() => v1 + " " + v2;
    public void Deconstruct(out T a, out U b) {
        a = v1; b = v2;
    }
}
static class util
{
    public static pair<T, T> make_pair<T>(this IList<T> l) => make_pair(l[0], l[1]);
    public static pair<T, U> make_pair<T, U>(T v1, U v2) => new pair<T, U>(v1, v2);
    public static T sq<T>(T a) => Operator<T>.Multiply(a, a);
    public static T Max<T>(params T[] a) => a.Max();
    public static T Min<T>(params T[] a) => a.Min();
    public static bool inside(int i, int j, int h, int w) => i >= 0 && i < h && j >= 0 && j < w;
    public static void swap<T>(ref T a, ref T b) where T : struct { var t = a; a = b; b = t; }
    public static void swap<T>(this IList<T> a, int i, int j) where T : struct { var t = a[i]; a[i] = a[j]; a[j] = t; }
    public static T[] copy<T>(this IList<T> a) {
        var ret = new T[a.Count];
        for (int i = 0; i < a.Count; i++) ret[i] = a[i];
        return ret;
    }
}
static class Operator<T>
{
    static readonly ParameterExpression x = Expression.Parameter(typeof(T), "x");
    static readonly ParameterExpression y = Expression.Parameter(typeof(T), "y");
    public static readonly Func<T, T, T> Add = Lambda(Expression.Add);
    public static readonly Func<T, T, T> Subtract = Lambda(Expression.Subtract);
    public static readonly Func<T, T, T> Multiply = Lambda(Expression.Multiply);
    public static readonly Func<T, T, T> Divide = Lambda(Expression.Divide);
    public static readonly Func<T, T> Plus = Lambda(Expression.UnaryPlus);
    public static readonly Func<T, T> Negate = Lambda(Expression.Negate);
    public static Func<T, T, T> Lambda(Binary op) => Expression.Lambda<Func<T, T, T>>(op(x, y), x, y).Compile();
    public static Func<T, T> Lambda(Unary op) => Expression.Lambda<Func<T, T>>(op(x), x).Compile();
}

class Scan
{
    public int Int => int.Parse(Str);
    public long Long => long.Parse(Str);
    public double Double => double.Parse(Str);
    public string Str => Console.ReadLine().Trim();
    public pair<T, U> Pair<T, U>() where T : IComparable<T> where U : IComparable<U> {
        T a; U b;
        Multi(out a, out b);
        return new pair<T, U>(a, b);
    }
    public P P {
        get {
            int a, b;
            Multi(out a, out b);
            return new P(a, b);
        }
    }
    public int[] IntArr => StrArr.Select(int.Parse).ToArray();
    public long[] LongArr => StrArr.Select(long.Parse).ToArray();
    public double[] DoubleArr => StrArr.Select(double.Parse).ToArray();
    public string[] StrArr => Str.Split(new[]{' '}, StringSplitOptions.RemoveEmptyEntries);
    bool eq<T, U>() => typeof(T).Equals(typeof(U));
    T ct<T, U>(U a) => (T)Convert.ChangeType(a, typeof(T));
    T cv<T>(string s) => eq<T, int>()    ? ct<T, int>(int.Parse(s))
                       : eq<T, long>()   ? ct<T, long>(long.Parse(s))
                       : eq<T, double>() ? ct<T, double>(double.Parse(s))
                       : eq<T, char>()   ? ct<T, char>(s[0])
                                         : ct<T, string>(s);
    public void Multi<T>(out T a) => a = cv<T>(Str);
    public void Multi<T, U>(out T a, out U b)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); }
    public void Multi<T, U, V>(out T a, out U b, out V c)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); }
    public void Multi<T, U, V, W>(out T a, out U b, out V c, out W d)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); }
    public void Multi<T, U, V, W, X>(out T a, out U b, out V c, out W d, out X e)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]); }
    public void Multi<T, U, V, W, X, Y>(out T a, out U b, out V c, out W d, out X e, out Y f)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]); f = cv<Y>(ar[5]); }
}