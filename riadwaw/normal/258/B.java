import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    final int mod = 1000000007;


    long solve(int level, long [] number, int sum){
        if(sum >= 9)
            return 0;
        if(level == 6){
            long ans = 0;
            for(int i = sum + 1; i <= 9; ++i){
                ans += number[i];
                ans %= mod;
            }
            return ans;
        }
        long res = 0;
        for(int i = 0; i <= 9; ++i){
            if(number[0] == 0)
                continue;
            number[i]--;
            sum += i;
            res += solve(level + 1, number, sum) * (number[i] + 1) % mod;
            res %= mod;
            sum-=i;
            number[i]++;
        }
        return res;

    }
    public void solve(int testNumber, Reader in, OutputWriter out) {

        int n = in.nextInt();
        String s = String.valueOf(n);
        int x[][] = new int[11][11];
        long[] cnt = new long[11];
        x[0][0] = 1;
        for(int i = 1; i < 11; ++i){
            x[i][0] = x[i - 1][0] * 8;
            for(int j = 1; j < 11; ++j){
                x[i][j] = x[i - 1][j] * 8 + x[i - 1][j - 1] * 2;
            }
        }

        int cur = 0;
        for(int i = 0; i < s.length(); ++i){

            if(s.charAt(i) > '0'){
                long mult = s.charAt(i)  -'0';
                long m2 = 0;
                if(mult >= 8){
                    --mult;
                    ++m2;
                }
                if(mult >= 5){
                    --mult;
                    ++m2;
                }

                int l = s.length() - i;
                for(int  r = 0; r <=l ;++r){
                    if(cur + r > 10)
                        continue;
                    cnt[cur + r] += x[l - 1][r] * mult %mod;
                    cnt[cur + r] %= mod;
                    if(m2 >= 0 && cur + r + 1 <= 10){
                        cnt[cur + r + 1] += (x[l - 1][r] * m2) % mod;
                        cnt[cur + r + 1] %= mod;
                    }

                }


            }

            if(s.charAt(i) == '4' || s.charAt(i)== '7')
                ++cur;


        }

        cnt[0]--;
        cnt[cur]++;

        //out.println(Arrays.toString(cnt));

        out.println(solve(0,cnt, 0));
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