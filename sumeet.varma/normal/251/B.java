import java.io.*;
import java.util.*;

public class R153qB {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int k = in.nextInt();

        int q[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            q[i] = in.nextInt();

        int s[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            s[i] = in.nextInt();

        boolean isInit = true;
        for (int i = 1; i <= n; i++)
            isInit &= s[i] == i;

        int ahead[][] = new int[k + 1][n + 1];
        for (int i = 1; i <= n; i++)
            ahead[0][i] = i;
        
        int aheadCnt = 1;
        
        for (aheadCnt = 1; aheadCnt <= k; aheadCnt++) {
            int i = aheadCnt;
            boolean isInit2 = true;
            for (int j = 1; j <= n; j++) {
                ahead[i][j] = ahead[i - 1][q[j]];
                isInit2 &= ahead[i][j] == j;
            }
            if (isInit2) {
                aheadCnt--;
                break;
            }
        }
        aheadCnt = Math.min(aheadCnt, k);

        int back[][] = new int[k + 1][n + 1];
        for (int i = 1; i <= n; i++)
            back[0][i] = i;
        
        int backCnt = 1;
        
        for (backCnt = 1; backCnt <= k; backCnt++) {
            int i = backCnt;
            boolean isInit2 = true;
            for (int j = 1; j <= n; j++) {
                back[i][q[j]] = back[i - 1][j];
                isInit2 &= back[i][q[j]] == q[j];
            }
            if (isInit2) {
                backCnt--;
                break;
            }
        }
        backCnt = Math.min(backCnt, k);

        int aheadIdx = 10000000, backIdx = 1000000;
        for (int i = 1; i <= aheadCnt; i++) {
            boolean found = true;
            for (int j = 1; j <= n; j++)
                found &= ahead[i][j] == s[j];
            if (found) {
                aheadIdx = i;
                break;
            }
        }
        
        for (int i = 1; i <= backCnt; i++) {
            boolean found = true;
            for (int j = 1; j <= n; j++)
                found &= back[i][j] == s[j];
            if (found) {
                backIdx = i;
                break;
            }
        }
        
        boolean ans = aheadIdx <= k || backIdx <= k;
        ans &= !isInit;
        
        if (ans) {
            
            boolean ans1 = false;
            if (aheadIdx <= k) {
                int xtra = k - aheadIdx;
                if (xtra == 0)
                    ans1 = true;
                else if(backCnt == 0)
                    ans1 = true;
                else if (xtra % 2 == 0) {
                    ans1 |= aheadIdx >= 2;
                    ans1 |= backCnt >= 1 && backIdx > 1;
                }
            }
            
            boolean ans2 = false;
            if (backIdx <= k) {
                int xtra = k - backIdx;
                if (xtra == 0)
                    ans2 = true;
                else if(aheadCnt == 0)
                    ans2 = true;
                else if (xtra % 2 == 0) {
                    ans2 |= backIdx >= 2;
                    ans2 |= aheadCnt >= 1 && aheadIdx > 1;
                }
            }
            
            ans &= ans1 | ans2;
        }

        w.println(ans ? "YES" : "NO");
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