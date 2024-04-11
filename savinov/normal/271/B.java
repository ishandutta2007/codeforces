import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
import java.math.*;
import java.io.InputStream;

public class main
{
    private static boolean isPrime(int num) {
        boolean isPrime = true;
        for(int i = 2; i<num; i++) {
            if(num % i == 0) {
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }
    public static void main(String[] args)
    {
        InputReader in = new InputReader(System.in);
        //Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int M = 100100;
        boolean [] sieve = new boolean[M + 1];
        sieve[1] = true;
        for(int i = 2; i * i <= M; ++i)
        {
            if (!sieve[i])
            {
                for(int j = i * i; j <= M; j += i)
                    sieve[j] = true;
            }
        }

        int n = in.readInt();
        int m = in.readInt();

        int [] cnt1 = new int[n];
        int [] cnt2 = new int[m];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                int a = in.readInt();
                while(sieve[a])
                {
                    cnt1[i]++;
                    cnt2[j]++;
                    ++a;
                    //out.println(a);
                }
            }
        int ans = (int)1e9;
        for(int i = 0; i < n; ++i)
            ans = Math.min(ans, cnt1[i]);
        for(int i = 0; i < m; ++i)
            ans = Math.min(ans, cnt2[i]);

        out.println(ans);
        out.flush();

    }
}


class InputReader {

    private final InputStream stream;
    private final byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}