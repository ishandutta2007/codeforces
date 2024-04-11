import java.io.*;
import java.util.*;

public class R393qC {

  static int val[];
  static int max[], lazy[];

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int m = in.nextInt();
    
    val = new int[m + 1];
    max = new int[4 * m];
    lazy = new int[4 * m];
    
    for (int i = 1; i <= m; i++) {
      int pi = in.nextInt();
      int ti = in.nextInt();
      if (ti == 0) {
        update(1, m, 0, 1, pi, -1);
      } else {
        val[pi] = in.nextInt();
        update(1, m, 0, 1, pi, +1);
      }
      //System.out.println(Arrays.toString(max) + " " + Arrays.toString(lazy));
      w.println(find(1, m, 0));
    }
    
    w.close();
  }

  static public void update(int s, int e, int c, int l, int r, int v) {
    if (s == l && e == r) {
      max[c] += v;
      lazy[c] += v;
      return;
    }
    propogate(c);
    int m = (s + e) >> 1;
    if (r <= m)
      update(s, m, 2 * c + 1, l, r, v);
    else if (l > m)
      update(m + 1, e, 2 * c + 2, l, r, v);
    else {
      update(s, m, 2 * c + 1, l, m, v);
      update(m + 1, e, 2 * c + 2, m + 1, r, v);
    }
    max[c] = Math.max(max[2 * c + 1], max[2 * c + 2]);
  }

  static public int find(int s, int e, int c) {
    if (max[c] <= 0)
      return -1;
    if (s == e)
      return val[s];
    propogate(c);
    int m = (s + e) >> 1;
    if (max[2 * c + 2] > 0)
      return find(m + 1, e, 2 * c + 2);
    else
      return find(s, m, 2 * c + 1);
  }

  static void propogate(int c) {
    max[2 * c + 1] += lazy[c];
    max[2 * c + 2] += lazy[c];
    lazy[2 * c + 1] += lazy[c];
    lazy[2 * c + 2] += lazy[c];
    lazy[c] = 0;
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