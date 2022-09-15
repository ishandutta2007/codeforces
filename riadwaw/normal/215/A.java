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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for(int i = 0;i<n;++i){
            a[i] = in.nextInt();
        }
        int m =  in.nextInt();
        int[] b = new int[m];
        for(int i = 0;i<m;++i){
            b[i] = in.nextInt();
        }
        int curmax = 0;
        int cnt = 0;
        for(int i = 0;i<n;++i){
            for(int j = 0; j < m;++j){
                if(b[j] % a[i] == 0){
                    int t = b[j] / a[i];
                    if(t > curmax){
                        curmax = t;
                        cnt = 1;
                    }
                    else if(t == curmax){
                        cnt++;
                    }
                }
            }
        }
        out.print(cnt);
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