import java.io.*;
import java.util.*;

public class R362qB {

    static ArrayList<Integer> g[];
    static double ans[];
    static int st[];
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        
        if (n == 1) {
            System.out.println(1.0);
            return;
        }
        
        int p[] = in.nextIntArray(n - 1);
        
        g = new ArrayList[n];
        for (int i = 0 ;i < n; i++)
            g[i] = new ArrayList<Integer>();
        
        for (int i = 0; i < n - 1; i++) {
            g[p[i] - 1].add(i + 1);
        }
        
        st = new int[n];
        dfs(0);
        
        ans = new double[n];
        ans[0] = 1;
        
        dfs2(0);
        
        for (int i = 0; i < n; i++)
            w.print(ans[i] + " ");
        w.println();
        w.close();
    }
    
    static public void dfs2(int c) {
        for (int nx : g[c])
            ans[nx] = ans[c] + 1 + 0.5 * (st[c] - 1 - st[nx]);
        for(int nx : g[c])
            dfs2(nx);
    }
    
    static public void dfs(int c) {
        st[c] = 1;
        for (int nx : g[c]) {
            dfs(nx);
            st[c] += st[nx];
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