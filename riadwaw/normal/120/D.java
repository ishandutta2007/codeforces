import java.io.*;
import java.util.*;
import java.math.*;

//created at 7:45 PM 10/20/11 by Abrackadabra

public class D {
    int IOMode = 2; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";

    int[][] a;

    int co(int x0, int y0, int x1, int y1) {
        int r = a[x1][y1];
        if (x0 > 0) r -= a[x0 - 1][y1];
        if (y0 > 0) r -= a[x1][y0 - 1];
        if (x0 > 0 && y0 > 0) r += a[x0 - 1][y0 - 1];
        return r;
    }

    void solve() throws IOException {
        int n = nextInt(), m = nextInt();
        a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nextInt();
            }
        }
        int[] s = {nextInt(), nextInt(), nextInt()};
        Arrays.sort(s);
        for (int i = 1; i < n; i++) {
            a[i][0] += a[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            a[0][i] += a[0][i - 1];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            }
        }
        int r = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int[] q = new int[3];
                q[0] = co(0, 0, i - 1, m - 1);
                q[1] = co(i, 0, j - 1, m - 1);
                q[2] = co(j, 0, n - 1, m - 1);
                Arrays.sort(q);
                if (q[0] == s[0] && q[1] == s[1] && q[2] == s[2]) r++;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int[] q = new int[3];
                q[0] = co(0, 0, n - 1, i - 1);
                q[1] = co(0, i, n - 1, j - 1);
                q[2] = co(0, j, n - 1, m - 1);
                Arrays.sort(q);
                if (q[0] == s[0] && q[1] == s[1] && q[2] == s[2]) r++;
            }
        }
        out.println(r);
    }

    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new D().run();
    }

    long startTime = System.nanoTime(), tempTime = startTime, finishTime = startTime;
    long startMem = Runtime.getRuntime().totalMemory(), finishMem = startMem;

    void run() throws IOException {
        init();
        if (debugMode) {
            con.println("Start");
            con.println("Console output:");
        }
        solve();
        finishTime = System.nanoTime();
        finishMem = Runtime.getRuntime().totalMemory();
        out.flush();
        if (debugMode) {
            int maxSymbols = 1000, c = 0;
            BufferedReader tbr = new BufferedReader(new FileReader("input.txt"));
            char[] a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println();
                con.println("File input:");
                con.print(a);
            }
            boolean left = true;
            for (int i = 0; i < maxSymbols; i++) left = left && a[i] != 0;
            if (left) con.println("...");
            else con.println();
            tbr = new BufferedReader(new FileReader("output.txt"));
            a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println();
                con.println("File output:");
                con.print(a);
            }
            left = true;
            for (int i = 0; i < maxSymbols; i++) left = left && a[i] != 0;
            if (left) con.println("...");
            else con.println();
            con.println("Time passed:  " + (finishTime - startTime) / 1000000000.0 + " sec");
            con.println("Memory used:  " + (finishMem - startMem) + " bytes");
            con.println("Total memory: " + Runtime.getRuntime().totalMemory() + " bytes");
        }
    }

    boolean tick(double x) {
        if (System.nanoTime() - tempTime > x) {
            tempTime = System.nanoTime();
            con.println("Tick at " + (tempTime - startTime) / 1000000000 + " sec");
            con.print("   ");
            return true;
        }
        return false;
    }

    void printTime() {
        con.println((System.nanoTime() - tempTime) + " nanos passed");
        tempTime = System.nanoTime();
    }

    static boolean debugMode = false;
    PrintStream con = System.out;

    void init() throws IOException {
        if (debugMode) {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new FileWriter("output.txt"));
        } else
            switch (IOMode) {
                case 0:
                    br = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(System.out);
                    break;
                case 1:
                    br = new BufferedReader(new FileReader(taskName + ".in"));
                    out = new PrintWriter(new FileWriter(taskName + ".out"));
                    break;
                case 2:
                    br = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    out = new PrintWriter(new FileWriter("input.txt"));
                    break;
            }
    }

    BufferedReader br;
    PrintWriter out;
    StringTokenizer in;

    boolean hasMoreTokens() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return false;
            in = new StringTokenizer(line);
        }
        return true;
    }

    String nextString() throws IOException {
        return hasMoreTokens() ? in.nextToken() : null;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }
}