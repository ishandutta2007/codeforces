
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;

public class probB {
    class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
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
    }



    public void run() throws FileNotFoundException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        //FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        //PrintWriter out = new PrintWriter("output.txt");

        int n = in.nextInt();
        int m = in.nextInt();

        Set<String> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String s = in.next();

            Iterator<String> iter = set.iterator();
            while (iter.hasNext()) {
                String oldS = iter.next();
                if (s.equals(oldS)) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    if (s.charAt(j) == '#' && s.charAt(j) == oldS.charAt(j)) {
                        out.print("No\n");
                        out.close();
                        return;
                    }
                }
            }
            set.add(s);
        }


        out.print("Yes\n");
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new probB().run();
    }
}