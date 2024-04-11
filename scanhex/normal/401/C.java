/**
 * Created by Alex on 10.03.14.
 */

import java.io.*;
import java.util.*;

public class C {
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
        new C().run();
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        if (n - m > 1 || m - 2 * n > 2) {
            out.print(-1);
            out.close();
            System.exit(0);
        }
        int a = m % n;
        int b = n - a;
        if (n - m == 1) {
            a = 0;
            b = m;
        }
        if (m >= 2 * n) {
            a = n;// + m % n;
            b = 0;
        }

        if (n - m == 1) out.print("0");
        for (int i = 0; i < a; i++) {
            out.print("110");
        }
        for (int i = 0; i < b; i++) {
            out.print("10");
        }
        if (m - 2 * n == 1) out.print("1");
        if (m - 2 * n == 2) out.print("11");
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