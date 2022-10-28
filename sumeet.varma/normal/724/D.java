import java.io.*;
import java.util.*;

public class IntelqD {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int m = in.nextInt();
        
        char s[] = in.readString().toCharArray();
        int n = s.length;
        
        /*int n = (int)1e5;
        char s[] = new char[n];
        for (int i = 0; i < n; i++)
            s[i] = (char)('a' + new Random().ne)
        */
        
        int cnt[] = new int[26];
        for (char x : s)
            cnt[x - 'a']++;
        
        for (char x = 'a'; x <= 'z'; x++) {
            boolean done = true;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += s[i] <= x ? 1 : 0;
                if (i >= m)
                    sum -= s[i - m] <= x ? 1 : 0;
                if (i >= m - 1)
                    done &= sum > 0;
            }
            if (!done) {
                for (int j = 0; j < cnt[x - 'a']; j++)
                    w.print(x);
            }
            else {
                boolean sel[] = new boolean[n];
                int add = 0;
                sum = 0;
                int lastPro = -1;
                
                for (int j = 0; j < n; j++) {
                    sum += s[j] < x ? 1 : 0;
                    if (j >= m)
                        sum -= (sel[j - m] || (s[j - m] < x)) ? 1 : 0;
                    if (s[j] == x)
                        lastPro = j;
                    if (j >= m - 1 && sum == 0) {
                        sum++;
                        sel[lastPro] = true;
                        add++;
                    }
                }
                
                for (int j = 0; j < add; j++)
                    w.print(x);
                break;
            }
        }
        
        w.println();
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