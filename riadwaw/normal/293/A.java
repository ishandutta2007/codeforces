import java.io.InputStreamReader;
import java.io.IOException;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        String s = in.nextString();
        String t = in.nextString();
        int both  = 0;
        int first = 0;
        int second = 0;
        for(int i = 0; i < 2 * n; ++i){
            if(s.charAt(i) == '1' && t.charAt(i) == '1'){
                both++;
            }
            if(s.charAt(i) == '0' && t.charAt(i) == '1'){
                second++;
            }
            if(s.charAt(i) == '1' && t.charAt(i) == '0'){
                first++;
            }
        }

        int fi = 0;
        int se = 0;

        while(true){
            if(both == 0 && second == 0 && first == 0){
                break;
            }
            if(both > 0) {
                ++fi;
                --both;
            }
            else if(first > 0) {
                ++fi;
                --first;
            }
            else {
                --second;
            }

            if(both == 0 && second == 0 && first == 0){
                break;
            }
            if(both > 0) {
                ++se;
                --both;
            }
            else if(second > 0) {
                ++se;
                --second;
            }
            else {
                --first;
            }
            //System.out.println(fi + " " + se);
        }


        if(fi > se) {
            out.println("First");
        }
        if(fi < se) {
            out.println("Second");
        }

        if(fi == se) {
            out.println("Draw");
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