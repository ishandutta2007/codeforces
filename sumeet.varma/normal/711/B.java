import java.io.*;
import java.util.*;

public class R369qB {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        
        if (n == 1) {
            System.out.println(1);
            return;
        }
        
        long a[][] = new long[n][n];
        long sum[] = new long[n];
        int I = -1, J = -1;
        
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {
                a[i][j] = in.nextInt();
                sum[i] += a[i][j];
                if (a[i][j] == 0) {
                    I = i;
                    J = j;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (I != i) {
                a[I][J] = sum[i] - sum[I];
                if (a[I][J] <= 0) {
                    System.out.println(-1);
                    return;
                }
            }
        }
        
        long x = 0;
        for (long y : a[0])
            x += y;
        
        for (int i = 0; i < n; i++) {
            long now = 0;
            for (long y : a[i])
                now += y;
            if (now != x) {
                System.out.println(-1);
                return;
            }
            now = 0;
            for (int j = 0; j < n; j++) {
                now += a[j][i];
            }
            if (now != x) {
                System.out.println(-1);
                return;
            }
        }
        
        long A = 0, B = 0;
        for (int i = 0; i < n; i++) {
            A += a[i][i];
            B += a[i][n - 1 - i];
        }
        
        if (A != x || B != x) {
            System.out.println(-1);
            return;
        }
        
        w.println(a[I][J]);  
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