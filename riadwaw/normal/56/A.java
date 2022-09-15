
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
        int c=0;
        int n=nextInt();
        for(int i=0;i<n;++i){
            String s=nextToken();
            try{
                BigInteger a=new BigInteger(s);
                if(a.intValue()<18)
                    ++c;
            }
            catch(NumberFormatException e){
                if(s.equals("VODKA") || s.equals("ABSINTH") || s.equals("BEER") || s.equals("BRANDY") || s.equals("CHAMPAGNE") || 
                        s.equals("GIN") || s.equals("RUM") || s.equals("SAKE")  || s.equals("TEQUILA") || s.equals("WINE") || 
                        s.equals("WHISKEY"))
                    ++c;
            }
        }
        writer.println(c);
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