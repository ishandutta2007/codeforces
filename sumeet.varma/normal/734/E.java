import java.io.*;
import java.util.*;

public class R379qE {

  static int diam;
  static ArrayList<Integer> g[];

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();

    int c[] = in.nextIntArray(n);
    DisjointSet ds = new DisjointSet(n);

    int u[] = new int[n];
    int v[] = new int[n];

    for (int i = 0; i < n - 1; i++) {
      u[i] = in.nextInt() - 1;
      v[i] = in.nextInt() - 1;
      if (c[u[i]] == c[v[i]])
        ds.merge(u[i], v[i]);
    }

    g = new ArrayList[n];
    for (int i = 0; i < n; i++)
      g[i] = new ArrayList<Integer>();

    int root = 0;

    for (int i = 0; i < n - 1; i++) {
      root = ds.find(u[i]);
      if (ds.find(u[i]) == ds.find(v[i]))
        continue;
      g[ds.find(u[i])].add(ds.find(v[i]));
      g[ds.find(v[i])].add(ds.find(u[i]));
    }
  
    diam = 0;
    dfs(root, -1, 0);
    
    w.println((diam + 1) / 2);
    w.close();
  }

  static int dfs(int c, int p, int l) {

    int max = 0;
    
    for (int v : g[c]) {
      if (v != p) {
        int d = 1 + dfs(v, c, l + 1);
        diam = Math.max(diam, max + d);
        max = Math.max(max, d);
      }
    }
    
    return max;
  }

  static public class DisjointSet {

    public int rank[], parent[], size[];
    public int n, comp;

    public DisjointSet(int n) {
      this.n = n;
      makeSet();
    }

    public void makeSet() {
      rank = new int[n];
      parent = new int[n];
      for (int i = 0; i < n; i++)
        parent[i] = i;
      size = new int[n];
      Arrays.fill(size, 1);
      comp = n;
    }

    public int find(int x) {
      if (parent[x] != x)
        parent[x] = find(parent[x]);
      return parent[x];
    }

    public void merge(int x, int y) {
      int xRoot = find(x);
      int yRoot = find(y);

      if (xRoot == yRoot)
        return;

      size[xRoot] = size[yRoot] = size[xRoot] + size[yRoot];

      if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
      else {
        parent[yRoot] = xRoot;
        if (rank[xRoot] == rank[yRoot])
          rank[xRoot]++;
      }

      comp--;
    }

  }

  static class InputReader {

    private final InputStream stream;
    private final byte[] buf = new byte[8192];
    private int curChar, snumChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int snext() {
      if (snumChars == -1)
        throw new InputMismatchException();
      if (curChar >= snumChars) {
        curChar = 0;
        try {
          snumChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (snumChars <= 0)
          return -1;
      }
      return buf[curChar++];
    }

    public int nextInt() {
      int c = snext();
      while (isSpaceChar(c)) {
        c = snext();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = snext();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9')
          throw new InputMismatchException();
        res *= 10;
        res += c - '0';
        c = snext();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public long nextLong() {
      int c = snext();
      while (isSpaceChar(c)) {
        c = snext();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = snext();
      }
      long res = 0;
      do {
        if (c < '0' || c > '9')
          throw new InputMismatchException();
        res *= 10;
        res += c - '0';
        c = snext();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public int[] nextIntArray(int n) {
      int a[] = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = nextInt();
      }
      return a;
    }

    public String readString() {
      int c = snext();
      while (isSpaceChar(c)) {
        c = snext();
      }
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = snext();
      } while (!isSpaceChar(c));
      return res.toString();
    }

    public String nextLine() {
      int c = snext();
      while (isSpaceChar(c))
        c = snext();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = snext();
      } while (!isEndOfLine(c));
      return res.toString();
    }

    public boolean isSpaceChar(int c) {
      if (filter != null)
        return filter.isSpaceChar(c);
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private boolean isEndOfLine(int c) {
      return c == '\n' || c == '\r' || c == -1;
    }

    public interface SpaceCharFilter {
      public boolean isSpaceChar(int ch);
    }
  }
}