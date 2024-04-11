
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
        String a=nextToken(),b=nextToken();
        String c=new BigInteger(a).add(new BigInteger(b)).toString();
        String a2="",b2="",c2="";
        for(int i=0;i<a.length();++i)
            if(a.charAt(i) !='0')
                a2+=a.charAt(i);
        for(int i=0;i<b.length();++i)
            if(b.charAt(i) !='0')
                b2+=b.charAt(i);
        for(int i=0;i<c.length();++i)
            if(c.charAt(i) !='0')
                c2+=c.charAt(i);
        writer.println(c2.equals(new BigInteger(a2).add(new BigInteger(b2)).toString())?"YES":"NO");
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