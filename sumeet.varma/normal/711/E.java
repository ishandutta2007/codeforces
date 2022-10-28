import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class R369qE {

    static long mod = (long) 1e6 + 3;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        // while (true) {
        long k = in.nextLong();
        long n = in.nextLong();

        long oth = 1;
        for (int i = 1; i <= k; i++) {
            oth *= 2;
            if (oth >= n)
                break;
        }

        if (n > oth) {
            System.out.println("1 1");
            return;
        }

        BigInteger max = BigInteger.valueOf(k);

        long _2 = 2;
        while (_2 < n) {
            max = max.add(BigInteger.valueOf((n - 1) / _2));
            _2 *= 2;
        }

        long gcd = powBig(2, max);
        // System.out.println(gcd);

        long den = powBig(2, BigInteger.valueOf(n).multiply(BigInteger.valueOf(k)));
        // System.out.println(den);

        long numTemp = 0; // n! * C(2^k, n)
        if (n < mod) {
            numTemp = 1 % mod;
            long pro = pow(2, k);
            for (int i = 0; i < n; i++) {
                numTemp *= pro;
                numTemp %= mod;
                pro--;
                if (pro < 0)
                    pro += mod;
            }
        }

        long num = den - numTemp;
        num %= mod;
        if (num < 0)
            num += mod;

        // System.out.println(gcd(num, den) + " " + gcd);
        den *= pow(gcd, mod - 2);
        den %= mod;

        num *= pow(gcd, mod - 2);
        num %= mod;

        w.println(num + " " + den);
        w.close();
    }

    public static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    private static long pow(long a, long b) {
        if (b == 0)
            return 1 % mod;
        long t = pow(a, b >> 1);
        t = (t * t) % mod;
        if ((b & 1) != 0)
            t = (t * a) % mod;
        return t;
    }

    private static long powBig(long a, BigInteger b) {
        if (b.equals(BigInteger.ZERO))
            return 1 % mod;
        long t = powBig(a, b.divide(BigInteger.valueOf(2)));
        t = (t * t) % mod;
        if (b.remainder(BigInteger.valueOf(2)).equals(BigInteger.ONE))
            t = (t * a) % mod;
        return t;
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