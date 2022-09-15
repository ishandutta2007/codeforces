import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.math.*;
import java.util.logging.StreamHandler;

//created at 8:38 PM 10/20/11 by Abrackadabra

public class H {
    int IOMode = 2; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";
    ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();

    int[] now = new int[22000 * 200];
    ArrayList<String> right = new ArrayList<String>();
    Map<String, Integer> rg = new HashMap<String, Integer>();

    int add(char[] a) {

        if (rg.containsKey(new String(a)))
            return rg.get(new String(a));
        int num = right.size();
        rg.put(new String(a), num);
        right.add(new String(a));
        return num;
    }

    boolean[] been;

    boolean dfs(int v) {
        if (v == -1)
            return true;
        if (been[v])
            return false;
        been[v] = true;
        for (Integer next : g.get(v)) {
            if (dfs(now[next])) {
                now[next] = v;
                return true;
            }
        }
        return false;
    }

    void solve() throws IOException {
        int n = nextInt();
        Arrays.fill(now, -1);
        String[] left = new String[n];
        for (int i = 0; i < n; ++i) {
            left[i] = nextString();
            g.add(new ArrayList<Integer>());
            char[][] str = new char[4][];
            for (int j = 0; j < 4; ++j)
                str[j] = new char[j + 1];
            int T = left[i].length();
            for (int a = 0; a < T; ++a) {
                str[0][0] = str[1][0] = str[2][0] = str[3][0] = left[i].charAt(a);
                g.get(i).add(add(str[0]));
                for (int b = a + 1; b < T ; ++b) {
                    str[1][1] = str[2][1] = str[3][1] = left[i].charAt(b);
                    g.get(i).add(add(str[1]));
                    for (int c = b + 1; c < T; ++c) {
                        str[2][2] = str[3][2] = left[i].charAt(c);
                        g.get(i).add(add(str[2]));
                        for (int d = c + 1; d < T; ++d) {
                            str[3][3] = left[i].charAt(d);
                            g.get(i).add(add(str[3]));
                        }
                    }
                }
            }


        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            been = new boolean[n];
            if (dfs(i))
                ++cnt;
        }

        if (cnt == n) {
            String[] ans = new String[n];
            for (int idr = 0; idr < right.size(); ++idr)
                if (now[idr] != -1)
                    ans[now[idr]] = new String(right.get(idr));
            for (String tt : ans)
                out.println(tt);
        } else
            out.println(-1);

    }

    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new H().run();
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