import java.io.*;
import java.util.*;

public class R393qD {

  static final int mod = (int) 1e9 + 7;
  static final int A = 26;
  static int n;
  static char s[];
  static long fact[], inv[];

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    n = in.nextInt();

    fact = new long[5 * n + 1];
    fact[0] = 1;
    for (int i = 1; i < fact.length; i++)
      fact[i] = (i * fact[i - 1]) % mod;

    inv = new long[fact.length];
    for (int i = 0; i < inv.length; i++)
      inv[i] = pow(fact[i], mod - 2, mod);

    s = in.readString().toCharArray();
    
    int dp[][] = new int[A][n + 1];
    int tot[] = new int[n + 1];
    int prevAdd[][] = new int[A][n + 1];
    int first[] = new int[A];
    Arrays.fill(first, -1);
    
    for (int i = 0; i < n; i++) {
      int x = s[i] - 'a';
      
      for (int j = n - 1; j > 0; j--) {
        long addNow = (tot[j] - dp[x][j]) % mod;
        if (addNow < 0)
          addNow += mod;
        
        long addPrev = prevAdd[x][j];
   
        long add = (addNow - addPrev) % mod;
        if (add < 0)
          add += mod;
        
        dp[x][j + 1] += add;
        if (dp[x][j + 1] >= mod)
          dp[x][j + 1] -= mod;
        
        tot[j + 1] += add;
        if (tot[j + 1] >= mod)
          tot[j + 1] -= mod;
        
        prevAdd[x][j] = (int)addNow;
      }
      
      if (first[x] == -1) {
        first[x] = 0;
        dp[x][1] = 1;
        tot[1]++;
      }
    }

    long cnt[] = new long[n + 1];
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < A; j++) {
        cnt[i] += dp[j][i];
        if (cnt[i] >= mod)
          cnt[i] -= mod;
      }
    }

    long ans = 0;

    for (int i = 1; i <= n; i++) {
      int N = n - i;
      int K = i;
      ans += C(N + K - 1, K - 1) * cnt[i];
      ans %= mod;
    }

    w.println(ans);
    w.close();
  }

  static long C(int n, int r) {
    long ans = fact[n];
    ans *= inv[r];
    ans %= mod;
    ans *= inv[n - r];
    ans %= mod;
    return ans;
  }

  static long pow(long a, int b, int mod) {
    if (b == 0)
      return 1;
    long t = pow(a, b >> 1, mod);
    t = (t * t) % mod;
    if ((b & 1) != 0)
      t = (t * a) % mod;
    return t;
  }

  static class Pair implements Comparable<Pair> {
    int idx, val;

    Pair(int i, int v) {
      idx = i;
      val = v;
    }

    public int compareTo(Pair o) {
      if (val != o.val)
        return Integer.compare(val, o.val);
      return Integer.compare(idx, o.idx);
    }

    public String toString() {
      return idx + " " + val;
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