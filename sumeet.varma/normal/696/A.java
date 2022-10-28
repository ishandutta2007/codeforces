import java.io.*;
import java.util.*;

public class R362qA {

    static HashMap<Long, Long> map = new HashMap<Long, Long>();
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int q = in.nextInt();
        
        while (q-- > 0) {
            int t = in.nextInt();
            if (t == 1) {
                long u = in.nextLong();
                long v = in.nextLong();
                int c = in.nextInt();
                int ud = Long.toBinaryString(u).length();
                int vd = Long.toBinaryString(v).length();
                while (ud > vd) {
                    ud--;
                    add(u, c);
                    u >>= 1;
                }
                while (vd > ud) {
                    vd--;
                    add(v, c);
                    v >>= 1;
                }
                while (u != v) {
                    add(u, c);
                    add(v, c);
                    u >>= 1;
                    v >>= 1;
                }
            }
            else {
                long u = in.nextLong();
                long v = in.nextLong();
                int ud = Long.toBinaryString(u).length();
                int vd = Long.toBinaryString(v).length();
                long ans = 0;
                while (ud > vd) {
                    ud--;
                    ans += map.containsKey(u) ? map.get(u) : 0;
                    u >>= 1;
                }
                while (vd > ud) {
                    vd--;
                    ans += map.containsKey(v) ? map.get(v) : 0;
                    v >>= 1;
                }
                while (u != v) {
                    ans += map.containsKey(u) ? map.get(u) : 0;
                    ans += map.containsKey(v) ? map.get(v) : 0;
                    u >>= 1;
                    v >>= 1;
                }
                w.println(ans);
            }
        }
        
        w.close();
    }
    
    static void add(long a, long b) {
        if (!map.containsKey(a))
            map.put(a, 0L);
        map.put(a, map.get(a) + b);
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