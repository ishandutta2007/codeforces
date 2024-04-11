import java.io.*;
import java.util.*;

public class C {
    class Edge implements Comparable<Edge> {
        int i, j, w;

        @Override
        public int compareTo(Edge o) {
            return w - o.w;
        }

        Edge(int i, int j, int w) {
            this.i = i;
            this.j = j;
            this.w = w;
        }
    }

    class Answer {
        ArrayList<Integer>[] graph;
        int num;

        Answer(ArrayList<Integer>[] graph, int num) {
            this.graph = graph;
            this.num = num;
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
        new C().run();
    }


    Answer Kruskal(ArrayList<Edge> graph, int k) {
        Collections.sort(graph);
        int[] comp = new int[k];
        ArrayList<Integer>[] ans = new ArrayList[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = new ArrayList<Integer>();
            comp[i] = i;
        }
        ArrayList<Integer>[] comps = new ArrayList[k];
        for (int i = 0; i < k; ++i) {
            comps[i] = new ArrayList<Integer>();
            comps[i].add(i);
        }
        int num = 0;
        for (Edge e : graph) {
            if (comp[e.i] != comp[e.j]) {
                num += e.w;
                int c1 = Math.min(comp[e.i], comp[e.j]);
                int c2 = comp[e.i] + comp[e.j] - c1;
                for (int i : comps[c2]) {
                    comps[c1].add(i);
                    comp[i] = c1;
                }
                ans[e.i].add(e.j);
                ans[e.j].add(e.i);
            }
        }
        return new Answer(ans, num);
    }

    boolean[] used;
    ArrayList<Integer>[] graph;
    int k;
    void dfs(int u) {
        used[u] = true;
        for (int v : graph[u]) {
            if (!used[v]) {
                out.println((v == k ? 0 : v + 1) + " " + (u == k ? 0 : u + 1));
                dfs(v);
            }
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        k = nextInt();
        int w = nextInt();
        char[][][] field = new char[k + 1][n][m];
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < n; ++j) {
                char[] s = nextToken().toCharArray();
                for (int g = 0; g < m; ++g)
                    field[i][j][g] = s[g];
            }
        for (int i = 0; i < n; ++i)
            field[k][i] = new char[m];
        ArrayList<Edge> g = new ArrayList<Edge>();
        for (int i = 0; i <= k; ++i)
            for (int j = 0; j <= k; ++j) {
                if (i == j)
                    continue;
                int err = 0;
                for (int a = 0; a < n; ++a)
                    for (int b = 0; b < m; ++b)
                        if (field[i][a][b] != field[j][a][b])
                            ++err;
                g.add(new Edge(i, j, (i == k || j == k) ? err : err * w));
            }
        Answer ans = Kruskal(g, k + 1);
        graph = ans.graph;
        used = new boolean[k + 1];
        out.println(ans.num);
        dfs(k);
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