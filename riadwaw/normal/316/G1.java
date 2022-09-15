import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
        StringHash hashes = new TwoIntStringHash(s);

        int n = in.nextInt();


        Set<Long> availableStrings = new HashSet<Long>();
        for(int i = 0; i < s.length(); ++i) {
            for(int j = i + 1; j <= s.length(); ++j)
                availableStrings.add(hashes.hash(i, j));
        }


        for(int i = 0; i < n; ++i){
            Counter<Long> timesAppeared = new Counter<Long>();
            String t = in.nextString();

            int l = in.nextInt();
            int r = in.nextInt();
            StringHash inner = new TwoIntStringHash(t);

            for(int j = 0; j < inner.length(); ++j)
                for(int k = j + 1; k <= inner.length(); ++k) {
                    timesAppeared.add(inner.hash(j, k));
                }

            Set<Long> nextStrings = new HashSet<Long>();
            for (Long string : availableStrings) {
                if(timesAppeared.get(string) >= l && timesAppeared.get(string) <= r)
                    nextStrings.add(string);
            }
            availableStrings = nextStrings;
        }



        out.println(availableStrings.size());
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

class TwoIntStringHash extends AbstractStringHash {
    private long[][] hash;
    private static long multiplier = 97;
    private static int[] mods;

    private static long[][] powers = new long[2][];

    private static int genPrime(Random random) {
        return (int) IntegerUtils.getNextPrime(random.nextInt((int) 1e9) + (int) (1e9));
    }

    static {
        Random random = new Random();
        mods = new int[]{genPrime(random), genPrime(random)};
    }

    public TwoIntStringHash(CharSequence string) {
        int length = string.length();
        ensureLength(length);
        hash = new long[2][length + 1];
        for (int i = 0; i < 2; ++i) {
            hash[i][0] = 0;
            for (int j = 0; j < length; ++j) {
                hash[i][j + 1] = (hash[i][j] * multiplier + string.charAt(j)) % mods[i];
            }
        }
    }

    private void ensureLength(int length) {
        powers = new long[2][length + 1];
        for (int i = 0; i < 2; ++i) {
            powers[i][0] = 1;
            for (int j = 1; j <= length; ++j) {
                powers[i][j] = (powers[i][j - 1] * multiplier) % mods[i];
            }
        }
    }

    public long hash(int from, int to) {
        return oneHash(from, to, 0) * (1L << 32) + oneHash(from, to, 1);
    }

    private long oneHash(int from, int to, int i) {
        return (hash[i][to] - hash[i][from] * powers[i][to - from] % mods[i] + mods[i]) % mods[i];
    }

    public int length() {
        return hash[0].length - 1;
    }
}

class Counter<T> extends TreeMap<T, Long> {
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

class IntegerUtils {

    public static boolean isPrime(long number) {
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static long getNextPrime(long n) {
        while (true) {
            ++n;
            if (isPrime(n)) {
                return n;
            }
        }
    }
}