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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    enum State {
        IN_TOKEN,
        IN_QUOTE,
        FREE
    }
    public void solve(int testNumber, Reader in, OutputWriter out) {
        String s = in.nextLine();

        ArrayList<String> tokens = new ArrayList<String>();

        State state = State.FREE;
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if(c == '"'){
                if(state == State.IN_QUOTE){
                    state = State.FREE;
                    tokens.add(sb.toString());
                    sb = new StringBuilder();
                }
                else {
                    state = State.IN_QUOTE;
                }
                continue;
            }
            if(c == ' '){
                if(state == State.IN_QUOTE){
                    sb.append(' ');
                }
                if(state == State.IN_TOKEN) {
                    if(sb.length() > 0) {
                        tokens.add(sb.toString());
                        sb = new StringBuilder();
                    }
                }
                continue;
            }
            if(state == State.FREE){
                state = State.IN_TOKEN;
            }
            sb.append(c);
        }
        if(sb.length() > 0) {
            tokens.add(sb.toString());
        }

        for (String token : tokens) {
            out.println("<", token, ">");
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

    public String nextLine() {
        tokenizer = null;
        return readLine();
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

    public void print(Object... objects){
        for (Object object : objects) {
            print(object);
        }
    }

    public void println(Object... objects){
        print(objects);
        super.println();
    }
}