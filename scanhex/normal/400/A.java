/**
 * Created by Alex on 10.03.14.
 */

import java.io.*;
import java.util.*;

public class A {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new A().run();
    }

    public void solve() throws IOException {
        int t = nextInt();
        for (int i = 0; i < t; i++) {

            String s = nextToken();
            int cnt = 0;
            int[] arr = {1, 2, 3, 4, 6, 12};
            ArrayList<Integer> ans = new ArrayList<Integer>();
            for (int c : arr) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < c; j++) sb.append('X');
                boolean flag = false;
                for (int k = 0; k < c; k++) {
                    boolean flag1 = false;
                    for (int j = 0; j < 12 / c; j++) {
                        if (s.charAt(j * c + k) != 'X') flag1 = true;
                    }
                    if (!flag1) flag = true;
                }
                if (flag) ans.add(c);
            }
            Collections.sort(ans, new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return 12 / o1 - 12 / o2;
                }
            });
            out.print(ans.size() + " ");
            for (int c : ans) {
                out.print(12 / c + "x" +  c + " ");
            }
            out.println();
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}