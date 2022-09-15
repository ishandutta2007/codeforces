
import java.io.*;
import java.util.*;

//created at 8:13 PM 10/13/11 by Abrackadabra
public class Java {

    int IOMode = 0; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";
    Hashtable <Integer, ArrayList<Integer>> ht = new Hashtable<Integer, ArrayList<Integer>>();
    boolean[] used;
    Hashtable<Integer, HashSet<Integer>> ans = new Hashtable<Integer, HashSet<Integer>>();
    TreeSet<Integer> ts = new TreeSet<Integer>();
    int[] level;
    int time = 0;
    int[] tin;

    int dfs(int v, int p) {
        int ret= tin[v] = time++;
        used[v] = true;

        if(v!=0)
                    level[v]=level[p]+1;
        for (Integer to : ht.get(v)) {
            if(p==to)
                continue;
            if (!used[to]) {
                
                int resto = dfs(to, v);
                ret=Math.min(ret,resto);
                if(resto>tin[v]){
                    out.println(0);
                    out.flush();
                    System.exit(0);
                }
                ans.get(v).add(to);
            }
            else
                ret=Math.min(ret,tin[to]);
        }
        return ret;
    }

    void solve() throws IOException {
        int n = nextInt(), m = nextInt();
        tin=new int [n];
        used = new boolean[n];
        level = new int[n];
        for (int i = 0; i < n; i++) {
            ht.put(i, new ArrayList<Integer>());
            ans.put(i, new HashSet<Integer>());
        }
        for (int i = 0; i < m; ++i) {
            int a = nextInt() - 1, b = nextInt() - 1;
            ht.get(a).add(b);
            ht.get(b).add(a);
        }
        dfs(0, 0);
        for (int i = 0; i < n; ++i) {
            for (Integer to : ht.get(i)) {
                if (!ans.get(i).contains(to) && !ans.get(to).contains(i)) {
                    if (level[i] > level[to]) {
                        ans.get(i).add(to);
                    } else {
                        ans.get(to).add(i);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (Integer to : ans.get(i)) {
                out.println(i+1+" "+(to+1));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) {
            debugMode = true;
        }
        new Java().run();
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
            BufferedReader tbr = new BufferedReader(new FileReader("/home/riad/Dropbox/NetBeansProjects/CodeForces/input.txt"));
            char[] a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println();
                con.println("File input:");
                con.print(a);
            }
            boolean left = true;
            for (int i = 0; i < maxSymbols; i++) {
                left = left && a[i] != 0;
            }
            if (left) {
                con.println("...");
            } else {
                con.println();
            }
            tbr = new BufferedReader(new FileReader("output.txt"));
            a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println();
                con.println("File output:");
                con.print(a);
            }
            left = true;
            for (int i = 0; i < maxSymbols; i++) {
                left = left && a[i] != 0;
            }
            if (left) {
                con.println("...");
            } else {
                con.println();
            }
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
        } else {
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
    }
    BufferedReader br;
    PrintWriter out;
    StringTokenizer in;

    boolean hasMoreTokens() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return false;
            }
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