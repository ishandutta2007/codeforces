using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Numerics;
using System.Threading;

partial class Program
{
    int[] dx = new int[] { 1, 0, -1, 0, 1, -1, -1, 1 };
    int[] dy = new int[] { 0, 1, 0, -1, 1, 1, -1, -1 };
    long mod = 1000000007;
    IO io = new IO();
    static void Main()
    {
        Console.SetIn(new StreamReader(Console.OpenStandardInput(8192)));
        Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
        var program = new Program();
        //var t = new Thread(program.Solve, 134217728);
        //t.Start();
        //t.Join();
        program.Solve();
        Console.Out.Flush();
        Console.Read();
    }

    public void Solve()
    {
        var T = io.GetInt();
        for (int i = 0; i < T; i++) SubSolve();
    }

    public void SubSolve()
    {
        var (N, Q) = io.GetMulti<int, long>();
        var A = io.GetLongArray();
        var X = io.GetLongArray();
        var cum = new long[N];
        var max = new long[N];
        cum[0] = A[0];
        max[0] = A[0];
        for (int i = 1; i < N; i++)
        {
            cum[i] = cum[i - 1] + A[i];
            max[i] = Math.Max(max[i - 1], cum[i]);
        }
        var ans = new long[Q];
        for (int i = 0; i < Q; i++)
        {
            var x = X[i];
            if (max[^1] < x && cum[^1] <= 0)
            {
                ans[i] = -1;
                continue;
            }
            var k = cum[^1] <= 0 ? 0 : Math.Max((x - max[^1] + cum[^1] - 1) / cum[^1], 0);
            var key = x - k * cum[^1];
            var ok = N - 1;
            var ng = -1;
            while (Math.Abs(ok - ng) > 1)
            {
                var mid = (ok + ng) / 2;
                if (max[mid] >= key) ok = mid;
                else ng = mid;
            }
            ans[i] = k * N + ok;
        }
        io.Print(" ", ans);
    }



}




//------------------------------------------------------------------------------------------------------------------

public static class Ex
{
    public static bool IsNullOrEmpty(this string s) { return string.IsNullOrEmpty(s); }
    public static void yesno(this bool b) => Console.WriteLine(b ? "yes" : "no");
    public static void YesNo(this bool b) => Console.WriteLine(b ? "Yes" : "No");
    public static void YESNO(this bool b) => Console.WriteLine(b ? "YES" : "NO");
    public static void Yes() => Console.WriteLine("Yes");
    public static void YES() => Console.WriteLine("YES");
    public static void No() => Console.WriteLine("No");
    public static void NO() => Console.WriteLine("NO");
    public static void M1() => Console.WriteLine("-1");
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static bool Chmax(ref this int a, int b)
    {
        if (a < b) { a = b; return true; }
        else return false;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static bool Chmin(ref this int a, int b)
    {
        if (a > b) { a = b; return true; }
        else return false;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static bool Chmax(ref this long a, long b)
    {
        if (a < b) { a = b; return true; }
        else return false;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static bool Chmin<T>(ref this long a, long b)
    {
        if (a > b) { a = b; return true; }
        else return false;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static bool Chmax<T>(ref this T a, T b) where T : struct, IComparable<T>
    {
        if (b.CompareTo(a) > 0) { a = b; return true; }
        else return false;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static bool Chmin<T>(ref this T a, T b) where T : struct, IComparable<T>
    {
        if (b.CompareTo(a) < 0) { a = b; return true; }
        else return false;
    }

    /// <summary>
    /// constraint
    /// </summary>
    /// <param name="constraint">T key </param>
    /// <returns>(0-indexed)</returns>
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static int LowerBound<T>(this IList<T> ls, Func<T, bool> constraint)
    {
        var ng = -1;
        var ok = ls.Count;
        while (ok - ng > 1)
        {
            var mid = (ok + ng) / 2;
            if (constraint(ls[mid])) ok = mid;
            else ng = mid;
        }
        return ok;

    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="fromLeft"></param>
    /// <param name="gen"></param>
    /// <param name="func"></param>
    /// <returns>N+1</returns>
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static T[] GetCum<T>(this IList<T> ls, bool fromLeft, T gen, Func<T, T, T> func)
    {
        var res = new T[ls.Count + 1];
        res.AsSpan().Fill(gen);
        if (fromLeft)
        {
            for (int i = 0; i < ls.Count; i++) res[i + 1] = func(res[i], ls[i]);
        }
        else
        {
            for (int i = ls.Count; i > 0; i--) res[i - 1] = func(res[i], ls[i - 1]);
        }
        return res;
    }

    /// <summary>
    /// IList
    /// </summary>
    /// <param name="ls"></param>
    /// <returns></returns>
    public static string[] StringListFastSort(this IList<string> ls)
    {
        var res = ls.ToArray();
        Array.Sort(res, StringComparer.OrdinalIgnoreCase);
        return res;
    }

    /// <summary>
    /// 
    /// </summary>
    public static int PopCount(this uint bits)
    {
        bits = bits - ((bits >> 1) & 0x55555555);
        bits = (bits & 0x33333333) + ((bits >> 2) & 0x33333333);
        return (int)(((bits + (bits >> 4) & 0xF0F0F0F) * 0x1010101) >> 24);
    }

    /// <summary>
    /// element
    /// </summary>
    public static T[] Repeat<T>(this T element, int N)
    {
        var res = new T[N];
        res.AsSpan().Fill(element);
        return res;
    }

    /// <summary>
    /// element
    /// </summary>
    public static T[][] Repeat<T>(this T element, int H, int W)
    {
        var res = new T[H][];
        for (int i = 0; i < H; i++)
        {
            res[i] = new T[W];
            res[i].AsSpan().Fill(element);
        }
        return res;
    }

    /// <summary>
    /// element
    /// </summary>
    public static T[][][] Repeat<T>(this T element, int H, int W, int R)
    {
        var res = new T[H][][];
        for (int i = 0; i < H; i++)
        {
            res[i] = new T[W][];
            for (int j = 0; j < W; j++)
            {
                res[i][j] = new T[R];
                res[i][j].AsSpan().Fill(element);
            }
        }
        return res;
    }

}

class IO
{
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public string GetStr() => Console.ReadLine().Trim();
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public char GetChar() => Console.ReadLine().Trim()[0];
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public int GetInt() => int.Parse(Console.ReadLine().Trim());
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public long GetLong() => long.Parse(Console.ReadLine().Trim());
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public double GetDouble() => double.Parse(Console.ReadLine().Trim());
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public decimal GetDecimal() => decimal.Parse(Console.ReadLine().Trim());
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public string[] GetStrArray() => Console.ReadLine().Trim().Split(' ');
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public string[][] GetStrArray(int N)
    {
        var res = new string[N][];
        for (int i = 0; i < N; i++) res[i] = Console.ReadLine().Trim().Split(' ');
        return res;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public int[] GetIntArray() => Console.ReadLine().Trim().Split(' ').Select(int.Parse).ToArray();
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public int[][] GetIntArray(int N)
    {
        var res = new int[N][];
        for (int i = 0; i < N; i++) res[i] = Console.ReadLine().Trim().Split(' ').Select(int.Parse).ToArray();
        return res;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public long[] GetLongArray() => Console.ReadLine().Trim().Split(' ').Select(long.Parse).ToArray();
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public long[][] GetLongArray(int N)
    {
        var res = new long[N][];
        for (int i = 0; i < N; i++) res[i] = Console.ReadLine().Trim().Split(' ').Select(long.Parse).ToArray();
        return res;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public decimal[] GetDecimalArray() => Console.ReadLine().Trim().Split(' ').Select(decimal.Parse).ToArray();
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public decimal[][] GetDecimalArray(int N)
    {
        var res = new decimal[N][];
        for (int i = 0; i < N; i++) res[i] = Console.ReadLine().Trim().Split(' ').Select(decimal.Parse).ToArray();
        return res;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public char[] GetCharArray() => Console.ReadLine().Trim().Split(' ').Select(char.Parse).ToArray();
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public double[] GetDoubleArray() => Console.ReadLine().Trim().Split(' ').Select(double.Parse).ToArray();
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public double[][] GetDoubleArray(int N)
    {
        var res = new double[N][];
        for (int i = 0; i < N; i++) res[i] = Console.ReadLine().Trim().Split(' ').Select(double.Parse).ToArray();
        return res;
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public char[][] GetGrid(int H)
    {
        var res = new char[H][];
        for (int i = 0; i < H; i++) res[i] = Console.ReadLine().Trim().ToCharArray();
        return res;
    }

    public List<int>[] GetUnweightedAdjanceyList(int V, int E, bool isDirected, bool isNode_0indexed)
    {
        var ls = new List<int>[V];
        for (int i = 0; i < V; i++) ls[i] = new List<int>();
        for (int i = 0; i < E; i++)
        {
            var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            if (isNode_0indexed == false) { input[0]--; input[1]--; }
            ls[input[0]].Add(input[1]);
            if (isDirected == false) ls[input[1]].Add(input[0]);
        }
        return ls;
    }

    public Dictionary<int, List<int>> GetUnweightedAdjacencyDict(int V, int E, bool isDirected, bool isNode_0indexed)
    {
        var dic = new Dictionary<int, List<int>>();
        foreach (var e in Enumerable.Range(0, V)) { dic.Add(e, new List<int>()); }
        for (int i = 0; i < E; i++)
        {
            var input = GetIntArray();
            var a = isNode_0indexed ? input[0] : input[0] - 1;
            var b = isNode_0indexed ? input[1] : input[1] - 1;
            dic[a].Add(b);
            if (isDirected == false) dic[b].Add(a);
        }
        return dic;
    }

    public List<(int to, long dist)>[] GetWeightedAdjacencyList(int V, int E, bool isDirected, bool isNode_0indexed)
    {
        var ls = new List<(int to, long dist)>[V];
        for (int i = 0; i < V; i++) ls[i] = new List<(int to, long dist)>();
        for (int i = 0; i < E; i++)
        {
            var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            if (isNode_0indexed == false) { input[0]--; input[1]--; }
            ls[input[0]].Add((input[1], input[2]));
            if (isDirected == false) ls[input[1]].Add((input[0], input[2]));
        }
        return ls;
    }

    public Dictionary<int, List<(int node, long cost)>> GetWeightedAdjacencyDict(int N, int M, bool isDirected, bool isNode_0indexed)
    {
        var dic = new Dictionary<int, List<(int, long)>>();
        foreach (var e in Enumerable.Range(0, N)) { dic.Add(e, new List<(int, long)>()); }
        for (int i = 0; i < M; i++)
        {
            var input = GetIntArray();
            var a = isNode_0indexed ? input[0] : input[0] - 1;
            var b = isNode_0indexed ? input[1] : input[1] - 1;
            var c = input[2];
            dic[a].Add((b, c));
            if (isDirected == false) dic[b].Add((a, c));
        }
        return dic;
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    bool eq<T, U>() => typeof(T).Equals(typeof(U));
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    T ct<T, U>(U a) => (T)Convert.ChangeType(a, typeof(T));
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    T cv<T>(string s) => eq<T, int>() ? ct<T, int>(int.Parse(s))
                       : eq<T, long>() ? ct<T, long>(long.Parse(s))
                       : eq<T, double>() ? ct<T, double>(double.Parse(s))
                       : eq<T, decimal>() ? ct<T, decimal>(decimal.Parse(s))
                       : eq<T, char>() ? ct<T, char>(s[0])
                       : ct<T, string>(s);
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    void Multi<T>(out T a) => a = cv<T>(GetStr());
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    void Multi<T, U>(out T a, out U b)
    {
        var ar = GetStrArray(); a = cv<T>(ar[0]); b = cv<U>(ar[1]);
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    void Multi<T, U, V>(out T a, out U b, out V c)
    {
        var ar = GetStrArray(); a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]);
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    void Multi<T, U, V, W>(out T a, out U b, out V c, out W d)
    {
        var ar = GetStrArray(); a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]);
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    void Multi<T, U, V, W, X>(out T a, out U b, out V c, out W d, out X e)
    {
        var ar = GetStrArray(); a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]);
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    void Multi<T, U, V, W, X, Y>(out T a, out U b, out V c, out W d, out X e, out Y f)
    {
        var ar = GetStrArray(); a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]); f = cv<Y>(ar[5]);
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public (T, U) GetMulti<T, U>()
    {
        var ar = Console.ReadLine().Split(' ');
        return (cv<T>(ar[0]), cv<U>(ar[1]));
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public (T, U, V) GetMulti<T, U, V>()
    {
        var ar = Console.ReadLine().Split(' ');
        return (cv<T>(ar[0]), cv<U>(ar[1]), cv<V>(ar[2]));
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public (T, U, V, W) GetMulti<T, U, V, W>()
    {
        var ar = Console.ReadLine().Split(' ');
        return (cv<T>(ar[0]), cv<U>(ar[1]), cv<V>(ar[2]), cv<W>(ar[3]));
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public (T, U, V, W, X) GetMulti<T, U, V, W, X>()
    {
        var ar = Console.ReadLine().Split(' ');
        return (cv<T>(ar[0]), cv<U>(ar[1]), cv<V>(ar[2]), cv<W>(ar[3]), cv<X>(ar[4]));
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public (T, U, V, W, X, Y) GetMulti<T, U, V, W, X, Y>()
    {
        var ar = Console.ReadLine().Split(' ');
        return (cv<T>(ar[0]), cv<U>(ar[1]), cv<V>(ar[2]), cv<W>(ar[3]), cv<X>(ar[4]), cv<Y>(ar[5]));
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public void Print() => Console.WriteLine();
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public void Print<T>(T t) => Console.WriteLine(t);
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public void Print<T>(string separator, IList<T> ls) => Console.WriteLine(string.Join(separator, ls));
    public void Debug<T>(IList<T> ls)
    {
        Console.Error.WriteLine();
        Console.Error.WriteLine("[" + string.Join(",", ls) + "]");
    }
    public void Debug<T>(IList<IList<T>> ls)
    {
        Console.Error.WriteLine();
        foreach (var l in ls)
        {
            Console.Error.WriteLine("[" + string.Join(",", l) + "]");
        }
        Console.Error.WriteLine();
    }
}