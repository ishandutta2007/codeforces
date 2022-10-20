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
        int n, k;
        sc.Multi(out n, out k);
        long ans = 0;
        MyMath.setfacts(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int c = n / i;
            if (c >= k) {
                ans += MyMath.comb(c - 1, k - 1);
            }
            else break;
        }
        Prt(ans % M);
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
    // public static readonly int M = 1000000007;
    public static readonly int M = 998244353;
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

static class MyMath {
    public static long Mod = util.M;
    // public static long Mod = 1000000007;
    public static bool isprime(long a) {
        if (a < 2) return false;
        for (long i = 2; i * i <= a; i++) if (a % i == 0) return false;
        return true;
    }
    public static bool[] sieve(int n) {
        var p = new bool[n + 1];
        for (int i = 2; i <= n; i++) p[i] = true;
        for (int i = 2; i * i <= n; i++) if (p[i]) for (int j = i * i; j <= n; j += i) p[j] = false;
        return p;
    }
    public static int[] sieve2(int n) {
        var p = new int[n + 1];
        for (int i = 2; i <= n; i++) p[i] = i;
        for (int i = 2; i * i <= n; i++) {
            if (p[i] == i)
                for (int j = i * i; j <= n; j += i)
                    p[j] = Math.Min(p[j], i);
        }
        return p;
    }
    public static bool[] segmentSieve(long l, long r) {
        int sqn = (int)Math.Sqrt(r + 9);
        var ps = getprimes(sqn);
        return segmentSieve(l, r,ps);
    }
    public static bool[] segmentSieve(long l, long r, List<int> ps) {
        var sieve = new bool[r - l + 1];
        for (long i = l; i <= r; i++) sieve[i - l] = true;
        foreach (long p in ps) {
            if (p * p > r) break;
            for (long i = p >= l ? p * p : (l + p - 1) / p * p; i <= r; i += p) sieve[i - l] = false;
        }
        return sieve;
    }
    public static List<int> getprimes(int n) {
        var prs = new List<int>();
        var p = sieve(n);
        for (int i = 2; i <= n; i++) if (p[i]) prs.Add(i);
        return prs;
    }
    public static long pow(long a, long b, long mod) {
        a %= mod;
        if (b < 0) Console.Error.WriteLine($"power number is negative ({a}^{b}).");
        if (b <= 0) return 1;
        var t = pow(a, b / 2, mod);
        if ((b & 1) == 0) return t * t % mod;
        return t * t % mod * a % mod;
    }
    public static long pow(long a, long b) => pow(a, b, Mod);
    public static long inv(long a) => pow(a, Mod - 2);
    public static long gcd(long a, long b) {
        while (b > 0) {
            var t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    // a x + b y = gcd(a, b)
    public static long extgcd(long a, long b, out long x, out long y) {
        long g = a; x = 1; y = 0;
        if (b > 0) { g = extgcd(b, a % b, out y, out x); y -= a / b * x; }
        return g;
    }

    // return (r, m): x = r (mod. m)
    // return (0, -1) if no answer
    public static pair<long, long> chineserem(IList<long> b, IList<long> m) {
        long r = 0, M = 1;
        for (int i = 0; i < b.Count; ++i) {
            long p, q;
            long d = extgcd(M, m[i], out p, out q); // p is inv of M/d (mod. m[i]/d)
            if ((b[i] - r) % d != 0) return new pair<long, long>(0, -1);
            long tmp = (b[i] - r) / d * p % (m[i]/d);
            r += M * tmp;
            M *= m[i]/d;
        }
        return new pair<long, long>((r % M + M) % M, M);
    }

    // return k: x^k = y (mod. mod) O(sqrt(mod))
    public static long modlog(long x, long y, long mod) {
        if (y == 1) return 0;
        long H = (long)Math.Sqrt(mod) + 1;
        var baby = new Dictionary<long, long>();
        for (long b = 0, xby = y; b < H; b++, xby = (xby * x) % mod) {
            if (!baby.ContainsKey(xby))
                baby.Add(xby, b);
            else
                baby[xby] = b;
        }

        long xH = 1;
        for (int i = 0; i < H; ++i) xH = xH * x % mod;
        for (long a = 1, xaH = xH; a <= H; a++, xaH = (xaH * xH) % mod)
            if (baby.ContainsKey(xaH))
                return a * H - baby[xaH];

        return -1;
    }
    public static long lcm(long a, long b) => a / gcd(a, b) * b;

    static long[] facts, invs;
    public static void setfacts(int n) {
        facts = new long[n + 1];
        facts[0] = 1;
        for (int i = 1; i <= n; i++) facts[i] = facts[i - 1] * i % Mod;
        invs = new long[n + 1];
        invs[n] = inv(facts[n]);
        for (int i = n; i > 0 ; i--) invs[i - 1] = invs[i] * i % Mod;
    }
    public static long fact(long n) {
        if (n < 0) return 0;
        if (facts != null && facts.Length > n) return facts[n];
        long numer = 1;
        for (long i = 1; i <= n; i++) numer = numer * (i % Mod) % Mod;
        return numer;
    }
    public static long perm(long n, long r) {
        if (n < 0 || r < 0 || r > n) return 0;
        if (facts != null && facts.Length > n) return facts[n] * invs[n - r] % Mod;
        long numer = 1;
        for (long i = 0; i < r; i++) numer = numer * ((n - i) % Mod) % Mod;
        return numer;
    }
    public static long comb(long n, long r) {
        if (n < 0 || r < 0 || r > n) return 0;
        if (facts != null && facts.Length > n) return facts[n] * invs[r] % Mod * invs[n - r] % Mod;
        if (n - r < r) r = n - r;
        long numer = 1, denom = 1;
        for (long i = 0; i < r; i++) {
            numer = numer * ((n - i) % Mod) % Mod;
            denom = denom * ((i + 1) % Mod) % Mod;
        }
        return numer * inv(denom) % Mod;
    }
    public static long multi_choose(long n, long r) => comb(n + r - 1, r);
    public static long[][] getcombs(int n) {
        var ret = new long[n + 1][];
        for (int i = 0; i <= n; i++) {
            ret[i] = new long[i + 1];
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; j++) ret[i][j] = (ret[i - 1][j - 1] + ret[i - 1][j]) % Mod;
        }
        return ret;
    }
    // nC0, nC2, ..., nCn
    public static long[] getcomb(int n) {
        var ret = new long[n + 1];
        ret[0] = 1;
        for (int i = 0; i < n; i++) ret[i + 1] = ret[i] * (n - i) % Mod * inv(i + 1) % Mod;
        return ret;
    }

    public static class ModMatrix {
        public static long[][] E(int n) {
            var ret = new long[n][];
            for (int i = 0; i < n; i++) { ret[i] = new long[n]; ret[i][i] = 1; }
            return ret;
        }
        public static long[][] pow(long[][] A, long n) {
            if (n == 0) return E(A.Length);
            var t = pow(A, n / 2);
            if ((n & 1) == 0) return mul(t, t);
            return mul(mul(t, t), A);
        }
        public static long dot(long[] x, long[] y) {
            int n = x.Length;
            long ret = 0;
            for (int i = 0; i < n; i++) ret = (ret + x[i] * y[i]) % Mod;
            return ret;
        }
        public static long[][] trans(long[][] A) {
            int n = A[0].Length, m = A.Length;
            var ret = new long[n][];
            for (int i = 0; i < n; i++) { ret[i] = new long[m]; for (int j = 0; j < m; j++) ret[i][j] = A[j][i]; }
            return ret;
        }
        public static long[] mul(long a, long[] x) {
            int n = x.Length;
            var ret = new long[n];
            for (int i = 0; i < n; i++) ret[i] = a * x[i] % Mod;
            return ret;
        }
        public static long[] mul(long[][] A, long[] x) {
            int n = A.Length;
            var ret = new long[n];
            for (int i = 0; i < n; i++) ret[i] = dot(x, A[i]);
            return ret;
        }
        public static long[][] mul(long a, long[][] A) {
            int n = A.Length;
            var ret = new long[n][];
            for (int i = 0; i < n; i++) ret[i] = mul(a, A[i]);
            return ret;
        }
        public static long[][] mul(long[][] A, long[][] B) {
            int n = A.Length;
            var Bt = trans(B);
            var ret = new long[n][];
            for (int i = 0; i < n; i++) ret[i] = mul(Bt, A[i]);
            return ret;
        }
    }
}