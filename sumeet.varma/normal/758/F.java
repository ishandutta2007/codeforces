import java.io.*;
import java.util.*;

public class R392qF {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    int l = in.nextInt();
    int r = in.nextInt();

    if (n > 50) {
      System.out.println(0);
      return;
    }
    
    if (n == 1) {
      System.out.println(r - l + 1);
      return;
    }
    
    if (n == 2) {
      long ans = (r - l + 1) * 1L * (r - l + 1) - (r - l + 1);
      System.out.println(ans);
      return;
    }
    
    int p[] = new int[100000];
    
    int max = 1;
    p[1] = 1;
    long temp;
    while ((temp = pow(max + 1, n - 1)) <= r) {
      p[max + 1] = (int)temp;
      max++;
    }
    
    long ans = 0;
    
    for (int b = 1; b <= max; b++) {
      int low = l / p[b];
      if (l % p[b] != 0)
        low++;
      for (int a = b + 1; a <= max; a++) {
        if (gcd(a, b) == 1) {
          int hig = r / p[a];
          if (hig >= low)
            ans += hig - low + 1;
        }
      }
    }
    
    w.println(2 * ans);
    w.close();
  }
  
  public static int gcd(int a, int b) {
    while (b != 0) {
      int t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
  
  static long pow(int a, int b) {
    if (b == 0)
      return 1;
    long t = pow(a, b >> 1);
    t *= t;
    if ( (b & 1) == 1)
       t *= a;
    return t;
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