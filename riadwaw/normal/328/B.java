import java.io.IOException;
import java.io.InputStreamReader;
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
        char[] s = in.nextString().toCharArray();
        char[] t = in.nextString().toCharArray();
        
        for(int i = 0; i < s.length; ++i){
            if(s[i] == '6')
                s[i] = '9';
            if(s[i] == '2')
                s[i] = '5';
        }

        for(int i = 0; i < t.length; ++i){
            if(t[i] == '6')
                t[i] = '9';
            if(t[i] == '2')
                t[i] = '5';
        }

        int[] need = new int[10];
        int[] have = new int[10];
        for(int i = 0; i < s.length; ++i)
            need[s[i] - '0'] ++;

        for(int i = 0; i < t.length; ++i) {
            have[t[i] - '0']++;
        }

        int pos = Integer.MAX_VALUE;

        for(int i = 0; i < 10 ;++ i){
            if(need[i] > 0){
                pos = Math.min(pos, have[i] / need[i]);
            }
        }
        
        out.println(pos);

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