import java.io.*;
import java.util.*;

public class R288qD {

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();

        ArrayList<Integer> g[] = new ArrayList[62 * 62 + 62];
        for (int i = 0; i < g.length; i++)
            g[i] = new ArrayList<Integer>();
        
        while (n-- > 0) {
            char s[] = in.readString().toCharArray();
            int u = hash(s[0], s[1]);
            int v = hash(s[1], s[2]);
            g[u].add(v);
        }

        ArrayList<Integer> eulerPath = getEulerPath(g);
        
        if (eulerPath == null)
            w.println("NO");
        else {
            w.println("YES");
            for (int h : eulerPath)
                w.print(getChar(h / 62));
            w.println(getChar(eulerPath.get(eulerPath.size() - 1) % 62));
        }

        w.close();
    }

    public static ArrayList<Integer> getEulerPath(ArrayList<Integer> g[]) {

        int n = g.length;
        int totalEdges = 0;
      
        int inDegree[] = new int[n];
        int startingVertex = -1;
        
        for (int u = 0; u < n; u++) {
            for (int v : g[u])
                inDegree[v]++;
            if (g[u].size() > 0)
                startingVertex = u;
            totalEdges += g[u].size();
        }
        
        int deficit = 0;
        
        for (int i = 0; i < n; i++) {
            if (g[i].size() > inDegree[i]) {
                deficit += g[i].size() - inDegree[i];
                startingVertex = i;
            }
        }
        
        if (deficit > 1)
            return null;
     
        // initialize stack with any non-isolated vertex
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(startingVertex);

        // greedily search through edges in iterative DFS style
        Stack<Integer> path = new Stack<Integer>();
        int ptr[] = new int[n];
        
        while (!stack.isEmpty()) {
            int v = stack.pop();
            while (ptr[v] < g[v].size()) {
                stack.push(v);
                v = g[v].get(ptr[v]++);
            }
            // push vertex with no more leaving edges to path
            path.push(v);
        }
        
        // check if all edges are used
        if (path.size() != totalEdges + 1)
            path = null;

        if (path == null)
            return null;
                    
        ArrayList<Integer> eulerPath = new ArrayList<Integer>(path);
        Collections.reverse(eulerPath);
        return eulerPath;
    }

    static char getChar(int h) {
        if (h < 10)
            return (char) ('0' + h);
        if (h < 10 + 26)
            return (char) ('a' + h - 10);
        if (h < 10 + 26 + 26)
            return (char) ('A' + h - 10 - 26);
        return '\n';
    }

    static int hash(char a, char b) {
        return 62 * hash(a) + hash(b);
    }

    static int hash(char a) {
        if (a >= '0' && a <= '9')
            return a - '0';
        if (a >= 'a' && a <= 'z')
            return a - 'a' + 10;
        if (a >= 'A' && a <= 'Z')
            return a - 'A' + 10 + 26;
        return -1;
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