import java.io.*;
import java.util.*;

public class R399qB {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);
    
    long n = in.nextLong();
    long l = in.nextLong();
    long r = in.nextLong();
    
    w.println(find(l, r, n));
    w.close();
  }
  
  static long find(long l, long r, long n) {
    long N = f(n);
    if (r - l + 1 == N) {
      return t(n);
    }
    long m = (1 + N) >> 1;
    long midValue = n % 2;
    long ans = 0;
    if (m >= l && m <= r)
      ans += midValue;
    long leftEnd = Math.min(m - 1, r);
    if (l <= leftEnd)
      ans += find(l, leftEnd, n / 2);
    long rightStart = Math.max(l, m + 1);
    if (rightStart <= r)
      ans += find(rightStart - m, r - m, n / 2);
    return ans;
  }
 
  static long f(long n) {
    if (n <= 1)
      return 1;
    return 1 + 2 * f(n / 2);
  }
  
  static long t(long n) {
    if (n <= 1)
      return n;
    return (n % 2) + 2 * t(n / 2);
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