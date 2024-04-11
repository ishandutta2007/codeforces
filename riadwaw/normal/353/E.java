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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        String s = in.nextString();
        int n = s.length();
        if(s.charAt(0) == s.charAt(n - 1)) {
            for(int i = 0; i < n; ++i) {
                if(s.charAt(i) != s.charAt(i + 1)) {
                    s = s.substring(i + 1) + s.substring(0, i + 1);
                    break;
                }
            }
        }

        ArrayList<Integer> sizes = new ArrayList<Integer>();
        int ans = 0;
        int start = 0;
        for(int i = 0; i <= n; ++i) {
            if(i == n || s.charAt(i) != s.charAt(start)) {
                sizes.add(i - start);
                if(i - start > 1)
                    ++ans;
                start = i;
            }
        }

        ArrayList<Integer> groups = new ArrayList<Integer>();

        start = 0;
        for(int i = 0; i <= sizes.size(); ++i) {
            if(i == sizes.size() || sizes.get(i) != 1) {
                int length = i - start;
                if(length > 0)
                    groups.add(length);
                start = i + 1;
            }
        }



        if(groups.size() > 1 && sizes.get(0) == 1 && sizes.get(sizes.size() - 1) == 1) {
            groups.set(0, groups.get(groups.size() - 1) + groups.get(0));
            groups.remove(groups.size() - 1);
        } 
        for (int group : groups) {
            ans += group / 2;
        }
        out.println(ans);
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