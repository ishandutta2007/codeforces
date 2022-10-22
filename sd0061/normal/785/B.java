import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        MyScanner in = new MyScanner();
        int n = in.nextInt();
        int rn = Integer.MAX_VALUE , ln = Integer.MIN_VALUE;
        for (int i = 0 ; i < n ; ++ i) {
            int l = in.nextInt() , r = in.nextInt();
            ln = Math.max(l , ln);
            rn = Math.min(r , rn);
        }
        int m = in.nextInt();
        int rm = Integer.MAX_VALUE , lm = Integer.MIN_VALUE;
        for (int i = 0 ; i < m ; ++ i) {
            int l = in.nextInt() , r = in.nextInt();
            lm = Math.max(l , lm);
            rm = Math.min(r , rm);
        }
        int res = 0;
        res = Math.max(res , Math.max(ln - rm, lm - rn));
        System.out.println(res);
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