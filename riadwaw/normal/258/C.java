import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
    public final long mod = 1000000007;
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = in.nextIntArray(n);

        int cntAtLeast[] = new int[100001];

        for(int i = 0; i < n; ++i){
            cntAtLeast[a[i]]++;
        }
        for(int i = 99999; i >= 0; --i){
            cntAtLeast[i] += cntAtLeast[i + 1];
        }

        long ans = 1;

        for(int max = 2; max <= 100000; ++max){
            List<Integer> list = IntegerUtils.getDivisors(max);
            Collections.sort(list, new ReverseComparator<Integer>());
            int variants = list.size();
            list.remove(0);

            long res = (IntegerUtils.power(variants, cntAtLeast[max], mod) - IntegerUtils.power(variants - 1, cntAtLeast[max], mod) + mod) % mod;
            int prev = cntAtLeast[max];
            for(int divisor: list){
                variants--;
                int cur = cntAtLeast[divisor] - prev;
                prev += cur;

                res *= IntegerUtils.power(variants, cur, mod);
                res %= mod;
            }
            //if (res > 0)
            //  out.println(max + " " + res);
            ans += res;
            ans %= mod;
        }

        out.println(ans);

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

class IntegerUtils {

    public static ArrayList<Integer> getDivisors(int n){
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 1; i * i <= n;++i){
            if(n % i == 0){
                list.add(i);
                if(i * i != n)
                    list.add(n / i);
            }
        }
        return list;
    }

    public static long power(long base, long power, long mod) {
        long result = 1 % mod;
        base %= mod;
        while (power > 0) {
            if (power % 2 == 1) {
                result *= base;
                result %= mod;
            }
            base *= base;
            base %= mod;
            power >>= 1;
        }
        return result;
    }

    }

class ReverseComparator<T extends Comparable<T>> implements Comparator<T> {
    public int compare(T t, T t1) {
        return t1.compareTo(t);
    }
}