import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
        TaskB1 solver = new TaskB1();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB1 {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int x = in.nextInt() - 1;
        int[] a = in.nextIntArray(n);
        boolean[] hasPrevious = new boolean[n];
        for(int i = 0; i < n; ++i){
            if(a[i] != 0)
                hasPrevious[a[i] - 1] = true;
        }
        ArrayList<Integer> chunks = new ArrayList<Integer>();
        int cleverLength = 0;
        int first = x;
        while (a[first] != 0) {
            cleverLength++;
            first = a[first] - 1;
        }
        for(int i = 0; i < n; ++i) {
            if(!hasPrevious[i]) {
                int cur = i;
                int len = 1;
                boolean hasClever = x == cur;

                while(a[cur] != 0) {
                    ++len;
                    cur = a[cur] - 1;
                    hasClever |= x == cur;
                }

                if(!hasClever)
                    chunks.add(len);

            }
        }

        //out.println(chunks);

        boolean[] possible = new boolean[n + 1];
        possible[0] = true;
        for(int i = 0; i < chunks.size(); ++i){
            int chunk = chunks.get(i);
            for(int j = n - chunk; j >= 0; --j) {
                if(possible[j])
                    possible[j + chunk] = true;
            }
        }

        for(int i = 0; i <= n; ++i) {
            if(possible[i])
                out.println(i + cleverLength + 1);
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

    public int[] nextIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextInt();
        }
        return array;
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