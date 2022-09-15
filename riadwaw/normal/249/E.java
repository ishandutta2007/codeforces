import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        TaskE solver = new TaskE();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
}

class TaskE {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int x1 = in.nextInt() -1;
        int y1 = in.nextInt() -1;
        int x2 = in.nextInt() ;
        int y2 = in.nextInt() ;

        BigInteger ans = ans(x2, y2).add(ans(x1,  y1)).subtract(ans(x1, y2)).subtract(ans(x2, y1));
        out.println(pretty(ans));

    }

    private String pretty(BigInteger ans) {
        if(ans.compareTo(BigInteger.valueOf(10000000000L)) < 0){
            return ans.toString();
        }
        else{
            String str = ans.toString();
            return "..." + str.substring(str.length() - 10, str.length());
        }
    }

    BigInteger sum(long x){
        return BigInteger.valueOf(x).multiply(BigInteger.valueOf(x + 1)).shiftRight(1);
    }


    BigInteger ans(int x, int y){
        long mn = Math.min(x, y);
        BigInteger base = sum(mn * mn);
        if(x == 0 || y ==0)
            return BigInteger.ZERO;
        int tmp = x;
        x = y;
        y = tmp;
        if(x > y){
            BigInteger add = sum(y - 1).multiply(BigInteger.valueOf(x - y));

            add = add.add(sumsqr(x - 1).subtract(sumsqr(y - 1)).add(BigInteger.valueOf(x - y)).multiply(BigInteger.valueOf(y)));

            base = base.add(add);
        }
        if(y > x){
            BigInteger add = sum(x - 1).multiply(BigInteger.valueOf(y - x)).negate();

            add = add.add(sumsqr(y).subtract(sumsqr(x)).multiply(BigInteger.valueOf(x)));

            base = base.add(add);
        }

        //System.err.println(x + " " + y + " " + base);
        return base;
    }

    private BigInteger sumsqr(long n) {
        return BigInteger.valueOf(n).multiply(BigInteger.valueOf(n + 1)).multiply(BigInteger.valueOf(2 * n + 1)).divide(BigInteger.valueOf(6));
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

    public String next() {
        return nextString();
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