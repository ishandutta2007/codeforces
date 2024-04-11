import java.io.*;
import java.util.*;

public class R356qA {

    static HashMap<Long, Long> cnt;
    static HashMap<Long, Long> val;
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        long n = in.nextLong();
        
        cnt = new HashMap<Long, Long>();
        val = new HashMap<Long, Long>();
        cnt.put(0L, 0L);
        val.put(0L, 0L);
        dp(n);
        
        w.println(cnt.get(n) + " " + val.get(n));
        w.close();
    }
    
    static public void dp(long n) {
        if(cnt.containsKey(n))
            return;
        long s = 1, e = (long)1e5 + 10;
        long best = 0;
        while (s < e) {
            long m = (s + e) >> 1;
            if ( m * m * m <= n) {
                s = m + 1;
                best = m * m * m;
            }
            else
                e = m;
        }
        dp(n - best);
        dp(best - 1);
        long cnt1 = cnt.get(n - best) + 1;
        long ans1 = val.get(n - best) + best;
        long cnt2 = cnt.get(best - 1);
        long ans2 = val.get(best - 1);
        if (cnt1 > cnt2 || (cnt1 == cnt2 && ans1 >= ans2)) {
            cnt.put(n, cnt1);
            val.put(n, ans1);
        } else {
            cnt.put(n, cnt2);
            val.put(n, ans2); 
        }
    }

    static class InputReader {

        private InputStream stream;
        private byte[] buf = new byte[8192];
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
            while (isSpaceChar(c))
                c = snext();
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
            while (isSpaceChar(c))
                c = snext();
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
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public String readString() {
            int c = snext();
            while (isSpaceChar(c))
                c = snext();
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