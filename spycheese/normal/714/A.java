import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException
	{
		long l1 = in.nextLong();
		long r1 = in.nextLong();
		long l2 = in.nextLong();
		long r2 = in.nextLong();
		long k = in.nextLong();
		long l = Math.max(l1, l2), r = Math.min(r1, r2);
		out.println(Math.max(r - l + 1, 0) + (l <= k && k <= r ? -1 : 0));
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] arg) {
        new A().run();
    }
}