import java.io.*;
import java.util.*;

public class R114qB {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int l = in.nextInt();
        int k = in.nextInt();

        int p[] = in.nextIntArray(n);
        int a[] = in.nextIntArray(n);

        double dp[][][] = new double[n + 1][l + 1][2 * n + 1];
        int B = n;
        for (int i = B; i <= B + n; i++)
            dp[n][0][i] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = l; j >= 0; j--) {
                for (int x = 2 * n; x >= 0; x--) {
                    dp[i][j][x] += (100 - p[i]) * dp[i + 1][j][x] / 100;
                    if (a[i] == -1)
                        dp[i][j][x] += p[i] * dp[i + 1][Math.max(j - 1, 0)][Math.max(0, x - 1)] / 100;
                    else
                        dp[i][j][x] += p[i] * dp[i + 1][Math.max(j - 1, 0)][Math.min(x + a[i], B + n)] / 100;
                }
            }
        }

        w.println(dp[0][l][B + Math.min(n, k)]);
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