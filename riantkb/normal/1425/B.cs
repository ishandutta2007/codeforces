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
        // var t = new Thread(solver.solve, 1 << 28); // 256 MB
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
        int n, m;
        sc.Multi(out n, out m);
        var uf = new UnionFind(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            sc.Multi(out u, out v);
            --u;
            --v;
            if (u != 0 && v != 0) {
                uf.unite(u, v);
            }
        }
        var a = new List<int>();
        for (int i = 1; i < n; i++)
        {
            if (uf.ispar(i)) {
                a.Add(uf.unionsize(i) + 1);
            }
        }
        Assert(a.Sum() == m);
        int N = a.Count;
        int ofst = m;
        long ans = 0;
        {
            var dpl = new int[N + 1][];
            var dpr = new int[N + 1][];
            for (int i = 0; i < N + 1; i++)
            {
                dpl[i] = new int[m * 2 + 1];
                dpr[i] = new int[m * 2 + 1];
            }
            dpl[0][ofst] = 1;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < m * 2 + 1; j++)
                {
                    if (dpl[i][j] == 0) continue;
                    dpl[i + 1][j + a[i]] = (dpl[i + 1][j + a[i]] + dpl[i][j]) % M;
                    dpl[i + 1][j] = (dpl[i + 1][j] + dpl[i][j]) % M;
                    dpl[i + 1][j - a[i]] = (dpl[i + 1][j - a[i]] + dpl[i][j]) % M;
                }
            }
            dpr[N][ofst] = 1;
            for (int i = N - 1; i >= 0 ; i--)
            {
                for (int j = 0; j < m * 2 + 1; j++)
                {
                    if (dpr[i + 1][j] == 0) continue;
                    dpr[i][j + a[i]] = (dpr[i][j + a[i]] + dpr[i + 1][j]) % M;
                    dpr[i][j] = (dpr[i][j] + dpr[i + 1][j]) % M;
                    dpr[i][j - a[i]] = (dpr[i][j - a[i]] + dpr[i + 1][j]) % M;
                }
            }
            for (int i = 0; i < N; i++)
            {
                var ims = new long[m * 2 + 2];
                for (int j = 0; j < m * 2 + 1; j++)
                {
                    ims[j + 1] = (ims[j] + dpr[i + 1][j]) % M;
                }
                for (int j = 0; j < m * 2 + 1; j++)
                {
                    int p = j - ofst;
                    int ql = Math.Max(-a[i] - p + 2 + ofst, 0);
                    int qr = Math.Min(a[i] - p - 2 + ofst, m * 2);
                    if (qr >= ql) {
                        ans = (ans + (long)dpl[i][j] * ((ims[qr + 1] - ims[ql] + M) % M) % M * 2) % M;
                    }
                }
            }
        }
        {
            var dpl = new int[N + 1][];
            var dpr = new int[N + 1][];
            for (int i = 0; i < N + 1; i++)
            {
                dpl[i] = new int[m * 2 + 1];
                dpr[i] = new int[m * 2 + 1];
            }
            dpl[0][ofst] = 1;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < m * 2 + 1; j++)
                {
                    if (dpl[i][j] == 0) continue;
                    dpl[i + 1][j + a[i]] = (dpl[i + 1][j + a[i]] + dpl[i][j]) % M;
                    // dpl[i + 1][j] = (dpl[i + 1][j] + dpl[i][j]) % M;
                    dpl[i + 1][j - a[i]] = (dpl[i + 1][j - a[i]] + dpl[i][j]) % M;
                }
            }
            dpr[N][ofst] = 1;
            for (int i = N - 1; i >= 0 ; i--)
            {
                for (int j = 0; j < m * 2 + 1; j++)
                {
                    if (dpr[i + 1][j] == 0) continue;
                    dpr[i][j + a[i]] = (dpr[i][j + a[i]] + dpr[i + 1][j]) % M;
                    // dpr[i][j] = (dpr[i][j] + dpr[i + 1][j]) % M;
                    dpr[i][j - a[i]] = (dpr[i][j - a[i]] + dpr[i + 1][j]) % M;
                }
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < m * 2 + 1; j++)
                {
                    int p = j - ofst;
                    int ql = -a[i] - p + 1 + ofst;
                    int qr = a[i] - p - 1 + ofst;
                    if (0 <= ql && ql <= m * 2) {
                        ans = (ans + (long)dpl[i][j] * dpr[i + 1][ql] % M * 2) % M;
                    }
                    if (0 <= qr && qr <= m * 2) {
                        ans = (ans + (long)dpl[i][j] * dpr[i + 1][qr] % M * 2) % M;
                    }
                }
            }

        }
        if (m % 2 == 0) {
            var dp = new long[m / 2 + 1];
            dp[0] = 1;
            foreach (var item in a)
            {
                for (int i = m / 2; i >= item ; i--)
                {
                    dp[i] = (dp[i] + dp[i - item]) % M;
                }
            }
            ans = (ans + dp[m / 2]) % M;
        }

        Prt(ans);




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
        if (conds.Any(x => !x)) throw new Exception();
    }
    public static pair<T, U> make_pair<T, U>(T v1, U v2) => new pair<T, U>(v1, v2);
    public static int CompareList<T>(IList<T> a, IList<T> b) where T : IComparable<T> {
        for (int i = 0; i < a.Count && i < b.Count; i++)
            if (a[i].CompareTo(b[i]) != 0) return a[i].CompareTo(b[i]);
        return a.Count.CompareTo(b.Count);
    }
    public static bool inside(int i, int j, int h, int w) => i >= 0 && i < h && j >= 0 && j < w;
    public static readonly int[] dd = { 0, 1, 0, -1 };
    // static readonly string dstring = "RDLU";
    public static IEnumerable<P> adjacents(int i, int j)
        => Enumerable.Range(0, dd.Length).Select(k => new P(i + dd[k], j + dd[k ^ 1]));
    public static IEnumerable<P> adjacents(int i, int j, int h, int w)
        => adjacents(i, j).Where(p => inside(p.v1, p.v2, h, w));
    public static IEnumerable<P> adjacents(this P p) => adjacents(p.v1, p.v2);
    public static IEnumerable<P> adjacents(this P p, int h, int w) => adjacents(p.v1, p.v2, h, w);
    public static IEnumerable<int> all_subset(this int p) {
        for (int i = 0; ; i = i - p & p) {
            yield return i;
            if (i == p) break;
        }
    }
    public static Dictionary<T, int> compress<T>(this IEnumerable<T> a)
        => a.Distinct().OrderBy(v => v).Select((v, i) => new { v, i }).ToDictionary(p => p.v, p => p.i);
    public static Dictionary<T, int> compress<T>(params IEnumerable<T>[] a) => compress(a.SelectMany(x => x));
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
    public string Str => ReadLine.Trim();
    public string ReadLine => sr.ReadLine();
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
class UnionFind {
    int num;
    int[] par, sz, rank;
    public UnionFind(int n) {
        num = n;
        par = new int[n];
        sz = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
            rank[i] = 0;
        }
    }
    int find(int x) => par[x] == x ? x : (par[x] = find(par[x]));
    public bool same(int x, int y) => find(x) == find(y);
    public int unionsize(int x) => sz[find(x)];
    public int unioncount => num;
    public bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        --num;
        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        }
        else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) ++rank[x];
        }
        return true;
    }
    public bool ispar(int x) => x == find(x);
    public int getpar(int x) => find(x);
}