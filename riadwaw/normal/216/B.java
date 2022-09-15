import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    ArrayList<Integer> g[];
    boolean[] used;
    boolean[] deleted;
    boolean dfs(int start, int v, boolean parity, boolean starts){
       // System.err.println(start + " " + v + " " + parity + " " + starts);
        if(start == v && !starts)
            return parity;
        if(used[v])
            return false;
        used[v] = true;
        for(int to: g[v]){
            if(!deleted[to])
                if(dfs(start, to, !parity, false))
                    return true;
        }
        return false;
    }
	public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        deleted = new boolean[n];
        for(int i = 0; i < n;++i){
            g[i] = new ArrayList<Integer>();
        }
        int m = in.nextInt();
        for(int i = 0; i < m; ++i){
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }

        int ans = n;
        for(int i = 0; i < n;++i){
            used = new boolean[n];
            if(dfs(i,i,false, true)){
                ans--;
                deleted[i] = true;
            }
        }
        out.print(n - ans/2*2);
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