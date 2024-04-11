import java.io.*;
import java.util.*;

public class R368qD {

    static boolean a[][];
    static boolean l[];
    static int c[];
    static int ans[];
    static int sum;
    static int n,m,q;
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = in.nextInt();
        m = in.nextInt();
        q = in.nextInt();
        
        a = new boolean[n + 1][m + 1];
        l = new boolean[n + 1];
        c = new int[n + 1];
        ans = new int[q + 1];
        sum = 0;
        
        Query Q[] = new Query[q + 1];
        Q[0] = new Query(-1, -1, -1, 0);
        
        for (int i = 1; i <= q; i++) {
            int t = in.nextInt();
            if (t <= 2)
               Q[i] = new Query(t, in.nextInt(), in.nextInt(), i);
            else
                Q[i] = new Query(t, in.nextInt(), -1, i);
            if (t == 4)
                Q[Q[i].i].child.add(Q[i]);
            else
                Q[i - 1].child.add(Q[i]);
        }
        
        dfs(Q[0]);
        
        for (int i = 1; i <= q; i++)
            w.println(ans[i]);
        
        w.close();
    }
    
    static void dfs(Query Q) {
        //System.out.println(Q.idx + " " + sum);
        if (Q.type == -1) {
            for (Query QQ : Q.child)
                dfs(QQ);
        }
        else if (Q.type == 1) {
            boolean pres = a[Q.i][Q.j] ^ l[Q.i];
            if (!pres) {
                a[Q.i][Q.j] = !a[Q.i][Q.j];
                c[Q.i]++;
                sum++;
            }
            ans[Q.idx] = sum;
            for (Query QQ : Q.child)
                dfs(QQ);
            if (!pres) {
                a[Q.i][Q.j] = !a[Q.i][Q.j];
                c[Q.i]--;
                sum--;
            }
        }
        else if (Q.type == 2) {
            boolean pres = a[Q.i][Q.j] ^ l[Q.i];
            if (pres) {
                a[Q.i][Q.j] = !a[Q.i][Q.j];
                c[Q.i]--;
                sum--;
            }
            ans[Q.idx] = sum;
            for (Query QQ : Q.child)
                dfs(QQ);
            if (pres) {
                a[Q.i][Q.j] = !a[Q.i][Q.j];
                c[Q.i]++;
                sum++;
            }
        }
        else if (Q.type == 3) {
            l[Q.i] = !l[Q.i];
            sum -= c[Q.i];
            c[Q.i] = m - c[Q.i];
            //System.out.println(Q.idx + " " + c[Q.i]);
            sum += c[Q.i];
            ans[Q.idx] = sum;
            for (Query QQ : Q.child)
                dfs(QQ);
            l[Q.i] = !l[Q.i];
            sum -= c[Q.i];
            c[Q.i] = m - c[Q.i];
            sum += c[Q.i];
        }
        else if (Q.type == 4) {
            ans[Q.idx] = sum;
            for (Query QQ : Q.child)
                dfs(QQ);
        }
        //System.out.println(Q.idx + " " + sum);
    }
    
    static class Query {
        int type, i, j, idx;
        List<Query> child;
        Query(int type, int i, int j, int idx) {
            this.type = type;
            this.i = i;
            this.j = j;
            this.idx = idx;
            child = new ArrayList<Query>();
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