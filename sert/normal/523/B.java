import java.lang.*;
import java.util.*;
import java.io.*;

public class Problem {

    strictfp void solve() throws IOException {
        Locale.setDefault(new Locale("US"));
        int n = in.nextInt();
        int t = in.nextInt();
        double c = in.nextDouble();
        long[] re = new long[n + 1];
        double[] app = new double[n + 1];
        for (int i = 1; i <= n; ++i) {
            int a = in.nextInt();
            re[i] = re[i - 1] + a;
            app[i] = (app[i - 1] + a * 1. / t) / c;
        }
        int m = in.nextInt();
        for (int it = 0; it < m; ++it) {
            int p = in.nextInt();
            double real = re[p] - re[p - t];
            real /= t;
            double approx = app[p];
            double error = Math.abs(approx - real) / real;
            out.printf("%.12f %.12f %.12f\n", real, approx, error);
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