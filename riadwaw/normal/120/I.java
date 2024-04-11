import java.io.*;
import java.util.*;
import java.math.*;

//created at 10:32 PM 10/20/11 by Abrackadabra

public class I {
    int IOMode = 2; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";

    void solve() throws IOException {
        String[] seg = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010",
                "1111111", "1111011"};
        int[][] luck = new int[10][10];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 7; k++)
                    luck[i][j] += (seg[i].charAt(k) - '0') * (seg[j].charAt(k) - '0');
        char[] s = nextString().toCharArray();
        int[] dig = new int[s.length];
        for (int i = 0; i < dig.length; i++)
            dig[i] = s[i] - '0';
        int size = dig.length / 2;
        int mlr = 0;
        int lr = 0;
        for (int i = 2 * size - 1; i >= size; i--) {
            lr += luck[dig[i - size]][dig[i]];
            for (int j = dig[i] + 1; j < 10; j++) {
                if (luck[j][dig[i - size]] + mlr > lr) {
                    dig[i] = j;
                    int need = lr - luck[j][dig[i - size]];
                    for (int k = i + 1; k < 2 * size; k++) {
                        mlr -= luck[dig[k - size]][dig[k - size]];
                        for (int l = 0; l < 10; l++) {
                            if (mlr + luck[l][dig[k - size]] > need) {
                                dig[k] = l;
                                break;
                            }
                        }
                        need -= luck[dig[k - size]][dig[k]];
                    }
                    for (int digit : dig)
                        out.print(digit);
                    out.println();
                    return;
                }
            }
            mlr += luck[dig[i - size]][dig[i - size]];
        }
        int L = 0;
        for (int i = 0; i < size; i++)
            L += luck[dig[i]][dig[i + size]];
        int ml = 0;
        for (int i = 0; i < size; i++)
            ml += luck[dig[i]][dig[i]];
        for (int i = size - 1; i >= 0; i--) {
            ml -= luck[dig[i]][dig[i]];
            for (int j = dig[i] + 1; j < 10; j++) {
                if (ml + luck[j][j] > L) {
                    dig[i] = j;
                    int need = L;
                    ml += luck[j][j];
                    for (int k = i + 1; k < size; k++) {
                        ml -= 7;
                        for (int l = 0; l < 10; l++) {
                            if (ml + luck[l][l] > need) {
                                dig[k] = l;
                                ml += luck[l][l];
                                break;
                            }
                        }
                    }
                    mlr = ml;
                    for (int k = size; k < 2 * size; k++) {
                        mlr -= luck[dig[k - size]][dig[k - size]];
                        for (int l = 0; l < 10; l++) {
                            if (mlr + luck[l][dig[k - size]] > need) {
                                dig[k] = l;
                                break;
                            }
                        }
                        need -= luck[dig[k - size]][dig[k]];
                    }
                    for (int digit : dig)
                        out.print(digit);
                    out.println();
                    return;
                }
            }
            ml += 7;
        }
        out.println(-1);
    }

    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new I().run();
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