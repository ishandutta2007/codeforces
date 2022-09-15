import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
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
        int[] a = in.nextIntArray(2 * n);
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
        for(int i = 0; i < 2 * n; ++i) {
            if(!map.containsKey(a[i]))
                map.put(a[i], new ArrayList<Integer>());

            map.get(a[i]).add(i);
        }

        int oneTime = 0;
        int twoTimes = 0;

        int where = 1;
        int[] rest = new int[]{n, n};

        int[] ans = new int[2 * n];

        for (Map.Entry<Integer, ArrayList<Integer>> entry : map.entrySet()) {
            if(entry.getValue().size() >= 2) {
                ans[entry.getValue().get(0)] = 1;
                ans[entry.getValue().get(1)] = 2;
                --rest[0];
                --rest[1];
                ++twoTimes;
            }
            else {

                ans[entry.getValue().get(0)] = where;
                --rest[where - 1];
                where = 3 - where;
                ++oneTime;
            }

        }

        //out.println(Arrays.toString(ans) + " " + Arrays.toString(rest));


        out.println((twoTimes + oneTime / 2) * (twoTimes + (oneTime + 1) / 2));

        for(int i = 0; i < 2 * n; ++i) {
            if(ans[i] != 0) {
                out.print(ans[i] + " ");
            }
            else if(rest[0] > 0) {
                --rest[0];
                out.println("1 ");
            }
            else {
                out.print("2 ");
            }
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