import java.io.*;
import java.util.*;

public class R369qC {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        
        int c[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            c[i] = in.nextInt();
        
        int p[][] = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                p[i][j] = in.nextInt();
        
        long inf = (long) 1e14;
        
        long dp[][][] = new long[n + 1][k + 1][m + 1];
        
        int min1[][] = new int[n + 1][k + 1];
        int min2[][] = new int[n + 1][k + 1];
        
        min1[0][0] = 0;
        min2[0][0] = 1;
        
        
        for (int i = 1; i <= k; i++) {
            Arrays.fill(dp[0][i], inf);
            min1[0][i] = min2[0][i] = -1;
        }
     
        for (int i = 1; i <= n; i++) {
            Arrays.fill(dp[i][0] , inf);
            min1[i][0] = min2[i][0] = -1;
            for (int j = 1; j <= k; j++) {
                min1[i][j] = min2[i][j] = -1;
                for (int pro = 1; pro <= m; pro++) {
                    if (c[i] == pro || c[i] == 0) {
                        int e = c[i] == pro ? 0 : p[i][pro];
                        dp[i][j][pro] = dp[i - 1][j][pro] + e;
                        if (min1[i - 1][j - 1] >= 0 && min1[i - 1][j - 1] != pro) {
                            dp[i][j][pro] = Math.min(dp[i][j][pro], dp[i - 1][j - 1][min1[i - 1][j - 1]] + e);
                        }
                        if (min2[i - 1][j - 1] >= 0 && min2[i - 1][j - 1] != pro) {
                            dp[i][j][pro] = Math.min(dp[i][j][pro], dp[i - 1][j - 1][min2[i - 1][j - 1]] + e);
                        }
                    }
                    else {
                        dp[i][j][pro] = inf;
                    }
                    if (min1[i][j] == -1 || dp[i][j][pro] <= dp[i][j][min1[i][j]]) {
                        min2[i][j] = min1[i][j];
                        min1[i][j] = pro;
                    }
                    else if (min2[i][j] == -1 || dp[i][j][pro] <= dp[i][j][min2[i][j]]) {
                        min2[i][j] = pro;
                    }
                }
            }
        }
        
        
        //System.out.println();
        //System.out.println(Arrays.toString(dp[n][k]));
        
        long ans = inf;
        for (int i = 1; i <= m; i++)
            ans = Math.min(ans, dp[n][k][i]);
        
        w.println(ans >= inf ? -1 : ans);
        w.close();
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

        public String nextLine() {
            int c = snext();
            while (isSpaceChar(c))
                c = snext();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
}