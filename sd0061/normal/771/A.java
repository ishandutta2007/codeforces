import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.*;
import java.util.*;

public class Main {
    static int N = 150005;
    static int[] f = new int[N];
    static int[] s = new int[N];
    static int[] e = new int[N];


    private static int getf(int x) {
      return f[x] == x ? x : (f[x] = getf(f[x]));
    }

    public static void main(String[] args) {
      MyScanner in = new MyScanner();
      PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
      int n = in.nextInt() , m = in.nextInt();
      for (int i = 0 ; i < n ; ++ i) {
        f[i] = i;
        s[i] = 1;
        e[i] = 0;
      }
      for (int i = 0 ; i < m ; ++ i) {
        int x = in.nextInt() - 1, y = in.nextInt() - 1;
        if (getf(x) != getf(y)) {
          s[getf(y)] += s[getf(x)];
          e[getf(y)] += e[getf(x)];
          f[getf(x)] = getf(y);
        }
        ++ e[getf(x)];
      }
      for (int i = 0 ; i < n ; ++ i) {
        if (getf(i) == i && e[i] != (long)s[i] * (s[i] - 1) / 2) {
          System.out.println("NO");
          return;
        }
      }
      System.out.println("YES");
    }


  static class MyScanner {
    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(next());
    }

    long nextLong() {
      return Long.parseLong(next());
    }

    double nextDouble() {
      return Double.parseDouble(next());
    }

    String nextLine(){
      String str = "";
      try {
        str = br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
      return str;
    }
  }
}