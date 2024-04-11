import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int s = in.nextInt();
        long ans = 0;
        for(int ac = 0; ac<= n/2; ++ac){
            for(int bd = 0; bd <= m/2; ++bd){
                int curS = (2 * ac + 1) * (2* bd + 1);
                if(curS < s)
                    continue;
                if(curS == s){
                    ans += (n - 2 * ac) * (m - 2 * bd) * (2L * (ac + 1) * (bd + 1) - 1);
                }
                else{
                    int toDrop = curS - s;
                    if(toDrop%4 !=0)
                        continue;
                    toDrop/=4;
                    for(int i = 1; i<=ac; ++i){
                        if(toDrop % i == 0 && toDrop/i <= bd){
                            ans +=2 * (n - 2 * ac) * (m - 2 * bd);
                        }
                    }
                }
            }

        }
        out.print(ans);
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