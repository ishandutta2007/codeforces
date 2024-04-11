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

        String [] s = new String[]{"qwertyuiop",
                                   "asdfghjkl;",
                                   "zxcvbnm,./"};
        int [] x = new int[256];
        int [] y = new int[256];

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < s[i].length(); ++j) {
                x[s[i].charAt(j)] = i;
                y[s[i].charAt(j)] = j;
            }
        }

        String v = in.next();

        String d = in.next();

        for (int i = 0; i < d.length(); ++i) {
            if (v.equals("L")) {
                out.print(s[x[d.charAt(i)]].charAt(y[d.charAt(i)] + 1));
            } else {
                out.print(s[x[d.charAt(i)]].charAt(y[d.charAt(i)] - 1));
            }
        }
        out.println();
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