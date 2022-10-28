import java.io.*;
import java.util.*;

public class R392qC {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    int m = in.nextInt();
    
    long k = in.nextLong();
    int x = in.nextInt() - 1;
    int y = in.nextInt() - 1;
    
    long f[][] = new long[n][m];
    
    long oneRound;
    
    if (n == 1) {
      oneRound = m;
    } else {
      oneRound = n * m + (n - 2) * m;
    }
    
    long rounds = k / oneRound;
    k %= oneRound;
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i != 0 && i != n - 1)
          f[i][j] = 2 * rounds;
        else
          f[i][j] = rounds;
      }
    }
    
    //System.out.println(oneRound);
    //System.out.println(rounds + " " + k);
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (k > 0) {
          f[i][j]++;
          k--;
        }
      }
    }
    
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (k > 0) {
          f[i][j]++;
          k--;
        }
      }
    }
    
    long min = f[0][0], max = f[0][0];
    
    for (long i[] : f) {
      for (long j : i) {
        min = Math.min(min, j);
        max = Math.max(max, j);
      }
    }
    
    w.println(max + " " + min + " " + f[x][y]);
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