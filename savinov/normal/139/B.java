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
        int [] p = new int[n];
        int [] h = new int[n];
        for(int i = 0; i < n; ++i)
        {
            int l = in.readInt();
            int w = in.readInt();
            h[i] = in.readInt();
            p[i] = 2 * (l + w);
        }
        int m = in.readInt();
        int [] l = new int[m];
        int [] w = new int[m];
        int [] cost = new int[m];
        for(int i = 0; i < m; ++i)
        {
            l[i] = in.readInt();
            w[i] = in.readInt();
            cost[i] = in.readInt();
        }
        long ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int best = (int)1e9;
            for(int j = 0; j < m; ++j)
            {
                if (l[j] < h[i]) continue;
                int cnt = (p[i] + (w[j] * (l[j] / h[i])) - 1) / (w[j] * (l[j] / h[i]));
                best = Math.min(best, cnt * cost[j]);
            }
            ans += best;
        }
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