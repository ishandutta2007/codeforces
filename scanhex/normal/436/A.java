import java.io.*;
import java.util.*;

public class A {
    class Candy {
        int h, m;
        boolean type;

        Candy(boolean type, int h, int m) {
            this.h = h;
            this.m = m;
            this.type = type;
        }

    }

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
        Candy[] c = new Candy[n];
        ArrayList<Candy>[] cc = new ArrayList[2];
        cc[0] = new ArrayList<Candy>();
        cc[1] = new ArrayList<Candy>();
        for (int i = 0; i < n; ++i) {
            int a = nextInt();
            c[i] = new Candy(a == 1, nextInt(), nextInt());
            cc[a].add(c[i]);
        }
        HashSet<Candy>[] d = new HashSet[2];
        int[] cnt = new int[2];
        int h = x;
        for (int t = 0; t < 2; ++t) {
            d[0] = new HashSet<Candy>(cc[0]);
            d[1] = new HashSet<Candy>(cc[1]);
            h = x;
            for (int i = 0; i < n; ++i) {
                int max = -1;
                Candy maxi = null;
                for (Candy can : d[(i + t) % 2])
                    if (can.h <= h && can.m > max) {
                        max = can.m;
                        maxi = can;
                    }
                if (maxi == null) {
                    cnt[t] = i;
                    break;
                }
                h += maxi.m;
                d[(i + t) % 2].remove(maxi);
                if (i == n - 1)
                    cnt[t] = n;
            }
        }
        out.print(Math.max(cnt[0], cnt[1]));
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