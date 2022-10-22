/**
 * Created by Alex on 10/20/2014.
 */

import java.io.*;
import java.util.*;

public class B33 {
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
        new B33().run();
    }

    final int INF = Integer.MAX_VALUE / 2;

    public void solve() throws IOException {
        char[] s1 = nextToken().toCharArray();
        char[] s2 = nextToken().toCharArray();
        if (s1.length != s2.length) {
            out.print(-1);
            return;
        }
        int[][] d = new int[26][26];
        for (int i = 0; i < 26; ++i)
            Arrays.fill(d[i], INF);
        int n = nextInt();
        for (int i = 0; i < n; ++i) {
            int a = nextToken().charAt(0) - 'a';
            int b = nextToken().charAt(0) - 'a';
            int w = nextInt();
            d[a][b] = Math.min(d[a][b], w);
        }
        for (int i = 0; i < 26; ++i)
            d[i][i] = 0;
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
        int ans = 0;
        char[] anss = new char[s1.length];
        for (int i = 0; i < s1.length; ++i) {
            s1[i] -= 'a';
            s2[i] -= 'a';
            int min = INF;
            char mini = 0;
            for (int j = 0; j < 26; ++j) {
                if (d[s1[i]][j] + d[s2[i]][j] < min) {
                    min = d[s1[i]][j] + d[s2[i]][j];
                    mini = (char) (j + 'a');
                }
            }
            if (min < INF) {
                ans += min;
                anss[i] = mini;
            } else {
                out.print(-1);
                return;
            }
        }
        out.println(ans);
        out.println(new String(anss));
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