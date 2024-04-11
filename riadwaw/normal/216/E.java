import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;
import java.util.InputMismatchException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    long ansFor0(int[] a){
        long ans = 0;
        int cur = 0;
        for(int c: a){
            if(c == 0){
                ++cur;
                ans += cur;
            }
            else
                cur = 0;
        }
        return ans;
    }
	public void solve(int testNumber, Reader in, PrintWriter out) {
        int k = in.nextInt();
        int b = in.nextInt();
        int n = in.nextInt();
        int[] a = in.nextIntArray(n);

        long ans = 0;
        if(b == 0){

            ans = ansFor0(a);
        }
        else{
            long toSubstruct = 0;
            if(b == k - 1){
                toSubstruct = ansFor0(a);
                b = 0;
            }
            ans -= toSubstruct;
            Map<Integer, Integer> map = new TreeMap<Integer, Integer>();

            map.put(0, 1);
            int cur = 0;
            for(int c: a){
                cur += c;
                cur %= k - 1;
                if(map.containsKey((cur - b + k - 1) % (k - 1)))
                    ans += map.get((cur - b + k - 1) % (k - 1));

                if(map.containsKey(cur))
                    map.put(cur, map.get(cur) + 1);
                else
                    map.put(cur, 1);
            }

        }

        out.print(ans);
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