import java.io.*;
import java.util.*;

public class R365qE {
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        long k = in.nextLong();

        long[] a = new long[n + 1];
        long[] b = new long[n + 1];
        
        long min = Long.MAX_VALUE;
        int minIndex = 0;
        
        for (int i = 1; i <= n; i++) {
            a[i] = in.nextLong();
            b[i] = gcd(a[i], k);
            if (a[i] < min) {
                min = a[i];
                minIndex = i;
            }
        }

        if (k == 1) {
            w.println(1);
            w.println(minIndex);
            w.close();
            return;
        }

        ArrayList<Long> div = new ArrayList<Long>();
        for (long i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                div.add(i);
                if (i * i != k)
                    div.add(k / i);
            }
        }

        Collections.sort(div);
        HashMap<Long, Integer> map = new HashMap<Long, Integer>(100000);
        long divLong[] = new long[div.size()];
        for (int i = 0; i < div.size(); i++) {
            map.put(div.get(i), i);
            divLong[i] = div.get(i);
        }

        int N = div.size();

        final int inf = (int)1e9;
        int len[] = new int[N];
        long sum[] = new long[N];
        boolean best[][] = new boolean[n + 1][N];

        Arrays.fill(len, inf);
       
        len[0] = 0;
        sum[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int idx = N - 1; idx >= 0; idx--) {
                int newIdx = map.get(divLong[idx] / gcd(divLong[idx], b[i]));
                if (len[newIdx] + 1 < len[idx]) {
                    len[idx] = len[newIdx] + 1;
                    sum[idx] = sum[newIdx] + a[i];
                    best[i][idx] = true;
                } else if (len[newIdx] + 1 == len[idx]) {
                    if (sum[newIdx] + a[i] < sum[idx]) {
                        sum[idx] = sum[newIdx] + a[i];
                        best[i][idx] = true;
                    }
                }
            }
        }

        if (len[N - 1] == inf)
            w.println(-1);
        else {
            w.println(len[N - 1]);
            int idx = N - 1;
            for (int i = n; i >= 1; i--) {
                if (best[i][idx]) {
                    w.print(i + " ");
                    idx = map.get(div.get(idx) / gcd(div.get(idx), b[i]));
                }
            }
            w.println();
        }

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