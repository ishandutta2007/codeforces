import java.io.*;
import java.util.*;

public class R363qB {

    static int a[];
    static int n;
    static ArrayList<Integer> g[];
    static boolean vis[];
    static int cycles[];
    static boolean inStack[];
    static boolean need;
    static int t;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = in.nextInt();
        a = in.nextIntArray(n);

        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();

        for (int j = 0; j < n; j++) {
            g[a[j] - 1].add(j);
        }

        vis = new boolean[n];
        cycles = new int[n];
        inStack = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                need = false;
                dfs(i);
                if (need)
                    t++;
            }
        }

        int singles = 0;
        int mainRoot = -1;
        int oRoot = -1;

        for (int i = 0; i < t; i++) {
            int x = cycles[i];
            if (a[x] - 1 == x) {
                singles++;
                mainRoot = x;
            }
            oRoot = x;
        }

        if (mainRoot != -1) {
            int ans = t - 1;
            for (int j = 0; j < t; j++) {
                int x = cycles[j];
                a[x] = mainRoot + 1;
            }
            w.println(ans);
        } else {
            int ans = t;
            for (int j = 0; j < t; j++) {
                int x = cycles[j];
                a[x] = oRoot + 1;
            }
            w.println(ans);
        }

        for (int i = 0; i < n; i++)
            w.print(a[i] + " ");
        w.println();
        w.close();
    }

    static public void dfs(int curr) {
        inStack[curr] = true;
        if (vis[a[curr] - 1]) {
            if (inStack[a[curr] - 1]) {
                cycles[t] = a[curr] - 1;
                need = true;
            }
        } else {
            vis[a[curr] - 1] = true;
            dfs(a[curr] - 1);
        }
        inStack[curr] = false;
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