using System;
using System.Linq;

public static class Program
{
    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static void Main()
    {
        var nn = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int n = nn[0];
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int mn = a[0];
        for (int i = 0; i < n; i++) if (a[i] < mn) mn = a[i];
        for (int i = 0; i < n; i++) a[i] -= mn;
        int mx = 0;
        for (int i = 0; i < n; i++) if (a[i] > mx) mx = a[i];
        int g = 0;
        for (int i = 0; i < n; i++) g = gcd(g, a[i]);
        int ans = mx / g - n + 1;
        Console.WriteLine(ans.ToString());
    }
}