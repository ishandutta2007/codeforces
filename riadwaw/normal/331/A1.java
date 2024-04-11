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
		TaskA1 solver = new TaskA1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA1 {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = in.nextIntArray(n);
        long[] sumPositive = new long[n + 1];

        HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();

        for(int i = 0; i < n; ++i){
            sumPositive[i + 1] = sumPositive[i] + Math.max(a[i], 0);
            if(!map.containsKey(a[i])) {
                map.put(a[i], new ArrayList<Integer>());
            }
            map.get(a[i]).add(i);
        }

        long bestRes = Long.MIN_VALUE;
        int bestNumber = 0;

        for (Map.Entry<Integer, ArrayList<Integer>> entry : map.entrySet()) {
            if(entry.getValue().size() < 2)
                continue;

            int last = entry.getValue().get(entry.getValue().size() - 1);
            int first = entry.getValue().get(0);
            long sum = sumPositive[last] - sumPositive[first + 1] + 2 * entry.getKey();

            if(sum > bestRes) {
                bestRes = sum;
                bestNumber = entry.getKey();
            }
        }

        int last = map.get(bestNumber).get(map.get(bestNumber).size() - 1);
        int first = map.get(bestNumber).get(0);

        ArrayList<Integer> toCut = new ArrayList<Integer>();

        for(int i = 0; i < n; ++i) {
            if(i < first || i > last || (a[i] < 0 && i != last && i != first)) {
                toCut.add(i);
            }
        }

        out.println(bestRes + " " + toCut.size());
        for (Integer integer : toCut) {
            out.print(integer + 1 + " ");
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