import java.io.*;
import java.util.*;

public class B {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int[] cnt = new int[m];
        for (int i = 0; i < n; ++i) {
            char[] s = nextToken().toCharArray();
            for (int j = 0; j < m; ++j) {
                if (s[j] == 'U' && i % 2 == 0) {
                    ++cnt[j];
                }
                if (s[j] == 'L' && j - i >= 0) {
                    ++cnt[j - i];
                }
                if (s[j] == 'R' && j + i < m) {
                    ++cnt[j + i];
                }
            }
        }
        for (int i = 0; i < m; ++i)
            out.print(cnt[i] + " ");
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}