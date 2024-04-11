import java.io.*;
import java.util.*;

public class _8VCEliminiation2017qC {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    
    int p[] = in.nextIntArray(n);
    
    DisjointSet ds = new DisjointSet(n);
    for (int i = 0; i < n; i++)
      ds.merge(i, p[i] - 1);
    
    w.println(ds.comp);
    w.close();
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