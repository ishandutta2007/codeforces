using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Threading;
using System.Text;
using System.Text.RegularExpressions;
using System.Diagnostics;
using static util;
using P = pair<int, int>;

class Program {
    static void Main(string[] args) {
        var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        var solver = new Solver(sw);
        // var t = new Thread(solver.solve, 1 << 26); // 64 MB
        // t.Start();
        // t.Join();
        solver.solve();
        sw.Flush();
    }
}

class Solver {
    StreamWriter sw;
    Scan sc;
    void Prt(string a) => sw.WriteLine(a);
    void Prt<T>(IEnumerable<T> a) => Prt(string.Join(" ", a));
    void Prt(params object[] a) => Prt(string.Join(" ", a));
    public Solver(StreamWriter sw) {
        this.sw = sw;
        this.sc = new Scan();
    }

    public void solve() {
        int T = sc.Int;
        for (int _ = 0; _ < T; _++)
        {
            long n, g, b;
            sc.Multi(out n, out g, out b);
            Prt(Math.Max(n, ((n + 1) / 2 - 1) / g * (g + b) + ((n + 1) / 2 % g == 0 ? g : (n + 1) / 2 % g)));
        }

    }
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
}
static class util {
    public static readonly int M = 1000000007;
    // public static readonly int M = 998244353;
    public static readonly long LM = 1L << 60;
    public static readonly double eps = 1e-11;
    public static void DBG(string a) => Console.Error.WriteLine(a);
    public static void DBG<T>(IEnumerable<T> a) => DBG(string.Join(" ", a));
    public static void DBG(params object[] a) => DBG(string.Join(" ", a));
    public static void Assert(params bool[] conds) {
        foreach (var cond in conds) if (!cond) throw new Exception();
    }
    public static pair<T, U> make_pair<T, U>(T v1, U v2) => new pair<T, U>(v1, v2);
    public static int CompareList<T>(IList<T> a, IList<T> b) where T : IComparable<T> {
        for (int i = 0; i < a.Count && i < b.Count; i++)
            if (a[i].CompareTo(b[i]) != 0) return a[i].CompareTo(b[i]);
        return a.Count.CompareTo(b.Count);
    }
    public static bool inside(int i, int j, int h, int w) => i >= 0 && i < h && j >= 0 && j < w;
    static readonly int[] dd = { 0, 1, 0, -1 };
    // static readonly string dstring = "RDLU";
    public static P[] adjacents(int i, int j)
        => Enumerable.Range(0, dd.Length).Select(k => new P(i + dd[k], j + dd[k ^ 1])).ToArray();
    public static P[] adjacents(int i, int j, int h, int w)
        => Enumerable.Range(0, dd.Length).Select(k => new P(i + dd[k], j + dd[k ^ 1]))
                                         .Where(p => inside(p.v1, p.v2, h, w)).ToArray();
    public static P[] adjacents(this P p) => adjacents(p.v1, p.v2);
    public static P[] adjacents(this P p, int h, int w) => adjacents(p.v1, p.v2, h, w);
    public static Dictionary<T, int> compress<T>(this IEnumerable<T> a)
        => a.Distinct().OrderBy(v => v).Select((v, i) => new { v, i }).ToDictionary(p => p.v, p => p.i);
    public static Dictionary<T, int> compress<T>(params IEnumerable<T>[] a) => compress(a.Aggregate(Enumerable.Union));
    public static T[] inv<T>(this Dictionary<T, int> dic) {
        var res = new T[dic.Count];
        foreach (var item in dic) res[item.Value] = item.Key;
        return res;
    }
    public static void swap<T>(ref T a, ref T b) where T : struct { var t = a; a = b; b = t; }
    public static void swap<T>(this IList<T> a, int i, int j) where T : struct { var t = a[i]; a[i] = a[j]; a[j] = t; }
    public static T[] copy<T>(this IList<T> a) {
        var ret = new T[a.Count];
        for (int i = 0; i < a.Count; i++) ret[i] = a[i];
        return ret;
    }
    public static void Deconstruct<T>(this IList<T> v, out T a) {
        a = v[0];
    }
    public static void Deconstruct<T>(this IList<T> v, out T a, out T b) {
        a = v[0]; b = v[1];
    }
    public static void Deconstruct<T>(this IList<T> v, out T a, out T b, out T c) {
        a = v[0]; b = v[1]; c = v[2];
    }
    public static void Deconstruct<T>(this IList<T> v, out T a, out T b, out T c, out T d) {
        a = v[0]; b = v[1]; c = v[2]; d = v[3];
    }
    public static void Deconstruct<T>(this IList<T> v, out T a, out T b, out T c, out T d, out T e) {
        a = v[0]; b = v[1]; c = v[2]; d = v[3]; e = v[4];
    }
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
    public void Multi<T, U>(out T a, out U b) {
        var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]);
    }
    public void Multi<T, U, V>(out T a, out U b, out V c) {
        var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]);
    }
    public void Multi<T, U, V, W>(out T a, out U b, out V c, out W d) {
        var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]);
    }
    public void Multi<T, U, V, W, X>(out T a, out U b, out V c, out W d, out X e) {
        var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]);
    }
}