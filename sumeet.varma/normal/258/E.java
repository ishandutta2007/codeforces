import java.io.*;
import java.util.*;

public class R157qE {

    static int n, m;
    static ArrayList<Integer> g[], h[];
    static int time;
    static int tin[], tout[];
    static int ans[];
    static Node st[];

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = in.nextInt();
        m = in.nextInt();

        g = new ArrayList[n];
        h = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
            h[i] = new ArrayList<Integer>();
        }

        for (int i = 1; i < n; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            g[u].add(v);
            g[v].add(u);
        }

        time = -1;
        tin = new int[n];
        tout = new int[n];
        dfs(0, -1);

        while (m-- > 0) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            h[a].add(b);
            h[b].add(a);
        }

        st = new Node[4 * n];
        build(0, n - 1, 0);

        ans = new int[n];
        dfs2(0, -1);

        for (int i = 0; i < n; i++)
            w.print((ans[i] > 0 ? (ans[i] - 1) : 0) + " ");
        w.println();

        w.close();
    }

    static public void dfs2(int c, int p) {
        for (int b : h[c])
            update(0, n - 1, 0, tin[b], tout[b], 1);
        if (!h[c].isEmpty())
            update(0, n - 1, 0, tin[c], tout[c], 1);
        ans[c] = st[0].min == 0 ? (n - st[0].freq) : n;
        for (int d : g[c])
            if (d != p)
                dfs2(d, c);
        for (int b : h[c])
            update(0, n - 1, 0, tin[b], tout[b], -1);
        if (!h[c].isEmpty())
            update(0, n - 1, 0, tin[c], tout[c], -1);
    }

    static public void build(int s, int e, int c) {
        st[c] = new Node(0, e - s + 1);
        if (s == e)
            return;
        int m = (s + e) >> 1;
        build(s, m, 2 * c + 1);
        build(m + 1, e, 2 * c + 2);
    }

    static public void update(int s, int e, int c, int l, int r, int v) {
        if (s == l && e == r) {
            st[c].min += v;
            st[c].lazy += v;
            return;
        }
        propogate(c);
        int m = (s + e) >> 1;
        if (r <= m)
            update(s, m, 2 * c + 1, l, r, v);
        else if (l > m)
            update(m + 1, e, 2 * c + 2, l, r, v);
        else {
            update(s, m, 2 * c + 1, l, m, v);
            update(m + 1, e, 2 * c + 2, m + 1, r, v);
        }
        st[c] = merge(st[2 * c + 1], st[2 * c + 2]);
    }
    
    static void propogate(int c) {
        st[2 * c + 1].lazy += st[c].lazy;
        st[2 * c + 1].min += st[c].lazy;
        st[2 * c + 2].lazy += st[c].lazy;
        st[2 * c + 2].min += st[c].lazy;
        st[c].lazy = 0;
    }

    static Node merge(Node l, Node r) {
        if (l.min < r.min)
            return new Node(l.min, l.freq);
        if (r.min < l.min)
            return new Node(r.min, r.freq);
        return new Node(l.min, l.freq + r.freq);
    }

    static public void dfs(int c, int p) {
        tin[c] = ++time;
        for (int d : g[c]) {
            if (d != p) {
                dfs(d, c);
            }
        }
        tout[c] = time;
    }

    static class Node {
        int min;
        int freq;
        int lazy;
        Node(int min, int freq) {
            this.min = min;
            this.freq = freq;
            this.lazy = 0;
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