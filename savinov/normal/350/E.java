import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Evgeny Savinov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out)
    {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        if (k == n || m > n * (n - 1) / 2 - k + 1)
        {
            out.println("-1");
            return;
        }
        boolean [] marked = new boolean[n];
        int chosen = -1;
        for(int i = 0; i < k; ++i)
        {
            marked[in.nextInt() - 1] = true;
        }
        int [] order = new int[n];
        int s = 0;
        for(int i = 0; i < n; ++i)
            if (!marked[i]) order[s++] = i;
        for(int i = 0; i < n; ++i)
            if (marked[i]) order[s++] = i;
        for(int i = 0; i < n; ++i)
        {
            if (marked[i])
            {
                chosen = i;
                break;
            }
        }
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
            {
                int from = order[i], to = order[j];
                if (m == 0) break;
                if (from != chosen || !marked[to])
                {
                    out.println((from + 1) + " " + (to + 1));
                    --m;
                }
            }

    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
    }