import java.io.*;
import java.util.*;
import java.math.*;

//created at 7:44 PM 10/13/11 by Abrackadabra

public class C {
    int IOMode = 0; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";

    void solve() throws IOException {
        int n = Integer.parseInt(nextString()), m = Integer.parseInt(nextString());
        String s = nextString();
        int min = 1000000;
        int[] best = new int[n];
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = s.charAt(i) - '0';
        for (int d = 0; d < 10; d++) {
            int[] b = new int[n];
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != d)
                    c++;
                b[i] = a[i];
            }
            c = Math.max(m - (n - c), 0);
            int C = 0;
            for (int q = 1; q < 10; q++) {
                for (int i = 0; i < n; i++) {
                    if (c == 0) break;
                    if (b[i] == d + q) {
                        b[i] = d;
                        c--;
                        C += q;
                    }
                }
                for (int i = n - 1; i >= 0; i--) {
                    if (c == 0) break;
                    if (b[i] == d - q) {
                        b[i] = d;
                        c--;
                        C += q;
                    }
                }
            }
            if (C < min) {
                min = C;
                best = b;
            }
            if (C == min) {
                boolean ch = false;
                for (int i = 0; i < n; i++) {
                    if (b[i] < best[i]) {
                        ch = true;
                        break;
                    }
                    if (b[i] > best[i]) break;
                }
                if (ch) best = b;
            }
        }
        out.println(min);
        for (int i = 0; i < n; i++)
            out.print(best[i]);
    }

    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new C().run();
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