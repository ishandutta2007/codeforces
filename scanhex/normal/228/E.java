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
        for (int u : graph[v])
            dfs(u, c);
    }
    public void solve() throws IOException {
        int n = nextInt();
        used = new boolean[n * 2];
        graph = new ArrayList[n * 2];
        out1 = new int[n * 2];
        graph1 = new ArrayList[n * 2];
        out = new int[n * 2];
        comps = new ArrayList<ArrayList<Integer>>();
        comp = new int[n * 2];
        for (int i = 0; i < n * 2; ++i) {
            graph[i] = new ArrayList<Integer>();
        }
        int m = nextInt();
        for (int i = 0; i < m; ++i) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            int state = nextInt();
            if (state == 1) {
                graph[u + n].add(v + n);
                graph[v + n].add(u + n);
                graph[u].add(v);
                graph[v].add(u);
                /*graph1[u * 2].add(v * 2);
                graph1[v * 2].add(u * 2);
                graph1[u].add(v);
                graph1[v].add(u);*/
            } else {
                graph[u + n].add(v);
                graph[v].add(u + n);
                graph[u].add(v + n);
                graph[v + n].add(u);
            }
        }
        for (int i = 0; i < n * 2; ++i)
            ts(i);
        used = new boolean[n * 2];
        int cnt = 0;
        for (int i = (n * 2) - 1; i >= 0 ; --i)
            if (!used[out1[i]]) {
                comps.add(new ArrayList<Integer>());
                dfs(out1[i], cnt++);
            }
        for (int i = 0; i < n; ++i) {
            if (comp[i] == comp[i + n]) {
                jout.println("Impossible");
                return;
            }
        }
        used = new boolean[n * 2];
        boolean[] val = new boolean[n];
        ArrayList<Integer>[] c = comps.toArray(new ArrayList[cnt]);
        for (int i = cnt - 1; i >= 0; --i) {
            if (used[c[i].get(0)])
                continue;
            for (int j : c[i]) {
                if (j < n) {
                    val[j] = true;
                    used[j + n] = true;
                } else {
                    val[j - n] = false;
                    used[j - n] = true;
                }
            }
        }
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i)
            if (val[i])
                ans.add(i);
        jout.println(ans.size());
        for (int i : ans)
            jout.print(i + 1 + " ");
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