  import java.io.*;
import java.util.*;
  
  public class LastestInput {
  
    public static void main(String[] args) {
      InputReader in = new InputReader(System.in);
      PrintWriter w = new PrintWriter(System.out);
  
      int prev = -1;
      
      char s[] = in.readString().toCharArray();
      int ans = 0;
      int i = -1;
      
      for (char x : s) {
        i++;
        if (x == 'A' || x == 'E'|| x == 'I'|| x == 'O'|| x == 'U'|| x == 'Y') {
          ans = Math.max(ans, i - prev);
          prev = i;
        }
      }
      
      ans = Math.max(ans, s.length - prev);
      w.println(ans);
      w.close();
    }
    
    static void printDiff(ArrayList<Integer> g) {
      int prev = 0;
      for (int x : g) {
        System.out.print(x - prev);
        System.out.print( " " );
        prev = x;
      }
      System.out.println();
    }
  
    static public class PermutationUtils {
  
      static int cnt;
  
      public   static int[][] getAllPermutations(int n) {
        int nfact = 1;
        for (int i = 1; i <= n; i++)
          nfact *= i;
        int ans[][] = new int[nfact][];
        cnt = 0;
        go(0, ans, n, new int[n], new boolean[n]);
        return ans;
      }
  
      public static void go(int pos, int ans[][], int n, int arr[], boolean done[]) {
        if (pos == n) {
          ans[cnt++] = Arrays.copyOf(arr, n);
        } else {
          for (int val = 0; val < n; val++) {
            if (!done[val]) {
              done[val] = true;
              arr[pos] = val;
              go(pos + 1, ans, n, arr, done);
              done[val] = false;
            }
          }
        }
      }
    }
  
    static class InputReader {
  
      private final InputStream st;
      private final byte[] buf = new byte[8192];
      private int cc, sc;
      private SpaceCharFilter f;
  
      public InputReader(InputStream st) {
        this.st = st;
      }
  
      public int t() {
        if (sc == -1)
          throw new InputMismatchException();
        if (cc >= sc) {
          cc = 0;
          try {
            sc = st.read(buf);
          } catch (IOException e) {
            throw new InputMismatchException();
          }
          if (sc <= 0)
            return -1;
        }
        return buf[cc++];
      }
  
      public int nextInt() {
        int c = t();
        while (isSpaceChar(c)) {
          c = t();
        }
        int sgn = 1;
        if (c == '-') {
          sgn = -1;
          c = t();
        }
        int res = 0;
        do {
          res *= 10;
          res += c - '0';
          c = t();
        } while (!isSpaceChar(c));
        return res * sgn;
      }
  
      public long nextLong() {
        int c = t();
        while (isSpaceChar(c)) {
          c = t();
        }
        int sgn = 1;
        if (c == '-') {
          sgn = -1;
          c = t();
        }
        long res = 0;
        do {
          res *= 10;
          res += c - '0';
          c = t();
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
        int c = t();
        while (isSpaceChar(c)) {
          c = t();
        }
        StringBuilder res = new StringBuilder();
        do {
          res.appendCodePoint(c);
          c = t();
        } while (!isSpaceChar(c));
        return res.toString();
      }
  
      public String nextLine() {
        int c = t();
        while (isSpaceChar(c))
          c = t();
        StringBuilder res = new StringBuilder();
        do {
          res.appendCodePoint(c);
          c = t();
        } while (!isEndOfLine(c));
        return res.toString();
      }
  
      public boolean isSpaceChar(int c) {
        if (f != null)
          return f.isSpaceChar(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
      }
  
      private boolean isEndOfLine(int c) {
        return c == '\n' || c == '\r' || c == -1;
      }
  
      public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
      }
    }
  }