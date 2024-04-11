import java.io.InputStreamReader;
import java.io.IOException;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] d = new int[n];

        for(int i = 0; i < m; ++i){
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            ++d[a];
            ++d[b];
        }

        Counter<Integer> counter = new Counter<Integer>();

        for(int i = 0; i < n; ++i){
            counter.add(d[i]);
        }

        if(counter.get(2) == n){
            out.println("ring topology");
            return;
        }

        if(counter.get(2) == n - 2 && counter.get(1) == 2) {
            out.println("bus topology");
            return;
        }

        if(counter.get(1) == n - 1 && counter.get(n - 1) == 1) {
            out.println("star topology");
            return;
        }
        
        out.println("unknown topology");

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

class OutputWriter extends PrintWriter {

    public OutputWriter(OutputStream out) {
        super(out);
    }

    public OutputWriter(java.io.Writer writer){
        super(writer);
    }

    }

class Counter<T> extends TreeMap<T, Integer> {
    public void add(T key) {
        add(key, 1);
    }

    public void add(T key, int value) {
        put(key, get(key) + value);
    }

    public Integer get(Object key) {
        return containsKey(key) ? super.get(key) : 0;
    }

}