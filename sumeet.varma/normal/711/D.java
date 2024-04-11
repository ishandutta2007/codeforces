import java.io.*;
import java.util.*;

public class R369qD {
    
    static int n;
    static int a[];
    static final int mod = (int)1e9 + 7;
    static int _2[];
    static boolean vis1[], vis2[];
    static int inStack[];
    static int cycleLength;
    static ArrayList<Integer> g[];
    static ArrayList<Integer> pro;    
    static int stackSize;
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = in.nextInt();
        
        _2 = new int[2 * n];
        _2[0] = 1;
        for (int i = 1; i < _2.length; i++)
            _2[i] = (_2[i - 1] * 2) % mod;
        
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
        }
        
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
            g[i].add(a[i]);
            g[a[i]].add(i);
        }
        
        cycleLength = 0;
        inStack = new int[n];
        vis1 = new boolean[n];
        vis2 = new boolean[n];
        
        long ans = 1;
        
        for (int i = 0; i < n; i++) {
            if (!vis1[i]) {
                pro = new ArrayList<Integer>();
                dfs1(i);
                for (int y : pro) {
                    if (!vis2[y]) {
                        dfs2(y);
                    }
                }
                long now = _2[pro.size() - cycleLength] * 1L * (_2[cycleLength] - 2); 
                now %= mod;
                ans *= now;
                ans %= mod;
            }
        }
        
        w.println(ans);
        w.close();
    }
    
    static void dfs2(int y) {
        inStack[y] = stackSize++;
        
        if (vis2[a[y]]) {
            if (inStack[a[y]] >= 0) {
                cycleLength = inStack[y] - inStack[a[y]] + 1;
            }
        } else {
            vis2[a[y]] = true;
            dfs2(a[y]);
        }
        
        inStack[y] = -1;
        stackSize--;
    }
    
    static void dfs1(int x) {
        if (vis1[x])
            return;
        vis1[x] = true;
        pro.add(x);
        for (int y : g[x]) {
            if (!vis1[y])
                dfs1(y);
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