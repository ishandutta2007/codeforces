import java.io.*;
import java.util.*;

public class R399qF {

  static int mod = (int)1e9 + 7;
  static long fact[], inv[];
  
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    pre();
    
    int f = in.nextInt();
    int w = in.nextInt();
    int h = in.nextInt();
    
    long p = 0;
    long q = 0;
    
    for (int n = 1; n <= f + w; n++) {
      {
        int F = (n + 1) / 2;
        int W = n / 2;
        q += get(f, F, 1) * get(w, W, 1);
        p += get(f, F, 1) * get(w, W, h + 1);
      }
      {
        int F = n / 2;
        int W = (n + 1) / 2;
        q += get(f, F, 1) * get(w, W, 1);
        p += get(f, F, 1) * get(w, W, h + 1);
      }
      p %= mod;
      q %= mod;
    }
    
    out.println((p * pow(q, mod - 2,mod)) % mod);
    out.close();
  }
  
  static long get(long balls, long bins, long min) {
    if (bins == 0) {
      return balls == 0 ? 1 : 0;
    }
    return getSol(balls - bins * min, bins);
  }
  
  static long getSol(long balls, long bins) {
    if (balls < 0)
      return 0;
    return C((int)(balls + bins - 1), (int)(bins - 1));
  }
  
  static long C(int N, int R) {
    if (R < 0 || R > N)
      return 0;
    long t = (fact[N] * inv[R]) % mod;
    return (t * inv[N - R]) % mod;
  }
  
  static void pre() {
    int N = 8 * 100010;
    fact = new long[N];
    inv = new long[N];
    
    fact[0] = 1;
    inv[0] = pow(fact[0], mod - 2, mod);
    
    for (int i = 1; i < N; i++) {
      fact[i] = (i * fact[i - 1]) % mod;
      inv[i] = pow(fact[i], mod - 2, mod);
    }
  }
  
  static long pow(long a, int b, int mod) {
    if (b == 0) {
      return 1;
    }
    long t = pow(a, b / 2, mod);
    t = (t * t) % mod;
    if ( b % 2 == 1) {
      t = (t * a) % mod;
    }
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