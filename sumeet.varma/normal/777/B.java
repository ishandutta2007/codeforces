import java.io.*;
import java.util.*;

public class R401qB {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    
    char a[] = in.readString().toCharArray();
    char b[] = in.readString().toCharArray();
    
    int f[] = new int[256];
    for (char x : b)
    	f[x]++;
    
    int min = 0;
    int t[] = Arrays.copyOf(f, f.length);
    for (char x : a) {
    	boolean h = false;
    	for (char j = x; j <= '9'; j++) {
    		if (t[j] > 0) {
    			t[j]--;
    			h = true;
    			break;
    		}
    	}
    	if (!h) {
    		for (char j = '0'; j < x; j++) {
    			if (t[j] > 0) {
    				t[j]--;
    				min++;
    				break;
    			}
    		}
    	}
    }
    
    int max = 0;
    t = Arrays.copyOf(f, f.length);
    for (char x : a) {
    	boolean h = false;
    	for (char j = (char)(x + 1); j <= '9'; j++) {
    		if (t[j] > 0) {
    			t[j]--;
    			h = true;
    			max++;
    			break;
    		}
    	}
    	if (!h) {
    		for (char j = '0'; j <= x; j++) {
    			if (t[j] > 0) {
    				t[j]--;
    				break;
    			}
    		}
    	}
    }
    
    w.println(min);
    w.println(max);
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