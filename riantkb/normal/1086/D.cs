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
        int n, q;
        sc.Multi(out n, out q);
        var s = sc.Str.ToCharArray();
        var bit_r = new BIT(n);
        var bit_s = new BIT(n);
        var bit_p = new BIT(n);
        int lr = n, ls = n, lp = n;
        int rr = -1, rs = -1, rp = -1;
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
                case 'R':
                    lr = Math.Min(lr, i);
                    rr = Math.Max(rr, i);
                    bit_r.add(i, 1);
                    break;
                case 'S':
                    ls = Math.Min(ls, i);
                    rs = Math.Max(rs, i);
                    bit_s.add(i, 1);
                    break;
                case 'P':
                    lp = Math.Min(lp, i);
                    rp = Math.Max(rp, i);
                    bit_p.add(i, 1);
                    break;
            }
        }
        Prt(calc(n, bit_r, ls, rs, lp, rp) + calc(n, bit_s, lp, rp, lr, rr) + calc(n, bit_p, lr, rr, ls, rs));
        for (int _ = 0; _ < q; _++)
        {
            int i;
            char c;
            sc.Multi(out i, out c);
            --i;
            char prev = s[i];
            if (prev == c) goto A;
            s[i] = c;
            switch (prev)
            {
                case 'R':
                    bit_r.add(i, -1);
                    if (lr == i)
                        lr = search_l(n, bit_r);
                    if (rr == i)
                        rr = search_r(n, bit_r);
                    break;
                case 'S':
                    bit_s.add(i, -1);
                    if (ls == i)
                        ls = search_l(n, bit_s);
                    if (rs == i)
                        rs = search_r(n, bit_s);
                    break;
                case 'P':
                    bit_p.add(i, -1);
                    if (lp == i)
                        lp = search_l(n, bit_p);
                    if (rp == i)
                        rp = search_r(n, bit_p);
                    break;
            }
            switch (c)
            {
                case 'R':
                    lr = Math.Min(lr, i);
                    rr = Math.Max(rr, i);
                    bit_r.add(i, 1);
                    break;
                case 'S':
                    ls = Math.Min(ls, i);
                    rs = Math.Max(rs, i);
                    bit_s.add(i, 1);
                    break;
                case 'P':
                    lp = Math.Min(lp, i);
                    rp = Math.Max(rp, i);
                    bit_p.add(i, 1);
                    break;
            }
            A:
            Prt(calc(n, bit_r, ls, rs, lp, rp) + calc(n, bit_s, lp, rp, lr, rr) + calc(n, bit_p, lr, rr, ls, rs));
        }
        sw.Flush();
    }
    static int search_l(int n, BIT bit) {
        int ok = 0, ng = n + 1;
        while (ok + 1 < ng) {
            int m = (ok + ng) / 2;
            if (bit.sum(m) == 0) {
                ok = m;
            }
            else
                ng = m;
        }
        return ok;
    }
    static int search_r(int n, BIT bit) {
        int all = bit.sum(n);
        if (all == 0) return -1;
        int ok = 0, ng = n;
        while (ok + 1 < ng) {
            int m = (ok + ng) / 2;
            if (bit.sum(m) == all) {
                ng = m;
            }
            else
                ok = m;
        }
        return ok;
    }
    static int calc(int n, BIT bit, int ls, int rs, int lp, int rp) {
        if (lp == n) {
            return bit.sum(n);
        }
        var lis = merge(new P(0, Math.Min(lp, rs)), new P(Math.Max(rp, ls), n), new P(ls, rs));
        int ret = 0;
        foreach (var item in lis)
        {
            ret += bit.sum(item.v1, item.v2);
        }
        return ret;
    }
    static List<P> merge(params P[] ps) {
        Array.Sort(ps);
        var ret = new List<P>();
        for (int i = 0; i < ps.Length; i++)
        {
            if (ps[i].v1 >= ps[i].v2) continue;
            if (ret.Count == 0) ret.Add(ps[i]);
            else if (ret[ret.Count - 1].v2 >= ps[i].v1) {
                ret[ret.Count - 1].v2 = Math.Max(ret[ret.Count - 1].v2, ps[i].v2);
            }
            else {
                ret.Add(ps[i]);
            }
        }
        return ret;
    }
    class BIT
    {
        int n;
        int[] bit;
        public BIT(int n) { this.n = n; bit = new int[n]; }
        public void add(int j, int w) { for (int i = j; i < n; i |= i + 1) bit[i] += w; }
        public int at(int j) => sum(j, j + 1);
        // [0, j)
        public int sum(int j) {
            int ret = 0;
            for (int i = j - 1; i >= 0; i = (i & i + 1) - 1) ret += bit[i];
            return ret;
        }
        // [j, k)
        public int sum(int j, int k) => sum(k) - sum(j);
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