import java.io.*;
import java.util.*;

public class R365qB {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = in.nextInt();
        int k = in.nextInt();
        int c[] = in.nextIntArray(n);
        int d[] = in.nextIntArray(k);
        
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c[i] * c[(i + 1) % n];
        }
        
        boolean e[] = new boolean[n];
        for (int x : d)
            e[x - 1] = true;
        
        long tot = 0;
        for (int x : c)
            tot += x;
        
        //System.out.println(ans);
        
        for (int x : d) {
            int left = (x - 2 + 2 * n) % n;
            int right = x % n;
            ans += c[x - 1] * (tot - c[x - 1] - c[left] - c[right]);
        }
        
        //System.out.println(ans);
        
        long oth = 0;
        for (int x : d) {
            ans -= oth * c[x - 1];
            oth += c[x - 1];
        }
        
        for (int i = 0; i < n; i++) {
            if (e[i] && e[(i+1)%n])
                ans += c[i] * c[(i+1)%n];
        }
        
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