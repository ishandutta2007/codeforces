import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class R362qC {

    static int A[][] = {{ 1, 2 }, { 1, 0 }};
    static int B[][] = {{ 1, 2 }, { 1, 0 }};
    static final int mod = (int)1e9 + 7;
    static int C[][] = new int[2][2];
    
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        
        /*F a[] = new F[3];
        a[0] = new F(BigInteger.ZERO, BigInteger.ONE);
        a[1] = new F(BigInteger.ONE, BigInteger.ONE);
        a[2] = new F(BigInteger.ZERO, BigInteger.ONE);
        
        for (int i = 1; i <= n; i++) {
            F b[] = new F[3];
            b[0] = a[0].add(a[1]);
            b[1] = a[0].add(a[2]);
            b[2] = a[1].add(a[2]);
            System.out.println(Arrays.deepToString(b));
            a = Arrays.copyOf(b, 3);
        }
        
       // System.out.println(Arrays.toString(a));
        
        */
        
        //long start = System.currentTimeMillis();
        long bb = 2;
        
        for (int i = 0; i < n; i++) {
            long x = in.nextLong();//(1L << 58) - 1;
            bb = pow(B, bb, x);
            A[0][0] = B[0][0];
            A[0][1] = B[0][1];
            A[1][0] = B[1][0];
            A[1][1] = B[1][1];
        }
        
        bb *= pow(2, mod - 2);
        bb %= mod;
        
        long num = B[1][1] * 1L * pow(2, mod - 2);
        num %= mod;
        
        w.println(num + "/" + bb);
        //System.out.println(System.currentTimeMillis() - start);
        w.close();
    }
    
    static long pow(long a, long n) {
        if (n == 0)
            return 1;
        long t = pow(a, n >> 1);
        t = (t * t) % mod;
        if ((n & 1) != 0)
            t = (t * a) % mod;
        return t;
    }
    
    /*static long pow(int B[][], long a, long n) {
        if (n <= 1)
            return n == 1 ? a : 1;
        long t = pow(B, a, n >> 1);
        mul(B, B);
        t = (t * t) % mod;
        if ( (n & 1) != 0) {
            mul(B, A);
            t = (t * a) % mod;
        }
        return t;
    }*/
    
    static long pow(int B[][], long a, long n) {
        long ans = 1;
        int ans2[][] = new int[2][2];
        ans2[0][0] = ans2[1][1] = 1;
        while (n > 0) {
            if ((n & 1) != 0) {
                ans = (ans * a) % mod;
                mul(ans2, B);
            }
            mul(B, B);
            a = (a * a) % mod;
            n >>= 1;
        }
        B[0][0] = ans2[0][0];
        B[0][1] = ans2[0][1];
        B[1][0] = ans2[1][0];
        B[1][1] = ans2[1][1];
        return ans;
    }
    
    static void mul(int B[][], int A[][]) {
        //int C[][] = new int[2][2];
        C[0][0] = (int)((B[0][0] * 1L * A[0][0] + B[0][1] * 1L * A[1][0]) % mod);
        C[0][1] = (int)((B[0][0] * 1L * A[0][1] + B[0][1] * 1L * A[1][1]) % mod);
        C[1][0] = (int)((B[1][0] * 1L * A[0][0] + B[1][1] * 1L * A[1][0]) % mod);
        C[1][1] = (int)((B[1][0] * 1L * A[0][1] + B[1][1] * 1L * A[1][1]) % mod);
        B[0][0] = C[0][0];
        B[0][1] = C[0][1];
        B[1][0] = C[1][0];
        B[1][1] = C[1][1]; 
    }
    
    /*static void mul(int B[][], int A[][]) {
        long C[][] = new long[2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    C[i][k] += B[i][j] * 1L * A[j][k];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                B[i][j] = (int)(C[i][j] % mod);
    }*/
    
    static class F {
        BigInteger n, d;
        F(BigInteger n, BigInteger d) {
            this.n = n;
            this.d = d;
        }
        F add(F o) {
            BigInteger num = n.multiply(o.d).add(o.n.multiply(d));
            BigInteger den = d.multiply(o.d).multiply(BigInteger.ONE.add(BigInteger.ONE));
            BigInteger gcd = num.gcd(den);
            num = num.divide(gcd);
            den = den.divide(gcd);
            return new F(num, den);
        }
        public String toString() {
            return n + "/" + d;
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
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res;
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