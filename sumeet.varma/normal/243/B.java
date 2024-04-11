import java.io.*;
import java.util.*;

public class R150qB {

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int h = in.nextInt();
        int t = in.nextInt();

        HashSet<Integer> set[] = new HashSet[n + 1];
        for (int i = 1; i <= n; i++)
            set[i] = new HashSet<Integer>();

        int a[] = new int[m + 1];
        int b[] = new int[m + 1];
        for (int i = 1; i <= m; i++) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
            set[a[i]].add(b[i]);
            set[b[i]].add(a[i]);
        }
        
        boolean f = false;
        int u = -1, v = -1;
        
        for (int i = 1; i <= m; i++) {
            
            if(set[a[i]].size() > set[b[i]].size()) {
                int temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
            
            int x = set[a[i]].size() - 1;
            int y = set[b[i]].size() - 1;
            int c = 0;
            
            boolean canSearch = (x >= t && y >= h) || (x >= h && y >= t);
            
            if(canSearch) {
                for (int neigh : set[a[i]]) {
                    if(neigh == b[i])
                        continue;
                    if(set[b[i]].contains(neigh)) {
                        x--;
                        y--;
                        c++;
                    }
                }
            }
            
            if(Math.max(0, h - x) + Math.max(0, t - y) <= c) {
                f = true;
                u = a[i];
                v = b[i];
                break;
            }
            
            if(Math.max(0, t - x) + Math.max(0, h - y) <= c) {
                f = true;
                u = b[i];
                v = a[i];
                break;
            }
        }
        
        if(!f)
            w.println("NO");
        else {
            w.println("YES");
            w.println(u + " " + v);
            List<Integer> A = new ArrayList<Integer>();
            List<Integer> B = new ArrayList<Integer>();
            List<Integer> C = new ArrayList<Integer>();
            
            for (int neigh : set[u]) {
                if (neigh != v) {
                    if (set[v].contains(neigh))
                        C.add(neigh);
                    else
                        A.add(neigh);
                }
            }
            
            for (int neigh : set[v]) {
                if (neigh != u) {
                    if (!set[u].contains(neigh))
                        B.add(neigh);
                }
            }
            
            int extraCnt = 0;
            
            for (int j = 0; j < Math.min(A.size(), h); j++)
                w.print(A.get(j) + " ");
            for (int j = 0; j < h - A.size(); j++)
                w.print(C.get(extraCnt++) + " ");
            w.println(); 
            
            for (int j = 0; j < Math.min(B.size(), t); j++)
                w.print(B.get(j) + " ");
            for (int j = 0; j < t - B.size(); j++)
                w.print(C.get(extraCnt++) + " ");
            w.println();
        }

        w.close();
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