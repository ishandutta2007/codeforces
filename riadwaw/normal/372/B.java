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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        char[][] s = new char[n][m];
        for(int i = 0; i < n; ++i) {
            s[i] = in.nextString().toCharArray();
        }
        int[][][][] counts = new int[n + 1][m + 1][n + 1][m + 1];
        for(int x1 = 0; x1 < n; ++x1) {
            for(int x2 = x1 + 1; x2 <= n; ++x2) {
                for(int y1 = 0; y1 < m; ++y1) {

                    for(int y2 = y1 + 1; y2 <= m; ++y2) {
                        boolean good = true;
                        for(int j = x1; j < x2; ++j) {
                            if(s[j][y2 - 1] == '1') {
                                good = false;
                                break;
                            }
                        }

                        if(!good)
                            break;
                        ++counts[x1][y1][x2][y2];
                    }
                }
            }
        }


        //System.err.println(Arrays.deepToString(counts[0][0]));

        for(int sx = 0; sx < n; ++sx) {
            for(int sy = 0; sy < m; ++sy) {
                for(int ex = sx + 1; ex <= n; ++ex) {
                    for(int ey = sy + 1; ey <= m; ++ey) {
                        counts[sx][sy][ex][ey] += counts[sx][sy][ex - 1][ey] + counts[sx][sy][ex][ey - 1] - counts[sx][sy][ex - 1][ey - 1];
                    }
                }
            }
        }

        for(int ex = 1; ex <= n; ++ex) {
            for(int ey = 1; ey <= m; ++ey) {
                for(int sx = ex - 1; sx >= 0; --sx) {
                    for(int sy = ey - 1; sy >= 0; --sy) {
                        counts[sx][sy][ex][ey] += counts[sx + 1][sy][ex][ey] + counts[sx][sy + 1][ex][ey] - counts[sx + 1][sy + 1][ex][ey];
                        //counts[sx][sy][ex][ey] += counts[sx][sy][ex - 1][ey] + counts[sx][sy][ex][ey - 1] - counts[sx][sy][ex - 1][ey - 1];
                    }
                }
            }
        }


        //System.err.println(Arrays.deepToString(counts[0][0]));

        for(int z = 0; z < q; ++z) {
            int sx = in.nextInt() - 1;
            int sy = in.nextInt() - 1;
            int ex = in.nextInt();
            int ey = in.nextInt();

            int ans = 0;
            out.println(counts[sx][sy][ex][ey]);
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