import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class CodecraftqC {

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter w = new PrintWriter(System.out);

    int n = in.nextInt();
    int m = in.nextInt();

    int a[][] = new int[n][];

    //HashMap<Integer, ArrayList<Pair>> show = new HashMap<>();
    //int empty = m;
    
    long h[] = new long[m + 1];
    long P = 1;
    int magic = 37;
    
    long hashMod = 10000000000037L;//BigInteger.valueOf((long)1e13).nextProbablePrime().longValueExact();
    //System.out.println(hashMod);
    
    for (int i = 0; i < n; i++) {
      int g = in.nextInt();
      a[i] = in.nextIntArray(g);
      HashMap<Integer, Integer> map = new HashMap<>();
      for (int x : a[i]) {
        if (!map.containsKey(x))
          map.put(x, 0);
        map.put(x, map.get(x) + 1);
      }
      
      //System.out.println(map);
      
      for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        int k = entry.getKey();
        int v = entry.getValue();
        /*if (!show.containsKey(k)) {
          show.put(k, new ArrayList<Pair>());
          empty--;
        }
        show.get(k).add(new Pair(i, v));*/
        h[k] = (h[k] + P * v) % hashMod;
      }
      P = (P * magic) % hashMod;
    }
    /*
    System.out.println(show);

    HashMap<ArrayList<Pair>, Integer> rev = new HashMap<ArrayList<Pair>, Integer>();
    for (Map.Entry<Integer, ArrayList<Pair>> entry : show.entrySet()) {
      ArrayList<Pair> v = entry.getValue();
      if (!rev.containsKey(v))
        rev.put(v, 0);
      rev.put(v, rev.get(v) + 1);
    }
    
    System.out.println(rev);
*/
    HashMap<Long, Integer> rev = new HashMap<>();
    for (int i = 1; i <= m; i++) {
      long x = h[i];
      if (!rev.containsKey(x))
        rev.put(x, 0);
      rev.put(x, rev.get(x) + 1);
    }
    
    long ans = 1;

    int mod = (int) 1e9 + 7;
    long f[] = new long[m + 10];
    f[0] = 1;
    for (int i = 1; i < f.length; i++)
      f[i] = (i * f[i - 1]) % mod;

    for (int v : rev.values())
      ans = (ans * f[v]) % mod;
    
    w.println(ans);
    w.close();
  }

  static class Pair implements Comparable<Pair> {
    int x, y;

    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }

    public int compareTo(Pair o) {
      if (x != o.x)
        return Integer.compare(x, o.x);
      return Integer.compare(y, o.y);
    }

    public String toString() {
      return x + " " + y;
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