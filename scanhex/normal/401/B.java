/**
 * Created by Alex on 10.03.14.
 */

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
        int x = nextInt();
        int k = nextInt();
        boolean[] arr = new boolean[x];
        arr[x - 1] = true;
        int cnt1 = 0;
        int cnt2 = 0;
        int min = 0;
        for (int i = 0; i < k; i++) {
            int t = nextInt();
            if (t == 1) {
                int num1 = nextInt() - 1;
                int num2 = nextInt() - 1;
                arr[num1] = true;
                arr[num2] = true;
                cnt1 += 2;
            } else {
                int num = nextInt() - 1;
                arr[num] = true;
                ++cnt2;
            }
        }
        int cur = -1;
        for (int i = 0; i < x; i++) {
            if (arr[i]) {
                min += (i - cur) / 2;
                cur = i;
            }
        }
        // (x - was + 1) / 2;
        int was = 1 + cnt1 + cnt2;
        int max = x - was;
        out.print(min + " " + max);
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