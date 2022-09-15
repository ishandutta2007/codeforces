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
        int a = in.nextInt();
        int b = in.nextInt();
        String s = in.nextString();

        int x = 0;
        int y = 0;

        int[] dx = new int[] {0,0, -1, 1};
        int[] dy = new int[] {1, -1, 0, 0};
        String d = "UDLR";

        for(int i = 0; i < s.length(); ++i) {
            int dir = d.indexOf(s.charAt(i));
            x += dx[dir];
            y += dy[dir];
            //out.println(x + " " + y);
        }

        int endX = x;
        int endY = y;
        x = 0;
        y = 0;

        for(int i = 0; i < s.length(); ++i) {
            if((a == x) || (endX != 0 && (a - x) % endX == 0)) {
                if(b == y || (endY != 0 && (b - y) % endY == 0 )) {
                    int stepsX = endX == 0 ? Integer.MAX_VALUE : (a - x) / endX;
                    int stepsY = endY == 0 ? Integer.MAX_VALUE : (b - y) / endY;
                    //out.println(stepsX + " " + stepsY + " " + x + " " + y);
                    if(stepsX == stepsY || stepsX == Integer.MAX_VALUE || stepsY == Integer.MAX_VALUE) {
                        if(stepsX >= 0 && stepsY >= 0) {
                            out.println("Yes");
                            return;
                        }
                    }

                }
            }
            int dir = d.indexOf(s.charAt(i));
            x += dx[dir];
            y += dy[dir];
        }

        out.print("No");
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