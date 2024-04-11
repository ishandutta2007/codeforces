import java.io.*;
import java.util.*;

public class ER21qE
{

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    int m = in.nextInt();
    
    @SuppressWarnings("unchecked")
	ArrayList<Integer> c[] = new ArrayList[4];
    for (int i = 1; i <= 3; i++)
    	c[i] = new ArrayList<Integer>();
    
    for (int i = 0; i < n; i++)
    	c[in.nextInt()].add(in.nextInt());
    
    for (int i = 1; i <= 3; i++) {
    	while (c[i].size() < m + 3)
    		c[i].add(0);
    }
    
    for (int i = 1; i <= 3; i++)
    	Collections.sort(c[i], Collections.reverseOrder());
    
    long dp[] = new long[m + 1];
    int _2 = 0, _1 = 0;
    
    for (int i = 2; i <= m; i += 2) {
    	if (c[2].get(_2) >= c[1].get(_1) + c[1].get(_1 + 1)) {
    		dp[i] = dp[i - 2] + c[2].get(_2);
    		_2++;
    	} else {
    		dp[i] = dp[i - 2] + c[1].get(_1) + c[1].get(_1 + 1);
    		_1 += 2;
    	}
    }
    
    dp[1] = c[1].get(0);
    _2 = 0;
    _1 = 1;
    
    for (int i = 3; i <= m; i += 2) {
    	if (c[2].get(_2) >= c[1].get(_1) + c[1].get(_1 + 1)) {
    		dp[i] = dp[i - 2] + c[2].get(_2);
    		_2++;
    	} else {
    		dp[i] = dp[i - 2] + c[1].get(_1) + c[1].get(_1 + 1);
    		_1 += 2;
    	}
    }
    
    long tot = 0, ans = 0;
    for (int i = 0; i <= c[3].size() && 3*i <= m; i++) {
    	ans = Math.max(ans, tot + dp[m - 3 * i]);
    	if (i < c[3].size())
    		tot += c[3].get(i);
    }
    
    w.println(ans);
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