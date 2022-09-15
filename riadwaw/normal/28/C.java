import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.lang.Comparable;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.StringTokenizer;
public class TheJackpotDivOne implements Runnable {
    public BigInteger c(int n, int k){
        if(b[n][k])
            return res[n][k];
        BigInteger ans= BigInteger.ONE;
        for(int i=n-k+1;i<=n;++i){
            ans=ans.multiply(BigInteger.valueOf(i));
        }
        for(int i=1;i<=k;++i)
            ans=ans.divide(BigInteger.valueOf(i));
        b[n][k]=true;
        res[n][k]=ans;
        return ans;
    }
    public int max(int a,int b){
        return a<b?b:a;
    }
    boolean[][] b;
    BigInteger[][] res;
    private void solve() throws IOException {
        int n=nextInt(),m=nextInt();
        int[]a =new int[m];
        b=new boolean[n+1][n+1];
        res=new BigInteger[n+1][n+1];
        for(int i=0;i<m;++i){
            a[i]=nextInt();
        }
        BigInteger dp[][][]=new BigInteger[m+1][n+1][n+1];
        for(int i=0;i<=m;++i)
            for(int j=0;j<=n;++j)
                for(int k=0;k<=n;++k)
                    dp[i][j][k]=BigInteger.ZERO;
        dp[0][n][0]=BigInteger.valueOf(1);
        for(int i=0;i<m;++i){ 
            for(int j=0;j<=n;++j){ 
                for(int k=0;k<=n;++k){ 
                    for(int now=0;now<=j;++now){
                        int nowq=(now-1)/a[i]+1;
                        dp[i+1][j-now][max(k,nowq)]=dp[i+1][j-now][max(k,nowq)].add(dp[i][j][k].multiply(c(j,now)));
                    }
                }
            }
        }
        BigInteger ans=BigInteger.ZERO,ss=BigInteger.ZERO;
            for(int i=0;i<=n;++i){
                ans=ans.add(dp[m][0][i].multiply(BigInteger.valueOf(i)));
                ss=ss.add(dp[m][0][i]);
            }
        writer.print(new BigDecimal(ans).divide(new BigDecimal(ss), 15, RoundingMode.UP));
        
    }
        
    public static void main(String[] args) {
        new TheJackpotDivOne().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
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