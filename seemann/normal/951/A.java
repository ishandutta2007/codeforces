import java.io.*;
import java.util.*;

public class Main {

    private class FastReader {
        private BufferedReader reader;
        private StringTokenizer st;

        public FastReader(InputStream is) {
            this.reader = new BufferedReader(new InputStreamReader(is));
            this.st = new StringTokenizer("");
        }

        public String next() {
            while (!st.hasMoreElements()) {
                st = new StringTokenizer(nextLine());
            }
            return st.nextToken();
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (Exception e) {
                return null;
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    class MyStruct {
        public int i;
        public double d;

        public MyStruct(int i, double d) {
            this.i = i;
            this.d = d;
        }

        public int getI() {
            return i;
        }
    }

    void run() throws IOException {
        InputStream is = System.in;
        OutputStream os = System.out;
        //is = new FileInputStream("input.txt");
        //os = new FileOutputStream("output.txt");

        FastReader reader = new FastReader(is);
        PrintWriter writer = new PrintWriter(os);

        String s = reader.nextLine();

        int len = 1;
        Integer maxlen = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                len++;
            } else {
                if (len > maxlen) {
                    maxlen = len;
                }
                len = 1;
            }
        }
        if (len > maxlen) {
            maxlen = len;
        }

        if (s.charAt(0) != s.charAt(s.length() - 1)) {
            int i = 1;
            while (i < s.length() && s.charAt(i) != s.charAt(i - 1)) {
                i++;
            }

            int j = 1;
            while (j < s.length() && s.charAt(s.length() - j) != s.charAt(s.length() - j - 1)) {
                j++;
            }

            int ans = i + j;
            if (i + j > s.length()) {
                ans = s.length();
            }

            if (ans > maxlen) {
                maxlen = ans;
            }
        }

        writer.write(maxlen.toString());

        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}