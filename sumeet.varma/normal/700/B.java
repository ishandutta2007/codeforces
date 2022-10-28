import java.io.*;
import java.util.*;

public class R364qB {

    static ArrayList<Integer> g[];
    static int b[];
    static boolean c[];
    static long ans;
    static int st[];
    static long sum[];
    static int depth[];
    static int rem[];
    static int lcaCount[];

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int k = in.nextInt();

        b = new int[2 * k];
        c = new boolean[n];
        for (int i = 0; i < 2 * k; i++) {
            b[i] = in.nextInt() - 1;
            c[b[i]] = true;
        }

        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();
        
        for (int i = 1; i < n; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            g[u].add(v);
            g[v].add(u);
        }
        
        ans = 0;
        st = new int[n];
        sum = new long[n];
        depth = new int[n];
        dfs1(0, -1, 0);
        
        lcaCount = new int[n];
        rem = new int[n];
        dfs2(0, -1);
        
        for (int i = 0; i < n; i++) {
            ans -= depth[i] * 1L * lcaCount[i];
            if (c[i])
                ans += depth[i];
        }
        
        w.println(ans);
        w.close();
    }
    
    static public void dfs1(int cr, int p, int d) {
        st[cr] = c[cr] ? 1 : 0;
        if (c[cr])
            sum[cr] = d;
        depth[cr] = d;
        for (int v : g[cr]) {
            if (v != p) {
                dfs1(v, cr, d + 1);
                st[cr] += st[v];
                sum[cr] += sum[v];
            }
        }
    }
    
    static public void dfs2(int u, int p) {
        int maxIdx = -1;
        for (int v : g[u]) {
            if (v != p) {
                if(maxIdx == -1 || st[v] > st[maxIdx])
                    maxIdx = v;
            }
        }
        if (maxIdx == -1)
            return;
        int totalEntries = st[u] - rem[u];
        rem[maxIdx] += rem[u];
        int lastEntries = st[maxIdx] - rem[u];
        if (lastEntries <= totalEntries - lastEntries) {
            lcaCount[u] = totalEntries;
        }
        else {
            lcaCount[u] = 2 * (totalEntries - lastEntries);
            rem[maxIdx] += totalEntries - lastEntries;
            dfs2(maxIdx, u);
        }
    }
    
    static class Pair2 implements Comparable<Pair2> {
        int idx, val;

        Pair2(int i, int v) {
            idx = i;
            val = v;
        }

        public int compareTo(Pair2 o) {
            if (val != o.val)
                return Integer.compare(val, o.val);
            return Integer.compare(idx, o.idx);
        }

        public String toString() {
            return idx + " " + val;
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