import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {

    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        long[] ips = new long[n];
        for(int i = 0; i < n; ++i){
            ips[i] = ip2long(in.nextString());
        }
        HashSet<Long> currentIPS = new HashSet<Long>();
        for (long ip : ips) {
            currentIPS.add(ip);
        }
        int lastOK = 42;
        for(int i = 1; i <= 31; ++i){
            HashSet<Long> nextIPS = new HashSet<Long>();
            for (long ip : currentIPS) {
                nextIPS.add(ip / 2);
            }
            if(nextIPS.size() == k)
                lastOK = i;
            if(nextIPS.size() < k) {
                break;
            }
            currentIPS = nextIPS;
        }
        if(lastOK == 42){
            out.println(-1);
        }
        else {
            long ans = 0;
            for(int i = lastOK; i <= 31; ++i){
                ans |= 1L << i;
            }
            out.println(long2ip(ans));
        }
    }

    private String long2ip(long ans) {
        return StringUtils.join('.', new Long[]{
                ans >> 24,
                (ans >> 16) & 255,
                (ans >> 8) & 255,
                ans & 255
        });
    }

    private long ip2long(String s) {
        long ans = 0;
        for (String t : s.split("\\.")) {
            ans <<= 8;
            ans += Integer.parseInt(t);
        }
        return ans;
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

class StringUtils {
    public static String join(String delimiter, Object[] array) {
        StringBuilder buffer = new StringBuilder();
        for (Object object : array) {
            buffer.append(delimiter).append(object);
        }
        return buffer.substring(delimiter.length());
    }

    public static String join(char delimiter, Object[] array) {
        return join(String.valueOf(delimiter), array);
    }

    }