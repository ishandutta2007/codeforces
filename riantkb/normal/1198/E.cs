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
    static void Main(string[] args)
    {
        int n, m;
        sc.Multi(out n, out m);
        var x1 = new int[m];
        var x2 = new int[m];
        var y1 = new int[m];
        var y2 = new int[m];
        for (int i = 0; i < m; i++)
        {
            sc.Multi(out x1[i], out y1[i], out x2[i], out y2[i]);
            --x1[i];
            --y1[i];
        }
        var xdic = compress(x1, x2);
        var xs = xdic.Keys.ToArray();
        Array.Sort(xs);
        var ydic = compress(y1, y2);
        var ys = ydic.Keys.ToArray();
        Array.Sort(ys);
        int xc = xdic.Count;
        int yc = ydic.Count;
        var exi = new bool[xc][];
        for (int i = 0; i < xc; i++)
        {
            exi[i] = new bool[yc];
        }
        for (int i = 0; i < m; i++)
        {
            int xl = xdic[x1[i]];
            int xr = xdic[x2[i]];
            int yl = ydic[y1[i]];
            int yr = ydic[y2[i]];
            for (int x = xl; x < xr; x++)
            {
                for (int y = yl; y < yr; y++)
                {
                    exi[x][y] = true;
                }
            }
        }

        var mf = new MaxFlow(xc + yc + xc * yc + 2);
        int S = xc + yc + xc * yc;
        int T = S + 1;
        for (int i = 0; i < xc - 1; i++)
        {
            mf.add_edge(S, i, xs[i + 1] - xs[i]);
        }
        for (int i = 0; i < yc - 1; i++)
        {
            mf.add_edge(xc + i, T, ys[i + 1] - ys[i]);
        }
        for (int i = 0; i < xc; i++)
        {
            for (int j = 0; j < yc; j++)
            {
                if (exi[i][j]) {
                    mf.add_edge(i, xc + yc + i * yc + j, M);
                    mf.add_edge(xc + yc + i * yc + j, xc + j, M);
                }
            }
        }
        Prt(mf.run(S, T));
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
    static readonly int[] dd = { 0, 1, 0, -1 };
    static readonly string dstring = "RDLU";
    public static P[] adjacents(this P p) => adjacents(p.v1, p.v2);
    public static P[] adjacents(this P p, int h, int w) => adjacents(p.v1, p.v2, h, w);
    public static pair<P, char>[] adjacents_with_str(int i, int j)
        => Enumerable.Range(0, dd.Length).Select(k => new pair<P, char>(new P(i + dd[k], j + dd[k ^ 1]), dstring[k])).ToArray();
    public static pair<P, char>[] adjacents_with_str(int i, int j, int h, int w)
        => Enumerable.Range(0, dd.Length).Select(k => new pair<P, char>(new P(i + dd[k], j + dd[k ^ 1]), dstring[k]))
                                         .Where(p => inside(p.v1.v1, p.v1.v2, h, w)).ToArray();
    public static P[] adjacents(int i, int j)
        => Enumerable.Range(0, dd.Length).Select(k => new P(i + dd[k], j + dd[k ^ 1])).ToArray();
    public static P[] adjacents(int i, int j, int h, int w)
        => Enumerable.Range(0, dd.Length).Select(k => new P(i + dd[k], j + dd[k ^ 1])).Where(p => inside(p.v1, p.v2, h, w)).ToArray();
    public static void Assert(bool cond) { if (!cond) throw new Exception(); }
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

class MinCostFlow {
    class edge {
        public int to, cap, rev;
        public long cost;
        public edge(int to, int cap, long cost, int rev) {
            this.to = to;
            this.cap = cap;
            this.cost = cost;
            this.rev = rev;
        }
    }
    const long LM = (long)1e18;
    int n;
    List<edge>[] g;

    public MinCostFlow(int n) {
        this.n = n;
        g = new List<edge>[n];
        for (int i = 0; i < n; i++)
        {
            g[i] = new List<edge>();
        }
    }
    public void addEdge(int from, int to, int cap, long cost) {
        g[from].Add(new edge(to, cap, cost, g[to].Count));
        g[to].Add(new edge(from, 0, -cost, g[from].Count));
    }
    public long run(int s, int t, int f) {
        long res = 0;
        var h = new long[n];
        while (f > 0) {
            var q = new PriorityQueue<pair<long, int>>(){ rev = true };
            var dist = new long[n];
            var prevv = new int[n];
            var preve = new int[n];
            for (int i = 0; i < n; i++) dist[i] = LM;
            dist[s] = 0;
            q.Push(new pair<long, int>(0, s));
            while (q.Count > 0) {
                var p = q.Pop();
                int v = p.v2;
                if (dist[v] < p.v1) continue;
                for (int i = 0; i < g[v].Count; ++i) {
                    var e = g[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        q.Push(new pair<long, int>(dist[e.to], e.to));
                    }
                }
            }
            if (dist[t] == LM) break;
            for (int v = 0; v < n; ++v) h[v] += dist[v];

            int d = f;
            for (int v = t; v != s; v = prevv[v]) d = Math.Min(d, g[prevv[v]][preve[v]].cap);

            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                var e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }
        return res;
    }
}

class MaxFlow // dinic
{
    public class edge {
        public int to;
        public long cap;
        public int rev;
        public edge(int t, long c, int r) { to = t; cap = c; rev = r; }
    }
    int V;
    List<edge>[] G;
    int[] itr, lev;
    public List<edge>[] getEdges() => G;

    public MaxFlow(int v) {
        V = v; G = new List<edge>[v];
        for (int i = 0; i < v; ++i) G[i] = new List<edge>();
    }
    public void add_edge(int frm, int to, long c) => add_edge(frm, to, c, true);
    public void add_edge(int frm, int to, long c, bool dir) {
        G[frm].Add(new edge(to, c, G[to].Count));
        G[to].Add(new edge(frm, dir ? 0 : c, G[frm].Count - 1));
    }
    void bfs(int s) {
        lev = new int[V];
        for (int i = 0; i < V; ++i) lev[i] = -1;
        var q = new Queue<int>();
        lev[s] = 0;
        q.Enqueue(s);
        while (q.Count > 0) {
            int v = q.Dequeue();
            foreach (var e in G[v]) {
                if (e.cap > 0 && lev[e.to] < 0) {
                    lev[e.to] = lev[v] + 1;
                    q.Enqueue(e.to);
                }
            }
        }
    }
    long dfs(int v, int t, long f) {
        if (v == t) return f;
        for (; itr[v] < G[v].Count; ++itr[v]) {
            var e = G[v][itr[v]];
            if (e.cap > 0 && lev[v] < lev[e.to]) {
                long d = dfs(e.to, t, f < e.cap ? f : e.cap);
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    public long run(int s, int t) {
        long ret = 0;
        bfs(s);
        while (lev[t] >= 0) {
            itr = new int[V];
            long f;
            while ((f = dfs(s, t, int.MaxValue)) > 0) ret += f;
            bfs(s);
        }
        return ret;
    }
}

// the greatest element pops
class PriorityQueue<T> where T : IComparable<T> {
    List<T> buf;
    public bool rev = false;
    public PriorityQueue() { buf = new List<T>(); }
    int cmp(int i, int j) => buf[i].CompareTo(buf[j]) * (rev ? -1 : 1);
    void swap(int i, int j) { var t = buf[i]; buf[i] = buf[j]; buf[j] = t; }
    public void Push(T elem) {
        int n = buf.Count;
        buf.Add(elem);
        while (n > 0) {
            int i = (n - 1) >> 1;
            if (cmp(n, i) > 0) swap(i, n);
            n = i;
        }
    }
    public T Pop() {
        T ret = buf[0];
        int n = buf.Count - 1;
        buf[0] = buf[n];
        buf.RemoveAt(n);
        for (int i = 0, j; (j = (i << 1) + 1) < n; i = j) {
            if (j != n - 1 && cmp(j, j + 1) < 0) ++j;
            if (cmp(i, j) < 0) swap(i, j);
        }
        return ret;
    }
    public T Top => buf[0];
    public int Count => buf.Count;
}

class PriorityQueue_rev_int {
    List<int> buf;
    public PriorityQueue_rev_int() { buf = new List<int>(); }
    // int cmp(int i, int j) => buf[i].CompareTo(buf[j]) * (rev ? -1 : 1);
    void swap(int i, int j) { var t = buf[i]; buf[i] = buf[j]; buf[j] = t; }
    public void Push(int elem) {
        int n = buf.Count;
        buf.Add(elem);
        while (n > 0) {
            int i = (n - 1) >> 1;
            if (buf[n] < buf[i]) swap(i, n);
            n = i;
        }
    }
    public int Pop() {
        int ret = buf[0];
        int n = buf.Count - 1;
        buf[0] = buf[n];
        buf.RemoveAt(n);
        for (int i = 0, j; (j = (i << 1) + 1) < n; i = j) {
            if (j != n - 1 && buf[j] > buf[j + 1]) ++j;
            if (buf[i] > buf[j]) swap(i, j);
        }
        return ret;
    }
    public int Top => buf[0];
    public int Count => buf.Count;
}