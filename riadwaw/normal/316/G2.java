import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.HashSet;
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
        TaskG1 solver = new TaskG1();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskG1 {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        String s = in.nextString();
        StringHash hashes = new SimpleInt64StringHash(s);

        int n = in.nextInt();

        int answer = 0;



        StringHash[] ts = new StringHash[n];
        int[] ls = new int[n];
        int[] rs = new int[n];
        for(int i = 0; i < n; ++i) {
            ts[i] = new SimpleInt64StringHash(in.nextString());
            ls[i] = in.nextInt();
            rs[i] = in.nextInt();
        }

        for(int len = 1; len <= s.length(); ++len) {

            Set<Long> availableStrings = new HashSet<Long>();
            for(int i = 0; i + len <= s.length(); ++i) {
                availableStrings.add(hashes.hash(i, i + len));
            }


            for(int i = 0; i < n; ++i){
                Counter<Long> timesAppeared = new Counter<Long>();

                StringHash inner = ts[i];
                int l = ls[i];
                int r = rs[i];

                for(int j = 0; j + len <= inner.length(); ++j)  {
                    timesAppeared.add(inner.hash(j, j + len));
                }

                if(l == 0) {
                    for (Map.Entry<Long, Long> entry : timesAppeared.entrySet()) {
                        if(entry.getValue() > r) {
                            availableStrings.remove(entry.getKey());
                        }
                    }
                }
                else {
                    Set<Long> nextStrings = new HashSet<Long>();
                    for (Map.Entry<Long, Long> entry : timesAppeared.entrySet()) {

                        if(entry.getValue() >= l && entry.getValue() <= r && availableStrings.contains(entry.getKey()))
                            nextStrings.add(entry.getKey());
                    }
                    availableStrings = nextStrings;
                }

            }

            answer += availableStrings.size();
        }

        out.println(answer);
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

interface StringHash {

    public long hash(int from, int to);

    public int length();

}

class SimpleInt64StringHash extends AbstractStringHash {
    private long[] hash;
    private static long[] powers;
    public static long multiplier = 97;

    public SimpleInt64StringHash(CharSequence string) {
        int length = string.length();
        ensureLength(length);
        hash = new long[length + 1];
        hash[0] = 0;
        for (int i = 0; i < length; ++i) {
            hash[i + 1] = hash[i] * multiplier + string.charAt(i);
        }
    }

    private static void ensureLength(int length) {
        if(powers != null && length + 1 <= powers.length)
            return;
        powers = new long[length + 1];
        powers[0] = 1;

        for (int i = 1; i <= length; ++i) {
            powers[i] = powers[i - 1] * multiplier;
        }
    }

    public long hash(int from, int to) {
        return hash[to] - hash[from] * powers[to - from];
    }

    public int length() {
        return hash.length - 1;
    }
}

class Counter<T> extends HashMap<T, Long> {
    public void add(T key) {
        add(key, 1);
    }

    public void add(T key, long value) {
        put(key, get(key) + value);
    }

    public Long get(Object key) {
        return containsKey(key) ? super.get(key) : 0;
    }

}

abstract class AbstractStringHash implements StringHash {

    }