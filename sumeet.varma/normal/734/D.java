import java.io.*;
import java.util.*;

public class R379qD {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter W = new PrintWriter(System.out);
    
    int N = in.nextInt();
    
    int xo = in.nextInt();
    int yo = in.nextInt();
    
    char t[] = new char[N];
    int x[] = new int[N];
    int y[] = new int[N];
    
    int n = -1, s = -1;
    int e = -1, w = -1;
    int nw = -1, ne = -1;
    int sw = -1, se = -1;
    
    for (int i = 0; i < N; i++) {
      t[i] = in.readString().charAt(0);
      x[i] = in.nextInt() - xo;
      y[i] = in.nextInt() - yo;
      
      if (x[i] == 0) {
        if (y[i] > 0) {
          if (n == -1 || y[n] > y[i])
            n = i;
        } else {
          if (s == -1 || y[s] < y[i])
            s = i;
        }
      }
      
      if (y[i] == 0) {
        if (x[i] > 0) {
          if (e == -1 || x[e] > x[i])
            e = i;
        } else {
          if (w == -1 || x[w] < x[i])
            w = i;
        }
      }
      
      if (x[i] == y[i]) {
        if (x[i] > 0) {
          if (ne == -1 || x[ne] > x[i])
            ne = i;
        } else {
          if (sw == -1 || x[sw] < x[i])
            sw = i;
        }
      }
      
      if (x[i] + y[i] == 0) {
        if (x[i] > 0) {
          if (se == -1 || x[se] > x[i])
            se = i;
        } else {
          if (nw == -1 || x[nw] < x[i])
            nw = i;
        }
      }
    }
    
    boolean ans = false;
    
    if (n != -1 && (t[n] == 'R' || t[n] == 'Q'))
      ans = true;
    
    if (s != -1 && (t[s] == 'R' || t[s] == 'Q'))
      ans = true;
    
    if (e != -1 && (t[e] == 'R' || t[e] == 'Q'))
      ans = true;
    
    if (w != -1 && (t[w] == 'R' || t[w] == 'Q'))
      ans = true;
    
    
    if (nw != -1 && (t[nw] == 'B' || t[nw] == 'Q'))
      ans = true;
    
    if (ne != -1 && (t[ne] == 'B' || t[ne] == 'Q'))
      ans = true;
    
    if (sw != -1 && (t[sw] == 'B' || t[sw] == 'Q'))
      ans = true;
    
    if (se != -1 && (t[se] == 'B' || t[se] == 'Q'))
      ans = true;
    
    W.println(ans ? "YES" : "NO");
    W.close();
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