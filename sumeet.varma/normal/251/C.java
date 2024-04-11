import java.io.*;
import java.util.*;

public class R153qC {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        long a = in.nextLong();
        long b = in.nextLong();
        int k = in.nextInt();
        
        int lcm = 1;
        for (int i = 2; i <= k; i++)
            lcm = lcm(lcm, i);
        
        long x1 = a / lcm;
        int y1 = (int)(a % lcm);
        
        long x2 = b / lcm;
        int y2 = (int)(b % lcm);
        
        if(x1 == x2) {
            w.println(bfs(y1, lcm,k)[y2]);
        } else {
            int d1[] = bfs(y1, lcm, k);
            int d2[] = bfs(0, lcm, k);
            long ans = d1[0] + d2[y2] + getCycle(0, d2, k) * (x1 - x2 - 1);
            w.println(ans);
        }
        
        w.close();
    }
    
    static int getCycle(int source, int d[], int k) {
        int ans = d.length;
        for (int i = 0; i < d.length; i++) {
            boolean f = false;
            f |= (i - 1 + 20 * d.length) % d.length == source;
            for (int j = 2; j <= k; j++)
                f |= (i - (i % j) + 20 * d.length) % d.length == source && i % j != 0;
            if (f)
                ans = Math.min(ans, d[i] + 1);
        }
        return ans;
    }
    
    static int[] bfs(int source, int lcm, int k) {
        int d[] = new int[lcm];
        Arrays.fill(d, -1);
        d[source] = 0;
        
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(source);
        while (!q.isEmpty()) {
            int c = q.remove();
            int cc = (c - 1 + 20 * lcm) % lcm;
            if(d[cc] == -1) {
                d[cc] = d[c] + 1;
                q.add(cc);
            }
            for (int i = 2; i <= k; i++) {
                cc = (c - (c % i) + 20 * lcm) % lcm;
                if(d[cc] == -1) {
                    d[cc] = d[c] + 1;
                    q.add(cc);
                }
            }
        }
        
        return d;
    }

    static int gcd(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        if (a >= b)
            return gcd(a % b, b);
        else
            return gcd(a, b % a);
    }
    
    static int lcm(int a, int b) {
        return a * b / gcd(a, b);
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