import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int paths = in.nextInt();
        int n = 21;
        int[] pows = new int[20];
        ArrayList<Pair<Integer, Integer>> edges = new ArrayList<Pair<Integer, Integer>>();
        for(int i = 0; i < 20; ++i) {
            pows[i] = 1 + i;
        }
        for(int i = 0; i + 1 < pows.length; ++i) {
            edges.add(new Pair<Integer, Integer>(n, pows[i]));
            edges.add(new Pair<Integer, Integer>(n, pows[i + 1]));
            ++n;
            edges.add(new Pair<Integer, Integer>(n, pows[i]));
            edges.add(new Pair<Integer, Integer>(n, pows[i + 1]));
            ++n;
            edges.add(new Pair<Integer, Integer>(n, pows[i]));
            edges.add(new Pair<Integer, Integer>(n, pows[i + 1]));
            ++n;
        }
        ArrayList<Integer> digits = new ArrayList<Integer>();
        while (paths > 0) {
            digits.add(paths % 3);
            paths /= 3;
        }
        for(int i = 0; i < digits.size(); ++i) {


            if(digits.get(i) == 1) {
                int prev = 0;
                for(int j = 0; j < 40 - i * 2; ++j) {
                    edges.add(new Pair<Integer, Integer>(prev, n));
                    prev = n;
                    ++n;
                }
                edges.add(new Pair<Integer, Integer>(prev, pows[i]));
            }
            if(digits.get(i) == 2) {
                int prev = 0;

                int firstAfter = n + 1;
                for(int j = 0; j < 40 - i * 2; ++j) {
                    edges.add(new Pair<Integer, Integer>(prev, n));
                    prev = n;
                    ++n;
                }
                edges.add(new Pair<Integer, Integer>(prev, pows[i]));
                edges.add(new Pair<Integer, Integer>(0, n));
                edges.add(new Pair<Integer, Integer>(n, firstAfter));
                ++n;
            }
        }


        //for (Pair<Integer, Integer> edge : edges) {
          //  out.println(edge.first + " " +edge.second);
        //}
        out.println(n);
        char[][] ans = new char[n][n];
        for(int i = 0; i < n; ++i)
            Arrays.fill(ans[i], 'N');
        for(int i = 0; i < edges.size(); ++i) {
            ans[edges.get(i).first][edges.get(i).second] = 'Y';
            ans[edges.get(i).second][edges.get(i).first] = 'Y';
        }
        for(int i = 0; i < n; ++i)
            out.println(new String(ans[i]));
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