import java.io.*;
import java.util.*;

public class R167qC {
    
    static ArrayList<Integer> g[];
    static boolean vis[];
    static int ans[];
    
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();
        
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        
        ans = new int[n];
        
        Queue<Integer> q = new LinkedList<Integer>();
        
        for (int i = 0; i < n; i++)
            if (g[i].size() > 1)
                q.add(i);
        
        while (!q.isEmpty()) {
            int c = q.remove();
            int bad = 0;
            for (int j = 0; j < g[c].size(); j++)
                if (ans[g[c].get(j)] == ans[c])
                    bad++;
            if (bad > 1) {
                ans[c] = 1 - ans[c]; 
                for (int j = 0; j < g[c].size(); j++)
                    q.add(g[c].get(j));
            }
        }
        
        for (int i = 0; i < n; i++)
            w.print(ans[i] == 0 ? '0' : '1');
        w.close();
    }
    
    static void dfs(int c) {
        int cnt[] = new int[3];
        int child[] = new int[4];
        int tot = 0;
        for (int next : g[c]) {
            if (!vis[next]) {
                vis[next] = true;
                dfs(next);
                cnt[ans[next]]++;
                child[tot++] = next;
            }
        }
        if (tot == 0)
            ans[c] = 2;
        else if (tot == 1) {
            if (ans[child[0]] <= 1)
                ans[c] = 1 - ans[child[0]];
            else {
                ans[c] = 0;
                ans[child[0]] = 1;
            }
        }
        else if (tot == 2) {
            if (cnt[2] == 0) {
                if (cnt[0] <= cnt[1])
                    ans[c] = 0;
                else
                    ans[c] = 1;
            } else if (cnt[2] == 1) {
                if (cnt[0] <= cnt[1])
                    ans[c] = 0;
                else
                    ans[c] = 1;
                for (int j = 0; j < tot; j++)
                    if (ans[child[j]] == 2)
                        ans[child[j]] = 1 - ans[c];
            } else if (cnt[2] == 2) {
                ans[c] = 0;
                ans[child[0]] = ans[child[1]] = 1;
            } else
                throw new RuntimeException();
        } else if (tot == 3) {
            if (cnt[0] <= cnt[1]) { 
                ans[c] = 1;
                for (int j = 0; j < tot; j++)
                    if (ans[child[j]] == 2)
                        ans[child[j]] = 0;
            }
            else {
                ans[c] = 0;
                for (int j = 0; j < tot; j++)
                    if (ans[child[j]] == 2)
                        ans[child[j]] = 1;
            }
        } else
            throw new RuntimeException();
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