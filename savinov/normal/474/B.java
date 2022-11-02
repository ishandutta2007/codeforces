import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static boolean home = true;

    static int [] rotate(int [] a, int [] b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];

        int [] res = new int[2];
        res[0] = b[0] - dy;
        res[1] = b[1] + dx;

        return res;
    }


    public static void main(String[] args) throws FileNotFoundException {
        InputStream is = home ? System.in : new FileInputStream("decoding.in");
        InputReader in = new InputReader(is);

        OutputStream os = home ? System.out : new FileOutputStream("decoding.out");
        PrintWriter out = new PrintWriter(os);

        int n = in.nextInt();

        int N = 1000000;

        int [] which = new int[N + 1];

        int x = 1;

        for (int i = 0; i < n; ++i) {
            int a = in.nextInt();
            while (a-- > 0) {
                which[x++] = i;
            }
        }

        int m = in.nextInt();

        while (m-- > 0) {
            int q = in.nextInt();
            out.println(which[q] + 1);
        }

        out.close();
    }

    private static int gcd(int a, int b) {
        while (b > 0) {
            a %= b;
            a ^= b;
            b ^= a;
            a ^= b;
        }
        return a;
    }

}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}