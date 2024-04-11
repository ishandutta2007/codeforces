import java.io.*;
import java.util.*;

public class R400qC {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    int k = in.nextInt();
    
    long pre[] = new long[n + 1];
    for (int i = 1; i <= n; i++)
      pre[i] = pre[i - 1] + in.nextInt();
    
    long inf = (long)1e17;
 
    long t[] = new long[100];
    t[0] = 1;
    
    int cnt = 1;
    
    while (cnt < 90) {
      t[cnt] = t[cnt - 1] * k;
      if (Math.abs(t[cnt]) >= inf)
        break;
      cnt++;
    }
    
    if (k == 1) {
      cnt = 1;
    }
    
    if (k == -1) {
      cnt = 2;
    }
    
    HashMap<Long, Integer> f = new HashMap<Long, Integer>();
    long ans = 0;
    
    for (int i = 0; i <= n; i++) {
      
      for (int j = 0; j < cnt; j++) {
        long need = pre[i] - t[j];
        ans += f.containsKey(need) ? f.get(need) : 0;
      }
      
      if (!f.containsKey(pre[i])) {
        f.put(pre[i], 0);
      }
      
      f.put(pre[i], f.get(pre[i]) + 1);
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