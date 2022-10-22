/**
 * Created by Alex on 10.03.14.
 */

import java.io.*;
import java.util.*;

public class A {
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
        new A().run();
    }

    public void solve() throws IOException {
        int n = nextInt();
        int x = nextInt();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nextInt();
        out.print(Math.abs(sum >= 0 ? (sum + x - 1) / x : (sum - x + 1) / x));
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