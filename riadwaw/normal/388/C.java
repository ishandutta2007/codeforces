import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.Collections;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int stacks = in.nextInt();
        int sum1 = 0, sum2 = 0;
        ArrayList<Integer> realGame = new ArrayList<Integer>();
        for(int i = 0; i < stacks; ++i) {
            int inGroup = in.nextInt();
            int[] group = in.nextIntArray(inGroup);
            for(int j = 0; j < inGroup / 2; ++j) {
                sum1 += group[j];
            }
            int start = inGroup / 2;
            if(inGroup % 2 == 1) {
                realGame.add(group[start]);
                ++start;
            }
            for(int j = start; j < inGroup; ++j) {
                sum2 += group[j];
            }
        }
        Collections.sort(realGame, Collections.reverseOrder());

        boolean first = true;
        for(int number: realGame) {
            if(first)
                sum1 += number;
            else
                sum2 += number;
            first = !first;
        }
        out.println(sum1 + " " + sum2);
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