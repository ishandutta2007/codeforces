import java.io.*;
import java.util.*;

public class R157qB {
    
    static final int mod = (int)1e9 + 7;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int m = in.nextInt();
        char s[] = Integer.toString(m).toCharArray();
        int n = s.length;

        int cnt[][][] = new int[n + 1][n + 1][2];
        cnt[n][0][0] = cnt[n][0][1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                for (int k = 0; k < 2; k++) {
                    if (k == 0) {
                        for (int z = 0; z < s[i] - '0'; z++) {
                            if (j - x(z) >= 0)
                                cnt[i][j][0] += cnt[i + 1][j - x(z)][1];
                          //  System.out.println();
                        }
                        if (j - x(s[i] - '0') >= 0)
                            cnt[i][j][0] += cnt[i + 1][j - x(s[i] - '0')][0];
                    } else {
                        for (int z = 0; z <= 9; z++) {
                            if (j - x(z) >= 0)
                                cnt[i][j][1] += cnt[i + 1][j - x(z)][1];
                        }
                    }
                }
            }
        }

        int dp[] = new int[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = cnt[0][i][0];

        dp[0]--;

        //System.out.println(Arrays.toString(dp));
        
        long ans = 0;
        final int mod = (int) 1e9 + 7;

        long dp2[][][] = new long[n + 1][7 * n + 1][7];
        dp2[n][0][0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int sum = 7 * n; sum >= 0; sum--) {
                for (int freq = 6; freq >= 0; freq--) {
                    for (int take = 0; take <= freq && take * i <= sum && take <= dp[i]; take++) {
                        dp2[i][sum][freq] += count (dp[i], take) * dp2[i + 1][sum - take * i][freq - take];
                        dp2[i][sum][freq] %= mod;
                    }
                }
            }
        }
        
        for (int sum = 0; sum <= 7 * n; sum++) {
            for (int osum = sum + 1; osum <= n; osum++) {
                //System.out.println(dp2[0][sum][6] + " " + dp[osum]);
                ans += ((dp2[0][sum][6] * dp[osum]) % mod) * 720;
                ans %= mod;
            }
        }
        
        w.println(ans);
        w.close();
    }
    
    static long count(int n, int r) {
        if (r > n)
            return 0;
        long ans = 1;
        for (int i = n; i > n - r; i--)
            ans = (ans * i) % mod;
        for (int i = r; i >= 2; i--)
            ans = (ans * pow(i, mod - 2)) % mod;
        return ans;
    }
    
    static long pow(long a, int b) {
        if (b == 0)
            return 1;
        long ans = pow(a, b / 2);
        ans = (ans * ans) % mod;
        if (b % 2 == 1)
            ans = (ans * a) % mod;
        return ans;
    }

    static int[] brute(int m) {
        int n = Integer.toString(m).length();
        int dp[] = new int[n + 1];
        for (int i = 1; i <= m; i++) {
            char s[] = Integer.toString(i).toCharArray();
            int c = 0;
            for (char x : s)
                c += x(x - '0');
            dp[c]++;
        }
        return dp;
    }
    
    static int x(int v) {
        return (v == 4 || v == 7) ? 1 : 0;
    }

    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int snext() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public String readString() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
}