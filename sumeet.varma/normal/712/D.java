import java.io.*;
import java.util.*;

public class R370qD {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        final int mod = (int)1e9 + 7;
        int a = in.nextInt();
        int b = in.nextInt();
        int k = in.nextInt();
        int t = in.nextInt();
        
        int M = a + b + 2 * k * t;
        
        int dp[][] = new int[t + 1][2 * M + 1];
        int pre[][] = new int[t + 1][2 * M + 1];
        
        for (int i = 1; i <= M; i++) {
            dp[t][i + M] = 1;
            pre[t][i + M] = dp[t][i + M] + pre[t][i + M - 1];
        }
        
        for (int i = t - 1; i >= 0; i--) {
            
            int lDiffPrev = -1, rDiffPrev = -1;
            long now = 0;
            
            for (int d = -M; d <= +M; d++) {
                int lDiff = Math.max(-M - d, -2 * k);
                int rDiff = Math.min(2 * k, M - d);
                //System.out.println(d + " " + lDiff + " " + rDiff);
                
                if (d == -M) {
                    for (int diff = lDiff; diff <= rDiff; diff++) {
                        long oth = dp[i + 1][d + diff + M];
                        oth *= 2 * k + 1 - Math.abs(diff);
                        now += oth;
                        now %= mod;
                    }
                    dp[i][d + M] = (int)now;
                    pre[i][d + M] = (int)now;
                }
                
                else {
                    
                    //System.out.println(d + " " + M + " " + lDiffPrev);
                    long left = pre[i + 1][d - 1 + M];
                    if (d - 1 + M + lDiffPrev > 0)
                        left -= pre[i + 1][d - 1 + M + lDiffPrev - 1];
                    if (left < 0)
                        left += mod;
                    
                    now -= left;
                    if (now < 0)
                        now += mod;
                    
                    //System.out.println("d " + (d - 1 + M) + " " + (d - 1 + M + rDiffPrev));
                    int x = Math.min(2 * M, d - 1 + M + rDiffPrev + 1);
                    long right = pre[i + 1][x];
                    //System.out.println("d " + (d - 1 + M) + " " + (d - 1 + M + rDiffPrev));
                    right -= pre[i + 1][d - 1 + M];
                    if (right < 0)
                        right += mod;
                    
                    now += right;
                    if (now >= mod)
                        now -= mod;
                    
                    dp[i][d + M] = (int)now;
                    
                    pre[i][d + M] = pre[i][d + M - 1] + dp[i][d + M];
                    if (pre[i][d + M] >= mod)
                        pre[i][d + M] -= mod;
                }
                
                //System.out.println(d + " " + dp[i][d + M]);
                lDiffPrev = lDiff;
                rDiffPrev = rDiff;
                
                /*for (int diff = -2 * k; diff <= 2 * k; diff++) {
                    if (d + diff >= -M && d + diff <= M) {
                        long oth = dp[i + 1][d + diff + M];
                        oth *= 2 * k + 1 - Math.abs(diff);
                        oth %= mod;
                        dp[i][d + M] += oth;
                        if (dp[i][d + M] >= mod)
                            dp[i][d + M] -= mod;
                    }
                }*/
            }
        }
        
        w.println(dp[0][M + a - b]);
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