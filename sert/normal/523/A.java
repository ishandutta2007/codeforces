import java.lang.*;
import java.util.*;
import java.io.*;

import static java.util.Arrays.copyOf;

public class Problem {

    void solve() throws IOException {
        int w = in.nextInt();
        int h = in.nextInt();
        char[][] a = new char[h][];
        for (int i = 0; i < h; ++i) {
            a[i] = in.nextToken().toCharArray();
        }
        char[][] b = new char[w][h];
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                b[j][h - 1 - i] = a[i][j];
            }
        }
        char[][] c = new char[w][h];
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                c[i][j] = b[i][h - 1 - j];
            }
        }
        char[][] d = new char[w + w][h + h];
        for (int i = 0; i < w + w; ++i) {
            for (int j = 0; j < h + h; ++j) {
                d[i][j] = c[i / 2][j / 2];
            }
        }
        for (int i = 0; i < w + w; ++i) {
            out.println(d[i]);
        }
    }

    static FastReader in;
    static PrintWriter out;
    static PrintStream err;

    public static void main(String[] args) throws IOException {
        try {
            in = new FastReader();
            out = new PrintWriter(System.out);
            err = System.err;
            new Problem().solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

}

class FastReader {
    private StringTokenizer st;
    private BufferedReader br;

    public FastReader() {
        this(System.in);
    }

    public FastReader(InputStream ps) {
        br = new BufferedReader(new InputStreamReader(ps));
    }

    public FastReader(String filename) throws FileNotFoundException {
        this(new FileInputStream(filename));
    }

    public String nextToken() throws IOException {
        while (st == null || !st.hasMoreElements()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}