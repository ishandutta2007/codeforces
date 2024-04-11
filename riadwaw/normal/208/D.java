import java.io.*;
import java.util.*;

public class D implements Runnable {
    void preCalc() {

    }

    void solve() throws IOException {
        int n = nextInt();
        int[] p = new int[n];
        for(int i= 0; i<n;++i){
            p[i] = nextInt();
        }

        int[] a = new int[5];
        for(int i = 0;i<5;++i){
            a[i] = nextInt();
        }


       long ans[] = new long[5];
        int balance = 0;
        for(int i = 0; i<n;++i){
            balance += p[i];
            for(int j=4;j>=0;--j){
                int cnt = balance / a[j];

                ans[j] += cnt;
                balance -= a[j] * cnt;
            }
        }

        for(int i = 0;i<5;++i){
            out.print(ans[i] + " ");
        }
        out.print("\n");
        out.print(balance);
    }

    public static void main(String[] args) {
        debugMode = args.length > 0 && args[0].equals("debug");
        new Thread(null, new D(), "", 1 << 25).start();
    }


    private void multiTest() throws IOException {
        int t = 1;
        preCalc();
        for (int i = 0; i < t; ++i) {
            solve();
        }
    }

    PrintWriter out;
    StringTokenizer st;
    BufferedReader br;

    public void run() {
        try {
            initFiles();
            long startTime = System.currentTimeMillis();
            if (debugMode) {
                out.println("Output:");
            }

            multiTest();
            if (debugMode) {
                double time = (System.currentTimeMillis() - startTime) / 1000.0;
                out.println("\n\n\nTime: " + time);
            }
            out.flush();
        } catch (IOException e) {
            out.println("IOException:");
            out.println(e.getStackTrace());
        }

    }

    private void initFiles() throws IOException {
        if (debugMode) {
            out = new PrintWriter(System.out);
            br = new BufferedReader(new FileReader("input.txt"));
        } else {
            out = new PrintWriter(System.out);
            br = new BufferedReader(new InputStreamReader(System.in));
        }
    }

    public String nextString() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }


    static boolean debugMode = false;


}