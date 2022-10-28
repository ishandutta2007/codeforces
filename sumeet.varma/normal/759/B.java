import java.io.*;
import java.util.*;

public class R393qB {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    

    int t[] = new int[n + 1];
    t[0] = -10000;
    
    long dp[] = new long[n + 1];
    
    for (int i = 1; i <= n; i++) {
      t[i] = in.nextInt();
      dp[i] = 20 + dp[i - 1];
    
      {
        int start = 0, end = i;
        int best = 0;
        while (start < end) {
          int mid = (start + end) >> 1;
          if (t[mid] + 90 - 1 < t[i]) {
            start = mid + 1;
            best = mid;
          } else {
            end = mid;
          }
        }
        dp[i] = Math.min(dp[i], 50 + dp[best]);
      }
      
      {
        int start = 0, end = i;
        int best = 0;
        while (start < end) {
          int mid = (start + end) >> 1;
          if (t[mid] + 1440 - 1 < t[i]) {
            start = mid + 1;
            best = mid;
          } else {
            end = mid;
          }
        }
        dp[i] = Math.min(dp[i], 120 + dp[best]);
      }
      
      w.println(dp[i] - dp[i - 1]);
    }
    
    
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