/**
 * Created by Alex on 19.05.14.
 */

import java.io.*;
import java.util.*;

public class C368 {
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
        new C368().run();
    }

    int[][] cnt;

    int cnt(int L, int R, int let) {
        return cnt[R][let] - cnt[L][let];
    }

    public void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        int m = nextInt();
        cnt = new int[s.length + 1][3];
        for (int i = 1; i <= s.length; ++i) {
            cnt[i][0] = cnt[i - 1][0] + (s[i - 1] == 'x' ? 1 : 0);
            cnt[i][1] = cnt[i - 1][1] + (s[i - 1] == 'y' ? 1 : 0);
            cnt[i][2] = cnt[i - 1][2] + (s[i - 1] == 'z' ? 1 : 0);
        }
        for (int i = 0; i < m; ++i) {
            int l = nextInt() - 1;
            int r = nextInt() - 1;
            if (r - l + 1 < 3) {
                jout.println("YES");
                continue;
            }
            int c1 = cnt(l, r + 1, 0);
            int c2 = cnt(l, r + 1, 1);
            int c3 = cnt(l, r + 1, 2);
            if (Math.abs(c1 - c2) <= 1 && Math.abs(c2 - c3) <= 1 && Math.abs(c3 - c1) <= 1)
                jout.println("YES");
            else
                jout.println("NO");
        }
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