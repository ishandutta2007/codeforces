import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Set;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        String s = in.nextString();
        int n = in.nextInt();
        Counter<Character> counter = new Counter<Character>();

        for(int i = 0; i < s.length(); ++i) {
            counter.add(s.charAt(i));
        }

        if(counter.size() > n){
            out.println(-1);
            return;
        }

        int l = 0;
        int r = 1111;
        while(r - l > 1) {
            int m = (l + r) / 2;
            int need = 0;
            for (Map.Entry<Character, Long> entry : counter.entrySet()) {
                long t = entry.getValue();
                need += (t + m - 1) / m;
            }
            if(need <= n) {
                r = m;
            }
            else
                l = m;
        }

        out.println(r);

        int m = r;
        int need = 0;
        for (Map.Entry<Character, Long> entry : counter.entrySet()) {
            long t = entry.getValue();
            long cur = (t + m - 1) / m;
            need += cur;
            
            for(long i = 0; i < cur; ++i){
                out.print(entry.getKey());
            }
        }
        
        for(int i = 0; i < n - need; ++i) {
            out.print('a');
        }
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

class Counter<T> extends HashMap<T, Long> {
    public void add(T key) {
        add(key, 1);
    }

    public void add(T key, long value) {
        put(key, get(key) + value);
    }

    public Long get(Object key) {
        return containsKey(key) ? super.get(key) : 0;
    }

}