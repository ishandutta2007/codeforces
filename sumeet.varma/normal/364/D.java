import java.io.*;
import java.util.*;

public class R213qD {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = in.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextLong();
        
        long ans = 1;
        int half = (n + 1) / 2;
        
        HashSet<Long> done = new HashSet<Long>();
        
        for (int i = 0;i < 7; i++) {
            int r = new Random().nextInt(n);
            if(done.contains(a[r]))
                continue;
            done.add(a[r]);
            TreeMap<Long , Integer> value = new TreeMap<>();
            for (long j = 1; j * j <= a[r]; j++) {
                if (a[r] % j == 0) {
                    value.put(j, 0);
                    value.put(a[r] / j, 0);
                }
            }
            long div[] = new long[value.size()];
            int ptr = 0;
            for (long d : value.keySet()) {
                value.put(d, ptr);
                div[ptr++] = d;
            }
            int cnt[] = new int[ptr];
            for (int j = 0; j < n; j++) {
                long g = gcd(a[j], a[r]);
                cnt[value.get(g)]++;
            }
            for (int x = 0; x < ptr; x++) {
                for (int y = x + 1; y < ptr; y++) {
                    if(div[y] % div[x] == 0)
                        cnt[x] += cnt[y];
                }
                if(cnt[x] >= half)
                    ans = Math.max(ans, div[x]);
            }   
        }
        
        w.println(ans);
        w.close();
    }

    public static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
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