import java.io.*;
import java.util.*;

public class R213qB {

    static TreeMap<Integer, Integer> map;
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = in.nextInt();
        int d = in.nextInt();
        int m = 10000;
        
        int a[] = in.nextIntArray(n);
        
        long cnt[][] = new long[n + 1][n * m + 1];
        cnt[n][0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < cnt[0].length; j++) {
                cnt[i][j] = cnt[i + 1][j];
                if (j - a[i] >= 0)
                    cnt[i][j] += cnt[i + 1][j - a[i]];
            }
        }
        
        //System.out.println(Arrays.toString(cnt[0]));
        
        int found[] = new int[n * m + 1];
        Arrays.fill(found, Integer.MAX_VALUE / 2);
        
        found[0] = 0;
        map = new TreeMap<Integer, Integer>();
        add(found[0]);
        
        for (int i = 1; i < found.length; i++) {
            if (i - d - 1 >= 0)
                rem(found[i - d - 1]);
            found[i] = cnt[0][i] > 0 ? map.firstKey() + 1 : found[i];
            add(found[i]);
        }
        
        for (int i = found.length - 1; i >= 0; i--) {
            if (found[i] < Integer.MAX_VALUE / 2) {
                w.println(i + " " + found[i]);
                break;
            }
        }
        
        w.close();
    }
    
    static void add(int x) {
        if (!map.containsKey(x))
            map.put(x, 0);
        map.put(x, map.get(x) + 1);
    }
    
    static void rem(int x) {
        map.put(x, map.get(x) - 1);
        if (map.get(x) == 0)
            map.remove(x);
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