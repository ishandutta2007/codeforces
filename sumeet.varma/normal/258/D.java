import java.io.*;
import java.util.*;

public class R157qD {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        
        int p[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            p[i] = in.nextInt();
        
        double d[][] = new double[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                d[i][j] = p[i] > p[j] ? 1 : 0;
        
        for (int i = 1; i <= m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int x = Math.min(a, b);
            int y = Math.max(a, b);
            for (int j = 1; j < x; j++)
                d[j][x] = d[j][y] = 0.5 * (d[j][x] + d[j][y]);
            for (int j = y + 1; j <= n; j++)
                d[x][j] = d[y][j] = 0.5 * (d[x][j] + d[y][j]);
            for (int j = x + 1; j < y; j++) {
                double dxj = d[x][j], djy = d[j][y];
                d[x][j] = 0.5 * (dxj + (1 - djy));
                d[j][y]=  0.5 * (djy + (1 - dxj));
            }
            d[x][y] = 0.5 * (d[x][y] + (1 - d[x][y]));
        }
                
        double ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                ans += d[i][j];
        
        w.println(ans);
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