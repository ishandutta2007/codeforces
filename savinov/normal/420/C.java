import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class Main {

    public static void main(String[] args) throws Exception {
        //InputStream inputStream = new FileInputStream("bluetube.in");//System.in;
        //OutputStream outputStream = new FileOutputStream("bluetube.out");//.out;
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        int testCount = 1;
        for (int i = 0; i < testCount; ++i) {
            solver.solve(in, out);
        }
        out.close();
    }

}


class Solver {

    int [] t;

    int get(int r) {
        int res = 0;
        for (; r >= 0; r &= r + 1, --r) {
            res += t[r];
        }
        return res;
    }

    void update(int pos, int val) {
        for (; pos < t.length; pos |= pos + 1) {
            t[pos] += val;
        }
    }

    public void solve(InputReader in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int p = in.nextInt();

        ArrayList<Integer>[] against = new ArrayList[n];
        t = new int[n + 1];
        int [][] ag = new int[n][2];
        int [] sz = new int[n];

        for (int i = 0; i < n; ++i) {
            against[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; ++i) {
            ag[i][0] = in.nextInt() - 1;
            ag[i][1] = in.nextInt() - 1;
            against[ag[i][0]].add(i);
            against[ag[i][1]].add(i);
            sz[ag[i][0]]++;
            sz[ag[i][1]]++;
        }
        for (int i = 0; i < n; ++i) {
            update(against[i].size(), 1);
        }
        long ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < against[i].size(); ++j) {
                for (int k = 0; k < 2; ++k) {
                    update(sz[ag[against[i].get(j)][k]], -1);
                    --sz[ag[against[i].get(j)][k]];
                    update(sz[ag[against[i].get(j)][k]], +1);
                }
            }
            int min = Math.max(0, p - against[i].size()) - 1;
            if (min == -1) {
                ans += n - 1;
            } else {
                ans += n - get(min);
            }
            for (int j = 0; j < against[i].size(); ++j) {
                for (int k = 0; k < 2; ++k) {
                    update(sz[ag[against[i].get(j)][k]], -1);
                    ++sz[ag[against[i].get(j)][k]];
                    update(sz[ag[against[i].get(j)][k]], 1);
                }
            }
        }
        ans /= 2;
        out.println(ans);
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;
    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }
    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                String s = reader.readLine();
                tokenizer = new StringTokenizer(s);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
    public String nextLine() throws IOException {
        return reader.readLine();
    }
}