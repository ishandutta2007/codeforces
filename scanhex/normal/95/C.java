/**
 * Created by Alex on 3/26/14.
 */

import java.io.*;
import java.util.*;

public class C95 {
    class Edge {
        long w;
        int t;

        Edge(int t, long w) {
            this.w = w;
            this.t = t;
        }

    }

    class Vertex implements Comparable {
        long w;
        int v;

        Vertex(long w, int v) {
            this.w = w;
            this.v = v;
        }


        @Override
        public int compareTo(Object o) {
            Vertex v1 = (Vertex) o;
            if (w > v1.w) return 1;
            if (w < v1.w) return -1;
            return v - v1.v;
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
        new C95().run();
    }

    int[] prev;

    void printPath() {
        int v = prev.length - 1;
        ArrayList<Integer> ans = new ArrayList<>();
        while (v != 0) {
            ans.add(v);
            v = prev[v];
        }
        ans.add(0);
        Collections.reverse(ans);
        for (int x : ans) {
            out.print(x + 1 + " ");
        }
    }

    ArrayList<Edge>[] graph;

    long[] dijkstra(ArrayList<Edge>[] graph, int s) {
        int n = graph.length;
        long[] d = new long[n];
        for (int i = 0; i < n; ++i)
            d[i] = Long.MAX_VALUE / 2;
        d[s] = 0;
        prev = new int[n];
        TreeSet<Vertex> gray = new TreeSet<>();
        gray.add(new Vertex(0, s));
        while (gray.size() > 0) {
            int v = gray.pollFirst().v;
            for (Edge e : graph[v]) {
                if (d[e.t] > d[v] + e.w) {
                    gray.remove(new Vertex(d[e.t], e.t));
                    d[e.t] = d[v] + e.w;
                    prev[e.t] = v;
                    gray.add(new Vertex(d[e.t], e.t));
                }
            }
        }
        return d;
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int s = nextInt() - 1;
        int f = nextInt() - 1;
        graph = new ArrayList[n];
        for (int i = 0; i < n; ++i) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            long c = nextLong();
            graph[a].add(new Edge(b, c));
            graph[b].add(new Edge(a, c));
        }

        int[] t = new int[n], c = new int[n];
        for (int i = 0; i < n; ++i) {
            t[i] = nextInt();
            c[i] = nextInt();
        }
        ArrayList<Edge>[] graph1 = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            graph1[i] = new ArrayList<>();
            long[] d = dijkstra(graph, i);
            for (int j = 0; j < n; ++j)
                if (d[j] <= t[i])
                    graph1[i].add(new Edge(j, c[i]));
            graph1[i].add(new Edge(i, 0));
        }
        long[] d = dijkstra(graph1, s);
        if (d[f] == Long.MAX_VALUE / 2)
            out.print(-1);
        else
            out.print(d[f]);

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