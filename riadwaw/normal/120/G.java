import java.io.*;
import java.util.*;
import java.math.*;

//created at 8:08 PM 10/20/11 by Abrackadabra

public class G {
    int IOMode = 2; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";

    void solve() throws IOException {
        int n = nextInt(), t = nextInt();
        int[][] a = new int[n][2], b = new int[n][2];
        for (int i = 0; i < n; i++) {
            a[i][0] = nextInt();
            b[i][0] = nextInt();
            a[i][1] = nextInt();
            b[i][1] = nextInt();
        }
        int m = nextInt();
        int[] c = new int[m];
        String[] w = new String[m];
        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 0; i < m; i++) {
            w[i] = nextString();
            c[i] = nextInt();
            q.add(i);
        }
        int[][] d = new int[n][m];
        int z = 0;
        ArrayList[] guessed = new ArrayList[n];
        for (int i = 0; i < n; i++)
            guessed[i] = new ArrayList();
        int tl = t;
        while (true) {
            if (q.size() == 0) break;
            int i = z % n;
            int j = z / n;
            int v = (j + 1) % 2;
            int k = q.poll();
            int g = Math.max(1, c[k] - a[i][j] - b[i][v] - d[i][k]);
            if (g <= tl) {
                guessed[i].add(w[k]);
                tl -= g;
                if (tl == 0) {
                    tl = t;
                    z = (z + 1) % (2 * n);
                }
            } else {
                d[i][k] += tl;
                tl = t;
                z = (z + 1) % (2 * n);
                q.add(k);
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(guessed[i].size() + " ");
            for (Object l : guessed[i])
                out.print(l.toString() + " ");
            out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new G().run();
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