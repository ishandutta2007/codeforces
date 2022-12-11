import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }
}

class Solver {
    class Vertex implements Comparable<Vertex>{
        int c;
        int n;
        int s;
        Vertex(int c, int s, int n) {
            this.c = c;
            this.s = s;
            this.n = n;
        }
        public int compareTo(Vertex other) {
            if (this.s != other.s)
                return ((this.s < other.s)?(-1):(1));
            if (this.n == other.n)
                return 0;
            return ((this.n < other.n)?(-1):(1));
        }
        
    }
    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; i++) {
            int c = in.nextInt();
            int s = in.nextInt();
            v[i] = new Vertex(c, s, i + 1);
        }
        TreeSet<Vertex>[] set = new TreeSet[2];
        for (int i = 0; i < 2; i++) {
            set[i] = new TreeSet<Vertex>();
        }
        for (int i = 0; i < n; i++) {
            set[v[i].c].add(v[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            int cur = 0;
            if (set[1].first().s < set[0].first().s)
                cur = 1;
            if (set[1].first().s == set[0].first().s && set[1].size() > set[0].size())
                cur = 1;
            int dest = 1 - cur;
            Vertex leaf = set[cur].first();
            Vertex root = set[dest].last();
            set[cur].remove(leaf);
            set[dest].remove(root);
            int s = leaf.s;
            leaf.s -= s;
            root.s -= s;
            out.format("%d %d %d\n", leaf.n, root.n, s);
            set[dest].add(root);
        }
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}