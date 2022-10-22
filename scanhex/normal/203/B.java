/**
 * Created by Alex on 12.05.14.
 */

import java.io.*;
import java.util.*;

public class B203 {
    BufferedReader br;
    StringTokenizer jin;
    PrintWriter jout;

    public String nextToken() throws IOException {
        while (jin == null || !jin.hasMoreTokens()) {
            jin = new StringTokenizer(br.readLine());
        }
        return jin.nextToken();
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
        new B203().run();
    }

    public void solve() throws IOException {
        int n = nextInt();
        boolean[][] map = new boolean[n][n];
        int m = nextInt();
        for (int i = 0; i < m; ++i) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            map[x][y] = true;
            for (int x1 = x - 2; x1 <= x; ++x1)
                for (int y1 = y - 2; y1 <= y; ++y1) {
                    boolean flag = true;
                    if (x1 < 0 || x1 > n - 3 || y1 < 0 || y1 > n - 3)
                        continue;
                    for (int x2 = 0; x2 < 3; ++x2)
                        for (int y2 = 0; y2 < 3; ++y2) {
                            if (!map[x1 + x2][y1 + y2])
                                flag = false;
                        }
                    if (flag) {
                        jout.print(i + 1);
                        return;
                    }
                }
        }
        jout.print(-1);
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            jout = new PrintWriter(System.out);

            solve();

            jout.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}