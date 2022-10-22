/**
 * Created by Alex on 9/22/2014.
 */

import java.io.*;
import java.util.*;

public class B269 {
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
        new B269().run();
    }

    public int max(int[] a) {
        int[] d = new int[a.length];
        Arrays.fill(d, 1);
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] <= a[i] && d[j] + 1 > d[i])
                    d[i] = d[j] + 1;
            }
        }
        return Arrays.stream(d).max().getAsInt();
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
        {
            a[i] = nextInt();
            nextToken();
        }
        out.print(a.length - max(a));
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