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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] matrix = new int[n][];
        for(int i = 0; i < n; ++i)
            matrix[i] = in.nextIntArray(m);
        
        int l = 0, r = 1000000001;
        while(r - l > 1) {
            int c = (l + r) / 2;
            if(exists(c, n, m, matrix)) {
                l = c;
            }
            else 
                r = c;
            
        }
        
        out.println(l);
    }

    private boolean exists(int c, int n, int m, int[][] matrix) {
        boolean[][] pairs = new boolean[m][m];
        for(int i = 0; i < n; ++i) {
            ArrayList<Integer> big = new ArrayList<Integer>();
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] >= c) {
                    big.add(j);
                }
            }
            for (int a : big) {
                for (int b : big) {
                    if(a == b)
                        continue;
                    if(pairs[a][b]) {
                        return true;
                    }
                    else
                        pairs[a][b] = true;
                }

            }
        }
        return false;
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

    public int[] nextIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextInt();
        }
        return array;
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