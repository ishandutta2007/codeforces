/**
 * Created by Alex on 15.05.14.
 */

import java.io.*;
import java.util.*;

public class C {
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
        new C().run();
    }

    ArrayList<Integer>[] graph;
    ArrayList<Integer>[] graph1;
    ArrayList<ArrayList<Integer>> comps;
    int[] comp;
    long[] cost;
    int[] out1;
    int[] out;
    int t = 0;
    boolean[] used;

    void ts(int v) {
        if (used[v])
            return;
        used[v] = true;
        for (int u : graph[v])
            ts(u);
        out1[t] = v;
        out[v] = t++;
    }

    void dfs(int v, int c) {
        if (used[v])
            return;
        used[v] = true;
        comp[v] = c;
        comps.get(c).add(v);
        for (int u : graph1[v])
            dfs(u, c);
    }
    public void solve() throws IOException {
        int n = nextInt();
        cost = new long[n];
        used = new boolean[n];
        graph = new ArrayList[n];
        out1 = new int[n];
        graph1 = new ArrayList[n];
        out = new int[n];
        comps = new ArrayList<ArrayList<Integer>>();
        comp = new int[n];
        for (int i = 0; i < n; ++i) {
            cost[i] = nextLong();
            graph[i] = new ArrayList<Integer>();
            graph1[i] = new ArrayList<Integer>();
        }
        int m = nextInt();
        for (int i = 0; i < m; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            graph[a].add(b);
            graph1[b].add(a);
        }
        for (int i = 0; i < n; ++i)
            ts(i);
        used = new boolean[n];
        int cnt = 0;
        for (int i = n - 1; i >= 0 ; --i)
            if (!used[out1[i]]) {
                comps.add(new ArrayList<Integer>());
                dfs(out1[i], cnt++);
            }
        ArrayList<Integer>[] c = comps.toArray(new ArrayList[cnt]);
        long prod = 1;
        int MOD = (int)(1e9 + 7);
        long ans = 0;
        for (int i = 0; i < cnt; ++i) {
            long min = Long.MAX_VALUE;
            int h = 0;
            for (int j = 0; j < c[i].size(); ++j) {
                long g = cost[c[i].get(j)];
                if (g == min)
                    ++h;
                if (g < min) {
                    h = 1;
                    min = g;
                }
            }
            ans += min;
            prod *= h;
            prod %= MOD;
        }
        jout.println(ans + " " + prod);
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