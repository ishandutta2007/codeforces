import java.io.*;
import java.util.*;

public class R157qC {

    static final int mod = (int) 1e9 + 7;
    
    public static void main(String[] args) {
        final InputReader in = new InputReader(System.in);
        final PrintWriter w = new PrintWriter(System.out);

        final int m = (int) 1e5;
        final int n = in.nextInt();

        final int a[] = in.nextIntArray(n);

        final int f[] = new int[m + 1];
        for (final int x : a)
            f[x]++;

        final int prefix[] = new int[m + 1];
        for (int i = 1; i <= m; i++)
            prefix[i] = prefix[i - 1] + f[i];

        final ArrayList<Integer> div1 = new ArrayList<Integer>();
        final ArrayList<Integer> div2 = new ArrayList<Integer>();

        long ans = 0;
        
        for (int i = 1; i <= m; i++) {

            div1.clear();
            div2.clear();

            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    div1.add(j);
                    if (j * j != i)
                        div2.add(i / j);
                }
            }

            Collections.reverse(div2);
            div1.addAll(div2);

            int next = i, ways = div1.size();
            long currAns = pow(ways, prefix[m] - prefix[i - 1]) - pow(ways - 1, prefix[m] - prefix[i - 1]);
            if (currAns < 0)
                currAns += mod;
            
            for (int j = div1.size() - 2; j >= 0; j--) {

                int x = div1.get(j);
                int currentFreq = prefix[next - 1] - prefix[x - 1];
                ways--;

                currAns = (currAns * pow(ways, currentFreq)) % mod;

                next = x;
            }

            ans += currAns;
        }

        w.println(ans % mod);
        w.close();
    }

    static long pow(int a, int b) {
        if ( b == 0)
            return 1;
        long t = pow(a, b >> 1);
        t = (t * t) % mod;
        if ( (b & 1) == 1)
            t = (t * a) % mod;
        return t;
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