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
        int res = 0 , T = in.nextInt();
        for (int i = 0 ; i < T ; ++ i) {
            String s = in.nextLine();
            if (s.compareTo("Tetrahedron") == 0) {
                res += 4;
            }
            if (s.compareTo("Cube") == 0) {
                res += 6;
            }
            if (s.compareTo("Octahedron") == 0) {
                res += 8;
            }
            if (s.compareTo("Dodecahedron") == 0) {
                res += 12;
            }
            if (s.compareTo("Icosahedron") == 0) {
                res += 20;
            }
        }
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