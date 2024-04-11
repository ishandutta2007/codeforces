import java.io.*;
import java.util.*;

public class HelveticqB {

    static int ans;
    static ArrayList<Integer> g[];
    static int depth[], md[];
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();
        
        for (int i = 1; i <= m; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            g[u].add(v);
            g[v].add(u);
        }
       
        depth = new int[n];
        md = new int[n];
        
        dfs(0, -1, 0);
        w.println(ans);
        
        w.close();
    }
    
    static void dfs(int c, int p, int d) {
        depth[c] = d;
        md[c] = 0;
        for (int x : g[c]) {
           if (x != p) {
               dfs(x, c, d + 1);
               int b = 1 + md[x];
               ans = Math.max(ans, b + md[c]);
               md[c] = Math.max(md[c], b);
           }
        }
    }
    
    static public class DisjointSet {

        public int rank[],parent[],size[];
        public int n,comp;
        
        public DisjointSet(int n){
            this.n = n;
            makeSet();
        }
        
        public void makeSet(){
            rank = new int[n];
            parent = new int[n];
            for(int i=0;i<n;i++)
                parent[i] = i;
            size = new int[n];
            Arrays.fill(size, 1);
            comp = n;
        }
        
        public int find(int x){
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        public void merge(int x,int y){
            int xRoot = find(x);
            int yRoot = find(y);
            
            if(xRoot == yRoot)  return;
            
            size[xRoot] = size[yRoot] = size[xRoot] + size[yRoot];
            
            if(rank[xRoot] < rank[yRoot])
                parent[xRoot] = yRoot;
            else{
                parent[yRoot] = xRoot;
                if(rank[xRoot] == rank[yRoot]) rank[xRoot]++;
            }
            
            comp--;
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