import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
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
    public void solve(InputReader in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();

        byte [] type = new byte[m];
        int [] num = new int[m];

        for (int i = 0; i < m; ++i) {
            String op = in.next();
            num[i] = in.nextInt() - 1;
            if (op.equals("+")) {
                type[i] = 0;
            } else {
                type[i] = 1;
            }
        }
        byte [] shouldBegin = new byte[n];
        byte [] shouldEnd = new byte[n];
        byte [] here = new byte[n];

        for (int i = 0; i < m; ++i) {
            if (type[i] == 1) {
                if (here[num[i]] != 0) {
                    here[num[i]] = 0;
                } else {
                    shouldBegin[num[i]] = 1;
                }
            } else {
                here[num[i]] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (here[i] != 0) {
                shouldEnd[i] = 1;
            }
        }

        Arrays.fill(here, (byte) 0);

        byte [] canNotBeLeader = new byte[n];

        int current = 0;

        for (int i = 0; i < n; ++i) {
            if (shouldBegin[i] != 0) {
                here[i] = 1;
                ++current;
            }
        }
        
        for (int i = 0; i < m; ++i) {
            if (type[i] == 1) {
                --current;
                here[num[i]] = 0;
                if (current != 0) {
                    canNotBeLeader[num[i]] = 1;
                }
                if (i < m - 1 && num[i + 1] != num[i]) {
                    canNotBeLeader[num[i]] = 1;
                }
            } else {
                here[num[i]] = 1;
                if (current != 0) {
                    canNotBeLeader[num[i]] = 1;
                }
                if (i > 0 && num[i - 1] != num[i]) {
                    canNotBeLeader[num[i]] = 1;
                }
                ++current;
            }
        }

        
        
        ArrayList<Integer> answer = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            if (canNotBeLeader[i] == 0) {
                answer.add(i + 1);
            }
        }

        out.println(answer.size());

        for (int i = 0; i < answer.size(); ++i) {
            if (i != 0) out.print(' ');
            out.print(answer.get(i));
        }
        out.println();
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