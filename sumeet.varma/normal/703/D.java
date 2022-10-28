import java.io.*;
import java.util.*;

public class R365qD {
    
    static int segtree[];
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = in.nextInt();
        
        int a[] = new int[n + 1];
        int p[] = new int[n + 1];
        MyArrayList g[] = new MyArrayList[n + 1];
        
        for (int i = 1; i <= n; i++) {
            a[i] = in.nextInt();
            p[i] = p[i - 1] ^ a[i];
            g[i] = new MyArrayList();
        }
        
        int m = in.nextInt();
        int l[] = new int[m];
        int ans[] = new int[m];
        
        for (int i = 0; i < m; i++) {
            l[i] = in.nextInt();
            g[in.nextInt()].add(i);
        }
        
        segtree = new int[4 * n];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for (int i = 1; i <= n; i++) {
            if(map.containsKey(a[i]))
                update(1, n, 0, map.get(a[i]), 0);
            map.put(a[i], i);
            update(1, n, 0, i, a[i]);
            for (int j = 0; j < g[i].size(); j++) {
                int id = g[i].get(j);
                ans[id] = find(1, n, 0, l[id], i) ^ p[i] ^ p[l[id] - 1];
            }
        }
        
        for (int i = 0; i < m; i++)
            w.println(ans[i]);
        
        w.close();
    }
    
    public static void update(int s, int e, int c, int x, int v) {
        if (s == e) {
            segtree[c] = v;
            return;
        }
        int m = (s + e) >> 1;
        if (x <= m)
            update(s, m, 2 * c + 1, x, v);
        else
            update(m + 1, e, 2 * c + 2, x, v);
        segtree[c] = merge(segtree[2 * c + 1], segtree[2 * c + 2]);
    }

    public static int find(int s, int e, int c, int l, int r) {
        if (s == l && e == r)
            return segtree[c];
        int m = (s + e) >> 1;
        if (r <= m)
            return find(s, m, 2 * c + 1, l, r);
        if (l > m)
            return find(m + 1, e, 2 * c + 2, l, r);
        return merge(find(s, m, 2 * c + 1, l, m), find(m + 1, e, 2 * c + 2, m + 1, r));
    }

    public static int merge(int a, int b) {
        return a ^ b;
    }
    
    static public class MyArrayList {

        private int[] myStore;
        private int actSize = 0;

        public MyArrayList() {
            myStore = new int[2];
        }

        public int get(int index) {
            if (index < actSize)
                return myStore[index];
            else
                throw new ArrayIndexOutOfBoundsException();
        }

        public void add(int obj) {
            if (myStore.length - actSize <= 1)
                increaseListSize();
            myStore[actSize++] = obj;
        }

        public int size() {
            return actSize;
        }

        public void clear() {
            actSize = 0;
        }

        private void increaseListSize() {
            myStore = Arrays.copyOf(myStore, myStore.length * 2);
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