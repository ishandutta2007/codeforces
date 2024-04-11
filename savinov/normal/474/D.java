import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static boolean home = true;

    public static void main(String[] args) throws FileNotFoundException {
        InputStream is = home ? System.in : new FileInputStream("decoding.in");
        InputReader in = new InputReader(is);

        OutputStream os = home ? System.out : new FileOutputStream("decoding.out");
        PrintWriter out = new PrintWriter(os);

        int n = in.nextInt();

        int k = in.nextInt();

        long mod = 1000000007;

        int N = 100000;

        long [][] dp = new long[N + 1][2];
        long [] sum = new long[N + 1];
        sum[0] = 1;

        dp[0][1] = 1;

        for (int i = 1; i <= N; ++i) {
            dp[i][0] = i >= k ? (dp[i - k][1] + dp[i - k][0]) : 0;
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] %= mod;
            dp[i][1] %= mod;
            //System.err.println(i + " " + dp[i][0] + " " + dp[i][1]);
            sum[i] = (sum[i - 1] + dp[i][0] + dp[i][1]) % mod;
        }

        while (n-- > 0) {
            int a = in.nextInt();
            int b = in.nextInt();
            out.println((sum[b] - sum[a - 1] + mod) % mod);
        }

        out.close();
    }

    private static int gcd(int a, int b) {
        while (b > 0) {
            a %= b;
            a ^= b;
            b ^= a;
            a ^= b;
        }
        return a;
    }

}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}