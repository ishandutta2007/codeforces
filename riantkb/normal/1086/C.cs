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
        int T = sc.Int;
        for (int _ = 0; _ < T; _++)
        {
            int k = sc.Int;
            var s = sc.Str.Select(x => x - 'a').ToArray();
            var a = sc.Str.Select(x => x - 'a').ToArray();
            var b = sc.Str.Select(x => x - 'a').ToArray();
            int n = s.Length;
            var map = new int[k];
            var inv = new int[k];
            for (int i = 0; i < k; i++)
            {
                map[i] = -1;
                inv[i] = -1;
            }
            for (int i = 0; i < n; i++)
            {
                if (map[s[i]] != -1) {
                    if (a[i] > map[s[i]] || map[s[i]] > b[i]) {
                        Prt("NO");
                        goto A;
                    }
                    if (a[i] < map[s[i]] && map[s[i]] < b[i]) {
                        tekitou(map, inv);
                        Prt("YES");
                        Prt(new string(map.Select(x => (char)(x + 'a')).ToArray()));
                        goto A;
                    }
                    if (a[i] < map[s[i]]) {
                        var cpmap = map.copy();
                        var cpinv = inv.copy();
                        if (smaller(s, a, b, cpmap, cpinv, i + 1)) {
                            tekitou(cpmap, cpinv);
                            Prt("YES");
                            Prt(new string(cpmap.Select(x => (char)(x + 'a')).ToArray()));
                            goto A;
                        }
                        else {
                            Prt("NO");
                            goto A;
                        }
                    }
                    if (map[s[i]] < b[i]) {
                        var cpmap = map.copy();
                        var cpinv = inv.copy();
                        if (larger(s, a, b, cpmap, cpinv, i + 1)) {
                            tekitou(cpmap, cpinv);
                            Prt("YES");
                            Prt(new string(cpmap.Select(x => (char)(x + 'a')).ToArray()));
                            goto A;
                        }
                        else {
                            Prt("NO");
                            goto A;
                        }
                    }
                    continue;
                }
                if (a[i] > b[i]) {
                    Prt("NO");
                    goto A;
                }
                else if (a[i] == b[i]) {
                    if (inv[a[i]] != -1) {
                        Prt("NO");
                        goto A;
                    }
                    map[s[i]] = a[i];
                    inv[a[i]] = s[i];
                }
                else {
                    for (int j = a[i] + 1; j < b[i]; j++)
                    {
                        if (inv[j] == -1) {
                            map[s[i]] = j;
                            inv[j] = s[i];
                            tekitou(map, inv);
                            Prt("YES");
                            Prt(new string(map.Select(x => (char)(x + 'a')).ToArray()));
                            goto A;
                        }
                    }
                    if (inv[a[i]] == -1) {
                        var cpmap = map.copy();
                        var cpinv = inv.copy();
                        cpmap[s[i]] = a[i];
                        cpinv[a[i]] = s[i];
                        if (larger(s, a, b, cpmap, cpinv, i + 1)) {
                            tekitou(cpmap, cpinv);
                            Prt("YES");
                            Prt(new string(cpmap.Select(x => (char)(x + 'a')).ToArray()));
                            goto A;
                        }
                    }
                    if (inv[b[i]] == -1) {
                        var cpmap = map.copy();
                        var cpinv = inv.copy();
                        cpmap[s[i]] = b[i];
                        cpinv[b[i]] = s[i];
                        if (smaller(s, a, b, cpmap, cpinv, i + 1)) {
                            tekitou(cpmap, cpinv);
                            Prt("YES");
                            Prt(new string(cpmap.Select(x => (char)(x + 'a')).ToArray()));
                            goto A;
                        }
                    }
                    Prt("NO");
                    goto A;
                }
            }
            tekitou(map, inv);
            Prt("YES");
            Prt(new string(map.Select(x => (char)(x + 'a')).ToArray()));
            A:
            continue;
        }
        sw.Flush();
    }
    static bool larger(int[] s, int[] a, int[] b, int[] map, int[] inv, int l) {
        int n = s.Length;
        int k = map.Length;
        for (int i = l; i < n; i++)
        {
            if (map[s[i]] != -1) {
                if (a[i] < map[s[i]]) return true;
                if (a[i] > map[s[i]]) return false;
            }
            else {
                for (int j = k - 1; j > a[i]; j--)
                {
                    if (inv[j] == -1) {
                        map[s[i]] = j;
                        inv[j] = s[i];
                        return true;
                    }
                }
                if (inv[a[i]] != -1) return false;
                map[s[i]] = a[i];
                inv[a[i]] = s[i];
            }
        }
        return true;
    }
    static bool smaller(int[] s, int[] a, int[] b, int[] map, int[] inv, int l) {
        int n = s.Length;
        int k = map.Length;
        for (int i = l; i < n; i++)
        {
            if (map[s[i]] != -1) {
                if (b[i] > map[s[i]]) return true;
                if (b[i] < map[s[i]]) return false;
            }
            else {
                for (int j = 0; j < b[i]; j++)
                {
                    if (inv[j] == -1) {
                        map[s[i]] = j;
                        inv[j] = s[i];
                        return true;
                    }
                }
                if (inv[b[i]] != -1) return false;
                map[s[i]] = b[i];
                inv[b[i]] = s[i];
            }
        }
        return true;
    }
    static void tekitou(int[] map, int[] inv) {
        int n = map.Length;
        var used = new bool[n];
        for (int i = 0; i < n; i++)
        {
            if (map[i] != -1) {
                used[map[i]] = true;
            }
        }
        var lis = new List<int>();
        for (int i = 0; i < n; i++)
        {
            if (!used[i]) lis.Add(i);
        }
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (map[i] == -1) {
                map[i] = lis[j];
                inv[lis[j]] = i;
                ++j;
            }
        }
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