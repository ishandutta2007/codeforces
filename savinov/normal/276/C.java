import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
import java.math.*;
import java.io.InputStream;

public class main
{

    public static void main(String[] args)
    {
        InputReader in = new InputReader(System.in);
        //Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.readInt();
        int q = in.readInt();

        long [] a = new long[n];

        long [] add = new long[n + 1];

        long [] cnt = new long[n];

        for(int i = 0; i < n; ++i)
            a[i] = in.readInt();

        for(int i = 0; i < q; ++i)
        {
            int l = in.readInt() - 1;
            int r = in.readInt();
            add[l]++;
            add[r]--;
        }
        int cur = 0;
        for(int i = 0; i < n; ++i)
        {
            cur += add[i];
            cnt[i] = cur;
        }
        Arrays.sort(cnt);
        Arrays.sort(a);
        long ans = 0;
        for(int i = 0; i < n; ++i)
            ans += a[i] * cnt[i];
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