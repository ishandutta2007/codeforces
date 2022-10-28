import java.io.*;
import java.util.*;

public class AimTech3qB {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        long a[][] = new long[2][2];
        //long a[][] = rand();
        
        long sum = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = in.nextInt();
                sum += a[i][j];
            }
        }

        if (sum == 0) {
            System.out.println("0");
            return;
        }

        if (sum == 1) {
            if (a[0][0] == 1)
                System.out.println("00");
            else if (a[0][1] == 1)
                System.out.println("01");
            else if (a[1][0] == 1)
                System.out.println("10");
            else
                System.out.println("11");
            return;
        }
        
        String I = "Impossible";

        // n * (n - 1) / 2 = sum
        long n = get(sum);
        long z = get(a[0][0]);
        long o = get(a[1][1]);
        
      
        if (n == -1 || z == -1 || o == -1) {
            w.println(I);
            w.close();
            return;
        }
        
        if (z + o != n) {
            if (z == 0)
                z++;
        }
        
        if (z + o != n) {
            if (o == 0)
                o++;
        }
        
        if (z + o != n) {
            w.println(I);
            w.close();
            return;
        }
      
        long t = z * o;
        if (a[0][1] + a[1][0] != t) {
            w.println(I);
            w.close();
            return;
        }

        int ans[] = new int[(int) n];

        for (int i = 0; i < n; i++) {
            if (a[0][1] >= o && z > 0) {
                ans[i] = 0;
                a[0][1] -= o;
                z--;
            }
            else if (a[1][0] >= z && o > 0) {
                ans[i] = 1;
                a[1][0] -= z;
                o--;
            }
            else {
                w.println(I);
                w.close();
                return;
            }
        }
        
        for (int i = 0; i < n; i++)
            w.print(ans[i]);

        w.close();
    }
    
    static long[][] rand() {
        int n = 5;
        int c[] = new int[2];
        long a[][] = new long[2][2];
        for (int i = 0; i < n; i++) {
            int x = new Random().nextInt(2);
            a[x][x] += c[x];
            a[1 - x][x] += c[1 - x];
            c[x]++;
        }
        return a;
    }

    static long get(long sum) {
        if (sum == 0)
            return 0;
        long S = Math.round(Math.sqrt(1 + 8 * sum));

        if ((S - 1) * (S - 1) == 1 + 8 * sum)
            S--;

        if ((S + 1) * (S + 1) == 1 + 8 * sum)
            S++;

        if (S * S != 1 + 8 * sum || (1 + S) % 2 != 0)
            return -1;

        long n = (1 + S) / 2;
        return n;
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