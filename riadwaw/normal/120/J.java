import java.io.*;
import java.util.*;
import java.math.*;

//created at 9:07 PM 10/20/11 by Abrackadabra

public class J {
    int IOMode = 2; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";

    void solve() throws IOException {
        int n = nextInt();
        TreeMap<Double, Integer> tm = new TreeMap<Double, Integer>();
        int[][] a = new int[n][2];
        int[] k = new int[n];
        for (int i = 0; i < n; i++) {
            int x = nextInt(), y = nextInt();
            int t = 0;
            if (x < 0) t = 1;
            if (y < 0) t = 2;
            if (x < 0 && y < 0) t = 3;
            x = Math.abs(x);
            y = Math.abs(y);
            k[i] = t;
            a[i][0] = x;
            a[i][1] = y;
        }
        for (int i = 0; i < n; i++) {
            double l = Math.sqrt((a[i][0] + 1000000.0) * (a[i][0] + 1000000.0) + (a[i][1] + 1000000.0) * (a[i][1] + 1000000.0));
            while (tm.containsKey(l)) l += Math.random();
            tm.put(l, i);
        }
        int[] s = new int[n];
        int c = 0;
        for (Map.Entry<Double, Integer> e : tm.entrySet()) {
            s[c] = e.getValue();
            c++;
        }
        int fo = 300;
        double min = 10000000.0;
        int A = -1, B = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < fo; j++) {
                if (i + j >= n) break;
                double l = Math.sqrt((a[s[i]][0] - a[s[i + j]][0]) * (a[s[i]][0] - a[s[i + j]][0]) +
                (a[s[i]][1] - a[s[i + j]][1]) * (a[s[i]][1] - a[s[i + j]][1]));
                if (l < min) {
                    min = l;
                    A = i;
                    B = i + j;
                }
            }
        }
        //k[s[B]] = (k[s[B]] + 3) % 4;
        switch (k[s[B]]) {
            case 0: k[s[B]] = 3; break;
            case 1: k[s[B]] = 2; break;
            case 2: k[s[B]] = 1; break;
            case 3: k[s[B]] = 0; break;
        }
        out.println((s[A] + 1) + " " + (k[s[A]] + 1) + " " + (s[B] + 1) + " " + (k[s[B]] + 1));
        //out.println(k[s[B]]);
        //out.println(min);
    }

    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new J().run();
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