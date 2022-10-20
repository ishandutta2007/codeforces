using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Threading;
using System.Text;
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
        int n, k;
        sc.Multi(out n, out k);
        // n = 200000;
        // k = 180000;
        var p = new P[n];
        var idx = new int[n];
        var rnd = new Random();
        for (int i = 0; i < n; i++)
        {
            int l, r;
            sc.Multi(out l, out r);
            // l = rnd.Next(1, 200000);
            // r = rnd.Next(1, 200000);
            // if (l > r) {
            //     swap(ref l, ref r);
            // }
            --l;
            p[i] = new P(r, l);
            idx[i] = i;
        }
        Array.Sort(p, idx);
        var sg = new LazySegtree<int, int>(200010, Math.Max, (x, y, l, r) => x + y, (x, y) => x + y, 0);
        var lis = new List<int>();
        for (int i = 0; i < n; i++)
        {
            if (sg.run(p[i].v2, p[i].v1) < k) {
                sg.update(p[i].v2, p[i].v1, 1);
            }
            else lis.Add(idx[i] + 1);
        }
        lis.Sort();
        Prt(lis.Count);
        Prt(lis);

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
    public static void Assert(bool cond) { if (!cond) throw new Exception(); }
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

class LazySegtree<T, U> {
    int n;
    T[] data;
    U[] lazy;
    bool[] is_lazy;
    Func<T, T, T> calc;
    Func<T, U, int, int, T> apply;
    Func<U, U, U> merge;
    T identity;

    public LazySegtree(int m, Func<T, T, T> calc, Func<T, U, int, int, T> apply, Func<U, U, U> merge, T identity) {
        this.calc = calc;
        this.apply = apply;
        this.merge = merge;
        this.identity = identity;
        n = 1;
        while (n < m) n <<= 1;
        data = new T[n * 2 - 1];
        lazy = new U[n * 2 - 1];
        is_lazy = new bool[n * 2 - 1];
        for (int i = 0; i < data.Length; i++) data[i] = identity;
    }
    public LazySegtree(int m, Func<T, T, T> calc, Func<T, U, int, int, T> apply, Func<U, U, U> merge, T identity, T ini) : this(m, calc, apply, merge, identity) {
        for (int i = 0; i < m; i++) data[i + n - 1] = ini;
        for (int i = n - 2; i >= 0; i--) data[i] = calc(data[i * 2 + 1], data[i * 2 + 2]);
    }
    public LazySegtree(int m, Func<T, T, T> calc, Func<T, U, int, int, T> apply, Func<U, U, U> merge, T identity, IList<T> ini) : this(m, calc, apply, merge, identity) {
        for (int i = 0; i < m; i++) data[i + n - 1] = ini[i];
        for (int i = n - 2; i >= 0; i--) data[i] = calc(data[i * 2 + 1], data[i * 2 + 2]);
    }
    void assign_lazy(int k, U x) {
        if (k >= lazy.Length) return;
        lazy[k] = is_lazy[k] ? merge(lazy[k], x) : x;
        is_lazy[k] = true;
    }
    void eval(int k, int l, int r){
        if (!is_lazy[k]) return;
        assign_lazy(k * 2 + 1, lazy[k]);
        assign_lazy(k * 2 + 2, lazy[k]);
        data[k] = apply(data[k], lazy[k], l, r);
        is_lazy[k] = false;
    }
    T update(int s, int t, U x, int k, int l, int r) {
        eval(k, l, r);
        if (r <= s || t <= l) return data[k];
        if (s <= l && r <= t) {
            assign_lazy(k, x);
            return apply(data[k], lazy[k], l, r);
        }
        return data[k] = calc(update(s, t, x, k * 2 + 1, l, (l + r) / 2),
                              update(s, t, x, k * 2 + 2, (l + r) / 2, r));
    }
    T run(int s, int t, int k, int l, int r) {
        eval(k, l, r);
        if (r <= s || t <= l) return identity;
        if (s <= l && r <= t) return data[k];
        return calc(run(s, t, k * 2 + 1, l, (l + r) / 2),
                    run(s, t, k * 2 + 2, (l + r) / 2, r));
    }

    // [s, t)
    public void update(int s, int t, U x) => update(s, t, x, 0, 0, n);
    // [s, t)
    public T run(int s, int t) => run(s, t, 0, 0, n);
}