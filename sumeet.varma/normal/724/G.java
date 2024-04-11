import java.io.*;
import java.util.*;

public class IntelqE {

    static int n, m;
    static int[] u, v;
    static long[] t, up;
    static ArrayList<Integer> g[];
    static boolean vis[];
    static ArrayList<Long> basis, values;
    static final int mod = (int) 1e9 + 7;

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = in.nextInt();
        m = in.nextInt();

        u = new int[m];
        v = new int[m];
        t = new long[m];

        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();

        for (int i = 0; i < m; i++) {
            u[i] = in.nextInt() - 1;
            v[i] = in.nextInt() - 1;
            t[i] = in.nextLong();
            g[u[i]].add(i);
            g[v[i]].add(i);
        }

        vis = new boolean[n];
        basis = new ArrayList<Long>();
        values = new ArrayList<Long>();
        up = new long[n];
        long ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                basis.clear();
                values.clear();
                dfs(i, 0, -1);
                ans += getAns();
                ans %= mod;
            }
        }

        w.println(ans);
        w.close();
    }

    static public long getAns() {
        long ans = 0;

        long cntOnes[] = new long[63];
        long cntZeros[] = new long[63];

        //System.out.println(basis);
        
        //HashSet<Long> basis2 = new HashSet<Long>();
        //for (long x : basis)
          //  basis2.add(x);
        
        //System.out.println(basis2);
        
        for (long x : basis) {
            for (int j = 0; j <= 62; j++) {
                if (get(x, j)) {
                    cntOnes[j]++;
                } else {
                    cntZeros[j]++;
                }
            }
        }

        for (int i = 62; i >= 0; i--) {

            long ones = 0, zeros = 0;
            
            for (long x : values) {
                if (get(x, i)) {
                    ones++;
                } else {
                    zeros++;
                }
            }

            long f = pow(i);

            long zerosInBasis = 1;

            long onesInBasis = 0;

            if (cntOnes[i] > 0) {
                onesInBasis = pow(cntZeros[i]) * pow(cntOnes[i] - 1);
                onesInBasis %= mod;
                zerosInBasis = onesInBasis;
            } else {
                zerosInBasis = pow(cntZeros[i]);
                zerosInBasis %= mod;
                onesInBasis = 0;
            }

            long c = 0;

            long onesInTree = ones * zeros;
            onesInTree %= mod;

            long zerosInTree = (ones * (ones - 1)) / 2 + (zeros * (zeros - 1)) / 2;
            zerosInTree %= mod;

            c += onesInTree * zerosInBasis;
            c %= mod;

            c += zerosInTree * onesInBasis;
            c %= mod;

            ans += f * c;
            ans %= mod;
        }
        
        return ans;
    }

    static long pow(long i) {
        return (1L << i) % mod;
    }

    static boolean get(long num, int bit) {
        return (num & (1L << bit)) != 0;
    }

    static public void dfs(int curr, long xor, int parentEdge) {
        if (vis[curr])
            return;
        vis[curr] = true;
        up[curr] = xor;
        for (int edge : g[curr]) {
            int next = u[edge] + v[edge] - curr;
            if (!vis[next]) {
                dfs(next, xor ^ t[edge], edge);
            } else {
                if (edge != parentEdge) {
                    add(t[edge] ^ up[curr] ^ up[next]);
                }
            }
        }
        values.add(up[curr]);
    }

    static public void add(long x) {
        for (long it : basis)
            if ((x ^ it) < x)
                x ^= it;

        for (int i = 0; i < basis.size(); i++) {
            long it = basis.get(i);
            if ((x ^ it) < it)
                it ^= x;
            basis.set(i, it);
        }

        if (x > 0) {
            basis.add(x);
          //  Collections.sort(basis);
        }

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