import java.io.*;
import java.util.*;

public class R392qD {

  static int n;
  static char k[];
  static long dp[];
  static long T = (long)2e18;
  
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);
    
    n = in.nextInt();
    k = ("#" + in.readString()).toCharArray();
    
    if (k[1] == '0') {
      w.println(0);
      w.close();
      return;
    }
    
    dp = new long[k.length];
    Arrays.fill(dp, -1);
    
    dp[0] = 0;
    
    w.println(DP(k.length - 1));
    w.close();
  }
  
  static long DP(int idx) {
    if (dp[idx] == -1) {
      dp[idx] = add(mul(DP(idx - 1), n), k[idx] - '0');
      for (int prev = idx - 2; prev >= 0; prev--) {
        long val = parse(prev + 1, idx);
        if (val < 0)
          continue;
        dp[idx] = Math.min(dp[idx], add(mul(DP(prev), n), val));
      }
    }
    return dp[idx];
  }
  
  static long parse(int start, int end) {
    int len = end - start + 1;
    if (len > 12)
      return -1;
    if (k[start] == '0')
      return -1;
    long val = Long.parseLong(new String(k).substring(start, end + 1));
    if (val >= n)
      return -1;
    return val;
  }
  
  static long mul(long a, long b) {
    if (a == 0 || b == 0)
      return 0;
    long t = a * b;
    if (t % a == 0 && t % b == 0)
      return Math.min(t, T);
    return T;
  }
  
  static long add(long a, long b) {
    return Math.min(a + b, T);
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