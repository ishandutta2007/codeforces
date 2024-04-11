
import java.io.*;
import java.util.*;
import java.util.Arrays;

public class main
{
    static long mod = 1000000007;
    static long f[];

    static long pw(long a, long n)
    {
        long res = 1;
        while(n != 0)
        {
            if ((n & 1) == 1)
               res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }

    static long inv(long a)
    {
        return pw(a, mod - 2);
    }

    static long bin(int n, int k)
    {
        return f[n] * inv(f[k]) % mod * inv(f[n - k]) % mod;
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int a = in.nextInt();
        int b = in.nextInt();

        int n = in.nextInt();
        f = new long[n + 1];
        f[0] = 1;
        for(int i = 1; i <= n; ++i)
            f[i] = i * f[i - 1] % mod;
        boolean good[] = new boolean[n * 10];
        for(int i = 1; i < 10 * n; ++i)
        {
            good[i] = true;
            int cur = i;
            while(cur != 0)
            {
                int d = cur % 10;
                if (d != a && d != b)
                {
                    good[i] = false;
                    break;
                }
                cur /= 10;
            }
        }
        long ans = 0;
        for(int i = 0; i <= n; ++i)
        {
            if (good[a * i + b * (n - i)])
                ans = (ans + bin(n, i)) % mod;
        }
        out.println(ans);

        out.flush();

    }

}