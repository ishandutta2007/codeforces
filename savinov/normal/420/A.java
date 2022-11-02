import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        Set<Character> mirrored = new HashSet<>();

        mirrored.add('A');
        mirrored.add('H');
        mirrored.add('I');
        mirrored.add('M');
        mirrored.add('O');
        mirrored.add('T');
        mirrored.add('U');
        mirrored.add('V');
        mirrored.add('W');
        mirrored.add('X');
        mirrored.add('Y');
        String s = in.next();

        for (int i = 0; i < s.length(); ++i) {
            if (!mirrored.contains(s.charAt(i))) {
                out.println("NO");
                return;
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");

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