import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
        int currentStrength = in.nextInt();
        int n = in.nextInt();
        Pair<Integer, Integer>[] dragons = new Pair[n];
        for(int i = 0; i < n; ++i) {
            dragons[i] = new Pair<Integer, Integer>(in.nextInt(), in.nextInt());
        }
        Arrays.sort(dragons);

        for(int i = 0; i < n; ++i) {
            if(currentStrength <= dragons[i].first) {
                out.println("NO");
                return;
            }
            currentStrength += dragons[i].second;
        }

        out.println("YES");
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

class Pair<F, S> implements Comparable<Pair<F, S>> {

    public F first;
    public S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pair<F, S> other) {
        int res = ((Comparable<F>) first).compareTo(other.first);
        if (res != 0) {
            return res;
        }
        return ((Comparable<S>) second).compareTo(other.second);
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        Pair pair = (Pair) o;

        if (first != null ? !first.equals(pair.first) : pair.first != null) {
            return false;
        }
        if (second != null ? !second.equals(pair.second) : pair.second != null) {
            return false;
        }

        return true;
    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }
}