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

    int[] reverse(int x, int y, int n, int m) {
        int x1 = x;
        int y1 = m - 1 - y;
        return new int[]{x1, y1};
    }

    int[] rotate90(int x, int y, int n, int m) {
        int x1 = y;
        int y1 = n - x - 1;
        return new int[]{x1, y1};
    }
    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int x1 = nextInt();
        int y1 = nextInt();
        int z = nextInt();
        int p = nextInt();
        int[] x = new int[p];
        int[] y = new int[p];
        for (int i = 0; i < p; i++) {
            x[i] = nextInt() - 1;
            y[i] = nextInt() - 1;
        }
        for (int i = 0; i < x1 % 4; i++) {
            for (int j = 0; j < p; j++) {
                int[] c = rotate90(x[j], y[j], n, m);
                x[j] = c[0];
                y[j] = c[1];
            }
            int t = m;
            m = n;
            n = t;
        }
        if (y1 % 2 == 1) {
            for (int i = 0; i < p; i++) {
                int[] c = reverse(x[i], y[i], n, m);
                x[i] = c[0];
                y[i] = c[1];
            }
        }
        for (int i = 0; i < 4 - z % 4; i++) {
            for (int j = 0; j < p; j++) {
                int[] c = rotate90(x[j], y[j], n, m);
                x[j] = c[0];
                y[j] = c[1];
            }
            int t = m;
            m = n;
            n = t;
        }
        for (int i = 0; i < p; i++) {
            out.println((x[i] + 1) + " " + (y[i] + 1));
        }
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