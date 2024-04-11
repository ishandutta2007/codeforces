import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.StringTokenizer;

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
        int x = in.nextInt();
        ArrayList<Pair<Integer, Integer>>[] candies = new ArrayList[2];
        ArrayList<Pair<Integer, Integer>>[] candies2 = new ArrayList[2];
        for(int i = 0; i < 2; ++i) {
            candies[i] = new ArrayList<Pair<Integer, Integer>>();
            candies2[i] = new ArrayList<Pair<Integer, Integer>>();
        }
        for(int i = 0; i < n; ++i) {
            int t = in.nextInt();
            int h = in.nextInt();
            int m = in.nextInt();
            candies[t].add(new Pair<Integer, Integer>(h, m));
            candies2[1 - t].add(new Pair<Integer, Integer>(h, m));
        }

        int res = solve(x, candies);
        res = Math.max(res, solve(x, candies2));
        out.println(res);

    }

    private int solve(int x, ArrayList<Pair<Integer, Integer>>[] candies) {
        int cur = 1;
        int ans = 0;
        while (true) {
            cur = 1 - cur;
            Pair<Integer, Integer> best = null;
            for (Pair<Integer, Integer> pair : candies[cur]) {
                if(pair.first > x) {
                    continue;
                }

                if(best == null || pair.second > best.second) {
                    best = pair;
                }

            }
            if(best == null) {
                return ans;
            }
            ans ++;
           // System.out.println(best);
            x += best.second;

            candies[cur].remove(best) ;
           // System.out.println(candies[0] + " " + candies[1]);
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

	public OutputWriter(Writer writer){
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