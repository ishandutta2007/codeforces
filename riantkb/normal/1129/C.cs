using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

using static util;
using P = pair<int, int>;

using Binary = System.Func<System.Linq.Expressions.ParameterExpression,
                           System.Linq.Expressions.ParameterExpression,
                           System.Linq.Expressions.BinaryExpression>;
using Unary = System.Func<System.Linq.Expressions.ParameterExpression,
                          System.Linq.Expressions.UnaryExpression>;

class Program {
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
    static Scan sc = new Scan();
    const int M = 1000000007;
    const int M2 = 998244353;
    const long LM = 1L << 60;
    const double eps = 1e-11;
    static readonly int[] dd = { 0, 1, 0, -1, 0 };
    const string dstring = "RDLU";
    static void Main(string[] args)
    {
        int m = sc.Int;
        var trie = new Trie(0, 2);
        var a = new int[m];
        var s = new List<int>();
        long ans = 0;
        for (int i = 0; i < m; i++)
        {
            a[i] = sc.Int;
            s.Insert(0, a[i]);
            int l = trie.get_longest_prefix(s);
            var dp = new long[i + 2];
            dp[0] = 1;
            for (int j = 0; j <= i; j++)
            {
                int b = 0;
                for (int k = 0; k < 4 && k <= j; k++)
                {
                    b = b * 2 + a[i - j + k];
                    if (k < 3 || b != 3 && b != 5 && b != 14 && b != 15) {
                        dp[j + 1] = (dp[j + 1] + dp[j - k]) % M;
                    }
                }
            }
            for (int j = l + 1; j <= i + 1; j++)
            {
                ans = (ans + dp[j]) % M;
            }
            Prt(ans);
            trie.insert(s);
        }

        sw.Flush();
    }

    static void DBG(string a) => Console.WriteLine(a);
    static void DBG<T>(IEnumerable<T> a) => DBG(string.Join(" ", a));
    static void DBG(params object[] a) => DBG(string.Join(" ", a));
    static void Prt(string a) => sw.WriteLine(a);
    static void Prt<T>(IEnumerable<T> a) => Prt(string.Join(" ", a));
    static void Prt(params object[] a) => Prt(string.Join(" ", a));
}
class pair<T, U> : IComparable<pair<T, U>> {
    public T v1;
    public U v2;
    public pair() : this(default(T), default(U)) {}
    public pair(T v1, U v2) { this.v1 = v1; this.v2 = v2; }
    public int CompareTo(pair<T, U> a) {
        int c = Comparer<T>.Default.Compare(v1, a.v1);
        return c != 0 ? c : Comparer<U>.Default.Compare(v2, a.v2);
    }
    public override string ToString() => v1 + " " + v2;
    public void Deconstruct(out T a, out U b) { a = v1; b = v2; }
    public static bool operator>(pair<T, U> a, pair<T, U> b) => a.CompareTo(b) > 0;
    public static bool operator<(pair<T, U> a, pair<T, U> b) => a.CompareTo(b) < 0;
    public static bool operator>=(pair<T, U> a, pair<T, U> b) => a.CompareTo(b) >= 0;
    public static bool operator<=(pair<T, U> a, pair<T, U> b) => a.CompareTo(b) <= 0;
}
static class util {
    public static pair<T, U> make_pair<T, U>(T v1, U v2) => new pair<T, U>(v1, v2);
    public static T sq<T>(T a) => Operator<T>.Multiply(a, a);
    public static T Max<T>(params T[] a) => a.Max();
    public static T Min<T>(params T[] a) => a.Min();
    public static bool inside(int i, int j, int h, int w) => i >= 0 && i < h && j >= 0 && j < w;
    public static Dictionary<T, int> compress<T>(this IEnumerable<T> a)
        => a.Distinct().OrderBy(v => v).Select((v, i) => new { v, i }).ToDictionary(p => p.v, p => p.i);
    public static Dictionary<T, int> compress<T>(params IEnumerable<T>[] a) => compress(a.Aggregate(Enumerable.Union));
    public static void swap<T>(ref T a, ref T b) where T : struct { var t = a; a = b; b = t; }
    public static void swap<T>(this IList<T> a, int i, int j) where T : struct { var t = a[i]; a[i] = a[j]; a[j] = t; }
    public static T[] copy<T>(this IList<T> a) {
        var ret = new T[a.Count];
        for (int i = 0; i < a.Count; i++) ret[i] = a[i];
        return ret;
    }
}
static class Operator<T> {
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

class Scan {
    StreamReader sr;
    public Scan() { sr = new StreamReader(Console.OpenStandardInput()); }
    public Scan(string path) { sr = new StreamReader(path); }
    public int Int => int.Parse(Str);
    public long Long => long.Parse(Str);
    public double Double => double.Parse(Str);
    public string Str => sr.ReadLine().Trim();
    public pair<T, U> Pair<T, U>() {
        T a; U b;
        Multi(out a, out b);
        return new pair<T, U>(a, b);
    }
    public P P => Pair<int, int>();
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
}
class Trie {
    public int cnt, dep;
    private readonly int fir;
    private readonly int len;
    Trie[] childs;

    public Trie(int fir, int len) : this(fir, len, 0) {}
    Trie(int fir, int len, int dep) {
        cnt = 0;
        this.dep = dep;
        this.fir = fir;
        this.len = len;
        childs = new Trie[len];
    }

    // get count of prefix == s
    public int getcnt(IList<int> s) {
        if (dep == s.Count) return cnt;
        if (childs[s[dep] - fir] == null) return 0;
        return childs[s[dep] - fir].getcnt(s);
    }
    public int get_longest_prefix(IList<int> s) {
        if (dep == s.Count) return dep;
        if (childs[s[dep] - fir] == null) return dep;
        return childs[s[dep] - fir].get_longest_prefix(s);
    }
    public void insert(IList<int> s) {
        ++cnt;
        if (dep == s.Count) return;
        if (childs[s[dep] - fir] == null) childs[s[dep] - fir] = new Trie(fir, len, dep + 1);
        childs[s[dep] - fir].insert(s);
    }
    public T calc_all_nodes<T>(T val, Func<Trie, T> get_val, Func<T, T, T> f) {
        val = f(val, get_val(this));
        foreach (var item in childs) if (item != null) val = item.calc_all_nodes(val, get_val, f);
        return val;
    }
}