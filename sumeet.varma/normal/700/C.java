import java.io.*;
import java.util.*;

public class R364qC {

    static int n, m;
    static int s, t;
    static ArrayList<Integer> g[];
    static int u[], v[], c[];
    static boolean vis[], deleted[];
    static int disc[], low[], id[], parentEdge[];
    static int time, total;
    static int bParentComp[], bParentEdge[];
    static final long inf = (long)1e14;
    
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = in.nextInt();
        m = in.nextInt();
        
        s = in.nextInt();
        t = in.nextInt();

        g = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            g[i] = new ArrayList<Integer>();
        
        u = new int[m + 1];
        v = new int[m + 1];
        c = new int[m + 1];
        
        for (int i = 1; i <= m; i++) {
            u[i] = in.nextInt();
            v[i] = in.nextInt();
            c[i] = in.nextInt();
            if (u == v)
                continue;
            g[u[i]].add(i);
            g[v[i]].add(i);
        }

        deleted = new boolean[m + 1];
        vis = new boolean[n + 1];
        disc = new int[n + 1];
        low = new int[n + 1];
        parentEdge = new int[n + 1];
        id = new int[n + 1];
        bParentComp = new int[n + 1];
        bParentEdge = new int[n + 1];
        time = 0;
        dfs(s); 

        if (!vis[t]) { //disconnected case
            w.println(0);
            w.println(0);
            w.close();
            return;
        }
        
        ArrayList<Integer> path = new ArrayList<Integer>();
        int temp = t;
        while (temp != s) {
            path.add(parentEdge[temp]);
            temp = other(temp, parentEdge[temp]);
        }
        
        long minCost = Long.MAX_VALUE;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        for (int edgeToRemove : path) {
            
            deleted[edgeToRemove] = true;
            
            long cost = c[edgeToRemove];
            ArrayList<Integer> edgesToRemove = new ArrayList<Integer>();
            edgesToRemove.add(edgeToRemove);
            
            Arrays.fill(vis, false);
            Arrays.fill(disc, 0);
            Arrays.fill(low, 0);
            Arrays.fill(parentEdge, 0);
            time = 0;
            dfs(s); 
            
            Arrays.fill(vis, false);
            Arrays.fill(id, 0);
            Arrays.fill(bParentComp, 0);
            Arrays.fill(bParentEdge, 0);
            total = 1;
            dfs2(s, total);
            
            if(vis[t]) {
                if (id[s] == id[t])
                    cost = inf;
                else {
                    int node = id[t];
                    int minEdge = -1;
                    while (node != id[s]) {
                        if (minEdge == -1 || c[bParentEdge[node]] < c[minEdge])
                            minEdge = bParentEdge[node];
                        node = bParentComp[node];
                    }
                    cost += c[minEdge];
                    edgesToRemove.add(minEdge);
                }
            }
            
            if (cost < minCost) {
                minCost = cost;
                ans = edgesToRemove;
            }
            
            deleted[edgeToRemove] = false;
        }
        
        

       
        if (minCost >= inf)
            w.println(-1);
        else {
            w.println(minCost);
            w.println(ans.size());
            for (int edge : ans)
                w.print(edge + " ");
            w.println();
        }
        
        w.close();
    }
    
    static public int other(int x, int i) {
        return u[i] + v[i] - x;
    }

    static public void dfs(int curr) {
        disc[curr] = low[curr] = time++;
        vis[curr] = true;
        for (int edge : g[curr]) {
            if (deleted[edge])  continue;
            int x = other(curr, edge);
            if (vis[x]) {
                if (edge != parentEdge[curr])
                    low[curr] = Math.min(low[curr], disc[x]);
            } else {
                parentEdge[x] = edge;
                dfs(x);
                low[curr] = Math.min(low[x], low[curr]);
            }
        }
    }

    static public void dfs2(int curr, int type) {
        id[curr] = type;
        vis[curr] = true;
        for (int edge : g[curr]) {
            if (deleted[edge])  continue;
            int x = other(curr, edge);
            if (!vis[x]) {
                if (low[x] > disc[curr]) {
                    ++total;
                    bParentEdge[total] = edge;
                    bParentComp[total] = type;
                    dfs2(x, total);
                }
                else
                    dfs2(x, type);
            }
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