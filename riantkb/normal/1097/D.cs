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
        long n;
        int k;
        sc.Multi(out n, out k);
        var lis = new List<pair<long, int>>();
        long m = n;
        for (long i = 2; i * i <= m; i++)
        {
            int c = 0;
            while (m % i == 0) {
                m /= i;
                ++c;
            }
            if (c > 0) {
                lis.Add(make_pair(i, c));
            }
        }
        if (m > 1) {
            lis.Add(make_pair(m, 1));
        }
        long ans = 1;
        var inv = new long[100];
        for (int i = 1; i < 100; i++)
        {
            inv[i] = MyMath.inv(i);
        }
        foreach (var item in lis)
        {
            int c = item.v2;
            var dp = new long[c + 1];
            dp[0] = 1;
            for (int i = 0; i < k; i++)
            {
                var nex = new long[c + 1];
                for (int j = 0; j <= c; j++)
                {
                    for (int l = 0; l <= j; l++)
                    {
                        nex[j] = (nex[j] + dp[l] * inv[c - l + 1]) % M;
                    }
                }
                dp = nex;
            }
            long a = 0;
            long b = 1;
            for (int i = c; i >= 0; i--)
            {
                a = (a + dp[i] * b) % M;
                b = b * (item.v1 % M) % M;
            }
            ans = ans * a % M;
        }
        Prt(ans);
        sw.Flush();
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

static class MyMath
{
    public static long Mod = 1000000007;
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
    public static List<int> getprimes(int n) {
        var prs = new List<int>();
        var p = sieve(n);
        for (int i = 2; i <= n; i++) if (p[i]) prs.Add(i);
        return prs;
    }
    public static long pow(long a, long b) {
        a %= Mod;
        if (a == 0) return 0;
        if (b == 0) return 1;
        var t = pow(a, b / 2);
        if ((b & 1) == 0) return t * t % Mod;
        return t * t % Mod * a % Mod;
    }
    public static long inv(long a) => pow(a, Mod - 2);
    public static long gcd(long a, long b) {
        while (b > 0) { var t = a % b; a = b; b = t; } return a;
    }
    // a x + b y = gcd(a, b)
    public static long extgcd(long a, long b, out long x, out long y) {
        long g = a; x = 1; y = 0;
        if (b > 0) { g = extgcd(b, a % b, out y, out x); y -= a / b * x; }
        return g;
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
    public static bool nextPermutation<T>(IList<T> p) where T : struct, IComparable<T> {
        for (int i = p.Count - 2; i >= 0; --i) {
            if (p[i].CompareTo(p[i + 1]) < 0) {
                for (int j = p.Count - 1; ; --j) {
                    if (p[j].CompareTo(p[i]) > 0) {
                        p.swap(i, j);
                        for(++i, j = p.Count - 1; i < j; ++i, --j)
                            p.swap(i, j);

                        return true;
                    }
                }
            }
        }
        return false;
    }
    public static bool nextPermutation<T>(IList<T> p, Comparison<T> compare) where T : struct {
        for (int i = p.Count - 2; i >= 0; --i) {
            if (compare(p[i], p[i + 1]) < 0) {
                for (int j = p.Count - 1; ; --j) {
                    if (compare(p[j], p[i]) > 0) {
                        p.swap(i, j);
                        for (++i, j = p.Count - 1; i < j; ++i, --j)
                            p.swap(i, j);

                        return true;
                    }
                }
            }
        }
        return false;
    }
}