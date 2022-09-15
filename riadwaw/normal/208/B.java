import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author RiaD
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Reader in = new Reader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    String[] a;

    Map<Integer, Boolean> mem = new HashMap<Integer, Boolean>();
    boolean ans(int n, int n1, int n2, int n3){
        if(n == 1)
            return true;
        int hash = n * 1000000 + n1 * 10000 + n2 * 100 + n3;
        if(mem.containsKey(hash))
            return mem.get(hash);

        boolean to3 = (n >= 4 && good(a[n3], a[n - 4])) ?  ans(n - 1,n3, n1,n2): false;

        if(to3){
            mem.put(hash, true);
            return true;
        }

        boolean  res = good(a[n2], a[n3]) ? ans(n - 1, n - 4, n1, n3) : false;

        mem.put(hash, res);
        return res;

    }

    private boolean good(String s, String s1) {
        return s.charAt(0) == s1.charAt(0) || s1.charAt(1) == s.charAt(1);
    }

    public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt();
        a = new String[n];
        for(int i = 0; i < n; ++i){
            a[i] = in.nextString();
        }

        out.print(ans(n, n-3,n-2, n-1)?"YES":"NO");
    }

}

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Reader(BufferedReader reader) {
        this.reader = reader;
    }

    public Reader(InputStream stream) {
        this(new BufferedReader(new InputStreamReader(stream)));
    }

    public String nextString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}