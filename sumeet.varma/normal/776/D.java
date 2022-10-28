import java.io.*;
import java.util.*;

public class R400qD {

  static int r[];
  static DisjointSet ds;
  static ArrayList<Integer> g[];
  static int r1[], r2[];
  static int c[];
  static boolean f;
  
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    int m = in.nextInt();
  
    r = in.nextIntArray(n);
    
    ds = new DisjointSet(m);
    r1 = new int[n];
    r2 = new int[n];
    
    for (int i = 1; i <= m; i++) {
      int x = in.nextInt();
      for (int j = 0; j < x; j++) {
        int R = in.nextInt() - 1;
        if (r1[R] == 0) {
          r1[R] = i;
        } else {
          r2[R] = i;
        }
      }
    }
    
    for (int i = 0; i < n; i++) {
      if (r[i] == 1) {
        ds.merge(r1[i] - 1, r2[i] - 1);
      }
    }
    
    g = new ArrayList[m];
    for (int i = 0; i < m; i++) {
      g[i] = new ArrayList<Integer>();
    }
    
    for (int i = 0; i < n; i++) {
      if (r[i] == 0) {
        g[ds.find(r1[i] - 1)].add(ds.find(r2[i] - 1));
        g[ds.find(r2[i] - 1)].add(ds.find(r1[i] - 1));
      }
    }
    
    f = true;
    c = new int[m];
    
    for (int i = 0; i < m && f; i++) {
      if (ds.find(i) == i) {
        if (c[i] == 0) {
          dfs(i, +1);
        }
      }
    }
    
    w.println(f ? "YES" : "NO");
    w.close();
  }
  
  static void dfs(int x, int y) {
    if (c[x] != 0) {
      if (c[x] != y) {
        f = false;
      }
      return;
    }
    c[x] = y;
    for (int next : g[x]) {
      dfs(next, -y);
    }
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

    public InputReader(InputStream st) {
      this.stream = st;
    }

    public int read() {
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
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public long nextLong() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      long res = 0;
      do {
        res *= 10;
        res += c - '0';
        c = read();
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
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = read();
      } while (!isSpaceChar(c));
      return res.toString();
    }

    public String nextLine() {
      int c = read();
      while (isSpaceChar(c))
        c = read();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = read();
      } while (!isEndOfLine(c));
      return res.toString();
    }

    public boolean isSpaceChar(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private boolean isEndOfLine(int c) {
      return c == '\n' || c == '\r' || c == -1;
    }

  }

}