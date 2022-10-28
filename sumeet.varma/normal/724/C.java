import java.io.*;
import java.util.*;

public class IntelqC {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        long inf = Long.MAX_VALUE / 2;

        int M = (int) 5e5;
        long upRight[] = new long[2 * M];
        long upLeft[] = new long[2 * M];

        Arrays.fill(upRight, inf);
        Arrays.fill(upLeft, inf);

        int x = 0, y = 0;
        int dx = +1, dy = +1;
        long time = 0;

        while (true) {
            long maxSteps = inf;
            if (dx == +1) {
                maxSteps = Math.min(maxSteps, n - x);
            } else {
                maxSteps = Math.min(maxSteps, x);
            }
            if (dy == +1) {
                maxSteps = Math.min(maxSteps, m - y);
            } else {
                maxSteps = Math.min(maxSteps, y);
            }
            if (dx == dy) {
                upRight[x - y + M] = dx * time;
            } else {
                upLeft[x + y + M] = dx * time;
            }
            x += dx * maxSteps;
            y += dy * maxSteps;
            time += maxSteps;
            if ((x == 0 || x == n) && (y == 0 || y == m))
                break;
            if (x == 0)
                dx = +1;
            if (x == n)
                dx = -1;
            if (y == 0)
                dy = +1;
            if (y == m)
                dy = -1;
        }

        int k = in.nextInt();

        while (k-- > 0) {
            int a = in.nextInt();
            int b = in.nextInt();
            long ans = inf;

            if (upRight[a - b + M] >= 0) {
                ans = Math.min(ans, upRight[a - b + M] + Math.min(a, b));
            } else {
                ans = Math.min(ans, -upRight[a - b + M] + Math.min(n - a, m - b));
            }

            if (upLeft[a + b + M] < 0) {
                ans = Math.min(ans, -upLeft[a + b + M] + Math.min(n - a, b));
            } else {
                ans = Math.min(ans, upLeft[a + b + M] + Math.min(a, m - b));
            }

            w.println(ans == inf ? -1 : ans);
        }

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