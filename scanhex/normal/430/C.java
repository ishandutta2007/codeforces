/**
 * Created by Alex on 11.05.14.
 */

import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {
    class Vertex {
        Vertex parent;
        ArrayList<Vertex> children;
        int num;
        int depth = 0;
        int changed = 0;
        int goal;

        Vertex(int num) {
            this.num = num;
            children = new ArrayList<Vertex>();
        }
    }

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

    Vertex[] graph;
    ArrayList<Integer>[] g;
    boolean[] used;
    ArrayList<Integer> ans;

    void buildGraph(int v) {
        used[v] = true;
        for (int u : g[v]) {
            if (used[u])
                continue;
            graph[u].parent = graph[v];
            graph[v].children.add(graph[u]);
            graph[u].depth = graph[v].depth + 1;
            buildGraph(u);
        }
    }


    void bfs() {
        ArrayDeque<Vertex> q = new ArrayDeque<Vertex>();
        q.push(graph[0]);
        while (q.size() > 0) {
            Vertex v = q.getFirst();
            q.removeFirst();
            if (v.changed % 2 != v.goal) {
                ++v.changed;
                ans.add(v.num);
            }
            for (Vertex u : v.children) {
                for (Vertex w : u.children)
                    w.changed = v.changed;
                q.addLast(u);
            }
        }
    }

    void printAns() {
        jout.println(ans.size());
        for (int i : ans)
            jout.println(i + 1);
    }

    public void solve() throws IOException {
        int n = nextInt();
        graph = new Vertex[n];
        g = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) graph[i] = new Vertex(i);
        for (int i = 0; i < n - 1; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        used = new boolean[n];
        buildGraph(0);
        int[] init = new int[n];
        for (int i = 0; i < n; ++i) {
            init[i] = nextInt();
        }
        for (int i = 0; i < n; ++i)
            graph[i].goal = nextInt() ^ init[i];
        ans = new ArrayList<Integer>();
        bfs();
        printAns();
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