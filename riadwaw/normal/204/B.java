import static java.util.Arrays.deepToString;

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.Entry;

public class B {

    static void solve() {
        int n = nextInt();
        Map<Integer, Integer> total = new TreeMap<>();
        Map<Integer, Integer> top = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            int c1 = nextInt(), c2 = nextInt();
            inc(total, c1);
            if (c2 != c1)
                inc(total, c2);
            inc(top, c1);
        }
        int ans = Integer.MAX_VALUE, need = (n + 1) / 2;
        for (Entry<Integer, Integer> e : total.entrySet()) {
            if (e.getValue() >= need)
                ans = Math.min(ans, Math.max(0, need - get(top, e.getKey())));
        }
        writer.println(ans != Integer.MAX_VALUE ? ans : -1);
    }

    static int get(Map<Integer, Integer> map, int x) {
        Integer val = map.get(x);
        return val != null ? val : 0;
    }

    static void inc(Map<Integer, Integer> map, int x) {
        Integer val = map.get(x);
        map.put(x, val != null ? val + 1 : 1);
    }

    public static void main(String[] args) throws Exception {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new PrintWriter(System.out);

        setTime();
        solve();
        printTime();
        printMemory();

        writer.close();
    }

    static BufferedReader reader;
    static PrintWriter writer;
    static StringTokenizer tok = new StringTokenizer("");
    static long systemTime;

    static void debug(Object... o) {
        System.err.println(deepToString(o));
    }

    static void setTime() {
        systemTime = System.currentTimeMillis();
    }

    static void printTime() {
        System.err.println("Time consumed: " + (System.currentTimeMillis() - systemTime));
    }

    static void printMemory() {
        System.err.println("Memory consumed: " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + "kb");
    }

    static String next() {
        while (!tok.hasMoreTokens()) {
            String w = null;
            try {
                w = reader.readLine();
            } catch (Exception e) {
                e.printStackTrace();
            }
            if (w == null)
                return null;
            tok = new StringTokenizer(w);
        }
        return tok.nextToken();
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static long nextLong() {
        return Long.parseLong(next());
    }

    static double nextDouble() {
        return Double.parseDouble(next());
    }

    static BigInteger nextBigInteger() {
        return new BigInteger(next());
    }
}