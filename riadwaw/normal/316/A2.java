import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.HashSet;
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
        TaskA1 solver = new TaskA1();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA1 {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        String s = in.nextString();
        Set<Character> set = new HashSet<Character>();
        long ans = 1;
        int nulls = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
                set.add(s.charAt(i));
            if(s.charAt(i) == '?' && i == 0)
                ans *= 9;
            else if (s.charAt(i) == '?')
                ++nulls;
        }



        for(int i = 0; i < set.size(); ++i){
            if(i == 0 && s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
                ans *= 9;
            else
                ans *= 10 - i;
        }

        out.print(ans);
        for(int i = 0; i < nulls; ++i)
            out.print(0);
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