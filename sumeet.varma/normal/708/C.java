import java.io.*;
import java.util.*;

public class AimTech3qC {

    static int n;
    static ArrayList<Integer> g[];
    static int st[];
    static int largDown[], largUp[];
    static int ans[];

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = in.nextInt();

        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();

        for (int i = 1; i < n; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            //int u = i;
            //int v = new Random().nextInt(i);//in.nextInt() - 1;
            g[u].add(v);
            g[v].add(u);
            //System.out.println(u + " " + v);
        }

        st = new int[n];
        largDown = new int[n];
        dfs1(0, -1);

        largUp = new int[n];
        if (1 <= n / 2)
            Arrays.fill(largUp, 1);
        dfs2(0, -1);
        
        //System.out.println(Arrays.toString(largUp));

        ans = new int[n];
        dfs3(0, -1);

        //brute();
        
        for (int i = 0; i < n; i++)
            w.print(ans[i] + " ");
        w.close();
    }

    static void dfs1(int c, int p) {
        st[c] = 1;
        for (int next : g[c]) {
            if (next != p) {
                dfs1(next, c);
                st[c] += st[next];
                largDown[c] = Math.max(largDown[c], largDown[next]);
            }
        }
        if (st[c] <= n / 2)
            largDown[c] = Math.max(largDown[c], st[c]);
    }

    static void dfs2(int c, int p) {

        int list[] = new int[g[c].size() + 2];
        int ptr = 0;

        for (int next : g[c]) {
            if (next != p) {
                list[ptr++] = largDown[next];
            }
        }

        Arrays.sort(list);

        for (int next : g[c]) {
            if (next == p)
                continue;
            largUp[next] = Math.max(largUp[next], largUp[c]);
            //if (next == 1)
              //  System.out.println(largUp[c] + " " + c + " " + n/2);
            if (st[0] - st[next] <= n / 2)
                largUp[next] = Math.max(largUp[next], st[0] - st[next]);
            if (list[list.length - 1] != largDown[next])
                largUp[next] = Math.max(largUp[next], list[list.length - 1]);
            else
                largUp[next] = Math.max(largUp[next], list[list.length - 2]);
            //if (next == 1)
              //  System.out.println(next + " " + largUp[next]);
        }

        for (int next : g[c]) {
            if (next == p)
                continue;
            dfs2(next, c);
        }
    }

    static void dfs3(int c, int p) {
        ans[c] = 1;
        for (int next : g[c]) {
            if (next == p)
                continue;
            dfs3(next, c);
            if (st[next] > n / 2) {
                ans[c] = 0;
                if (st[next] - largDown[next] <= n / 2)
                    ans[c] = 1;
            }
        }
        int o = st[0] - st[c];
        if (o > n / 2) {
            ans[c] = 0;
            if (o - largUp[c] <= n / 2)
                ans[c] = 1;
        }
    }

    /*static int[] brute() {
        int my[] = new int[n];
        for (int i = 0; i < n; i++) {
            my[i] = dfs4(i, -1);
            if (my[i] != ans[i]) {
                System.out.println("sad  " + i + " " + my[i] + " " + ans[i] );
            }
        }
        return my;
    }

    static int dfs4(int c, int p) {
        st[c] = 1;
        int max = 0;
        largDown[c] = 0;
        for (int next : g[c]) {
            if (next != p) {
                dfs4(next, c);
                st[c] += st[next];
                max = Math.max(max, st[next]);
                largDown[c] = Math.max(largDown[c], largDown[next]);
            }
        }
        if (st[c] <= n / 2)
            largDown[c] = Math.max(largDown[c], st[c]);
        if (p == -1) {
            int ans = 1;
            for (int next : g[c]) {
                if (next != p) {
                    if (st[next] > n / 2) {
                        ans = 0;
                        if (st[next] - largDown[next] <= n / 2) {
                            ans = 1;
                        }
                    }
                }
            }
            return ans;
        }
        else
            return -1;
    }*/

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