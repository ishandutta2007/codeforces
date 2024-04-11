import java.io.*;
import java.util.*;

public class R114qC {

    static boolean dp[][];
    static boolean dn[][];
    static long A[], B[];
    static int ptr = 0;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        /*dp = new boolean[101][101];
        dn = new boolean[101][101];

        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                w.print((rec(i, j) ? 1 : 0) + " ");
            }
            w.println();
        }*/

        /*  //rec(2, 1);
          w.println();
          w.println();
          w.println();
          
          for (int i = 1; i <= 10; i++) {
              for (int j = 1; j <= 10; j++) {
                  w.print(gcd(i, j) + " ");
              }
              w.println();
          }
          */
        
        int t = in.nextInt();
        
        A = new long[500];
        B = new long[500];
        boolean[] dp = new boolean[500];
        
        while (t-- > 0) {
            long a = in.nextLong();
            long b = in.nextLong();

            ptr = 0;

            gcd(Math.min(a, b), Math.max(a, b));
            /*for (int i = 0; i < ptr; i++) {
                w.println(A[i] + " " + B[i]);
            }
            w.flush();
            */
            
            dp[ptr - 1] = false;
            for (int i = ptr - 2; i >= 0; i--) {
                if (!dp[i + 1])
                    dp[i] = true;
                else {
                   // System.out.println("I " + i);
                    long n = B[i] / A[i];
                    dp[i] = get(n, A[i]);
                }
            }
            
            w.println(dp[0] ? "First" : "Second");
        }

        w.close();
    }

    public static boolean get(long n, long a) {
        if (a % 2 == 1)
            return n % 2 == 0;
        else {
            n %= (a + 1);
            return n % 2 == 0;
        }
    }
    
    public static long gcd(long a, long b) {

        while (a != 0) {
            A[ptr] = a;
            B[ptr++] = b;
            long t = a;
            a = b % a;
            b = t;
        }

        A[ptr] = a;
        B[ptr++] = b;

        return b;
    }

    public static int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    static boolean rec(int a, int b) {
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        if (dn[a][b])
            return dp[a][b];
        dn[a][b] = true;
        if (a == 0)
            dp[a][b] = true;
        else {
            boolean ans = false;
            ans |= !rec(a, b % a);
            int pro = a;
            while (pro <= b) {
                ans |= !rec(a, b - pro);
                pro *= a;
                if (a == 1)
                    break;
            }
            dp[a][b] = ans;
        }
        return dp[a][b];
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