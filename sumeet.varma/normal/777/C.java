import java.io.*;
import java.util.*;

public class R401qC {

  static int n, m;
  static int max[];
  static int nx[][];
  
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    n = in.nextInt();
    m = in.nextInt();
    
    int a[][] = new int[n + 2][m + 2];
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		a[i][j] = in.nextInt();
    	}
    }
    
    nx = new int[n + 2][m + 2];
    max = new int[n + 2];
    
    for (int i = n; i >= 1; i--) {
    	for (int j = m; j >= 1; j--) {
    		if (a[i + 1][j] >= a[i][j])
    			nx[i][j] = nx[i + 1][j];
    		else
    			nx[i][j] = i;
    		max[i] = Math.max(max[i], nx[i][j]);
    	}
    }
    
    int q = in.nextInt();
    while (q-- > 0) {
    	int l = in.nextInt();
    	int r = in.nextInt();
    	w.println(max[l] >= r ? "Yes" : "No");
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