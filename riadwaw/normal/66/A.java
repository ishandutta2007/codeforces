
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.StringTokenizer;
import sun.security.util.BigInt;

public class Progression implements Runnable {

    private void solve(int t) throws IOException {
        BigInteger b=new BigInteger(nextToken());
        if(b.compareTo(new BigInteger("128")) * b.compareTo(new BigInteger("-129"))<0)
            writer.println("byte");
        else if(b.compareTo(new BigInteger("32768")) * b.compareTo(new BigInteger("-32769"))<0)
            writer.println("short");
        else if(b.compareTo(new BigInteger("2147483648")) * b.compareTo(new BigInteger("-2147483649"))<0)
            writer.println("int");
        else if(b.compareTo(new BigInteger("9223372036854775808")) * b.compareTo(new BigInteger("-9223372036854775809"))<0)
            writer.println("long");
        else
            writer.println("BigInteger");
    }

    public static void main(String[] args) {
        new Progression().run();
    }
    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve(1000);
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}