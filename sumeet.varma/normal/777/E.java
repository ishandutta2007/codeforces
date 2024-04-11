import java.io.*;
import java.util.*;

public class R401qE {

	static long st[];
	
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    
    Pair p[] = new Pair[n];
    for (int i = 0; i < n; i++) {
    	p[i] = new Pair(in.nextInt(), in.nextInt(), in.nextInt());
    }
    
    Arrays.sort(p);
    
    st = new long[4 * n];
    long dp[] = new long[n + 1];
    long ans = 0;
    
    for (int i = n - 1; i >= 0; i--) {
    	dp[i] = p[i].h;
    	int start = i + 1, end = n;
    	int best = i;
    	while (start < end) {
    		int mid = (start + end) >> 1;
    		if (p[mid].b > p[i].a) {
    			best = mid;
    			start = mid + 1;
    		} else {
    			end = mid;
    		}
    	}
    	if (best >= i + 1)
    		dp[i]+= find(0, n - 1, 0, i + 1, best);

    	update(0, n - 1, 0, i, dp[i]);
    	ans = Math.max(ans, dp[i]);
    }
    
    w.println(ans);
    w.close();
  }

  private static long find(int s, int e, int c, int l, int r) {
	if (s == l && e == r)
		return st[c];
	int m = (s + e) >> 1;
	if (r <= m)
		return find(s, m, 2*c+1, l, r);
	else if (l > m)
		return find(m + 1, e, 2*c+2, l, r);
	else
		return Math.max(find(s, m, 2*c+1, l, m), find(m+1, e, 2*c+2, m+1, r));
}
  
  private static void update(int s, int e, int c, int x, long v) {
	  if (s == e)
		  st[c] = v;
	  else {
		  int m = (s + e) >> 1;
		  if (x <= m)
			  update(s, m, 2*c+1, x, v);
		  else
			  update(m+1,e ,2*c+2, x, v);
		  st[c] =Math.max(st[2*c+1], st[2*c+2]);
	  }
  }

static class Pair implements Comparable<Pair> {
	  int a, b, h;
	  Pair (int a, int b, int h) {
		  this.a = a;
		  this.b = b;
		  this.h = h;
	  }
	  public int compareTo(Pair o) {
		  if (b != o.b)
			  return Integer.compare(o.b, b);
		  else {
			  return Integer.compare(o.a, a);
		  }
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