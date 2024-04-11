import java.io.*;
import java.util.*;

public class R399qC {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    int k = in.nextInt();
    int x = in.nextInt();
    
    int b = 10;
    int N = 1 << b;
    
    int f[][] = new int[2][N];
    for (int i = 0; i < n; i++)
      f[0][in.nextInt()]++;
    
    int prev = 0;
    int curr = 1;
    
    for (int i = 0; i < k; i++) {
      int prefix = 0;
      for (int j = 0; j < N; j++) {
        if ((prefix & 1) == 1) {
          f[curr][j ^ x] += f[prev][j] >> 1;
          f[curr][j] += f[prev][j] - (f[prev][j] >> 1);
        } else {
          f[curr][j] += f[prev][j] >> 1;
          f[curr][j ^ x] += f[prev][j] - (f[prev][j] >> 1);
        }
        prefix += f[prev][j];
        f[prev][j] = 0;
      }
      prev ^= 1;
      curr ^= 1;
    }
    
    int min = 1 << b, max = -1;
    for (int i = 0; i < N; i++) {
      if (f[prev][i] > 0) {
        min = Math.min(min, i);
        max = Math.max(max, i);
      }
    }
    
    w.println(max + " " + min);
    w.close();
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