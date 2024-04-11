import java.io.*;
import java.util.*;

public class HelveticqD {

    static int Mx = -1, mx = 1;
    static int My = -1, my = 1;
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        
        char s[][] = new char[n][n];
        for (int i = 0; i < n; i++)
            s[i] = in.readString().toCharArray();
        
        Mx = -1; mx = n + 1;
        My = -1; my = n + 1;
        
        boolean f = false;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '4') {
                    
                    Mx = Math.max(Mx, i);
                    mx = Math.min(mx, i);

                    My = Math.max(My, j);
                    my = Math.min(my, j);
                    
                    f = true;
                }
            }
        }
        
        if (!f) {
            System.out.println("No");
            return;
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                if (g(i - 1,j) || g(i, j) || g(i - 1,j + 1) || g(i, j + 1))
                    cnt++;
                if (g(i, j) || g(i + 1, j) || g(i, j + 1) || g(i + 1, j + 1))
                    cnt++;
                if (g(i - 1,j) || g(i, j) || g(i - 1,j - 1) || g(i, j - 1))
                    cnt++;
                if (g(i, j) || g(i + 1, j) || g(i, j - 1) || g(i + 1, j - 1))
                    cnt++;
                f &= s[i][j] == (char)('0' + cnt);
            }
        }
        
        w.println(f ? "Yes" : "No");
        w.close();
    }

    static boolean g(int x, int y) {
        return x >= mx && x <= Mx && y >= my && y <= My;
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