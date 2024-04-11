import java.io.*;
import java.util.*;
public class JavaSolution {
   private void solve() throws IOException {
        int n = nextInt();
        String[] bad = new String[n];
        for (int i = 0; i < n; ++i) bad[i] = nextToken().toLowerCase();
        String input = nextToken();
        String inputLower = input.toLowerCase();
        char need = nextToken().toLowerCase().charAt(0);
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < input.length(); ++i) {
            boolean any = false;
            for (String b : bad) {
                for (int j = Math.max(0, i - b.length() + 1); j <= i && j + b.length() <= input.length(); ++j) {
                    if (inputLower.substring(j, j + b.length()).equals(b)) {
                        any = true;
                        break;
                    }
                }
                if (any) break;
            }
            char ch = input.charAt(i);
            if (any) {
                if (inputLower.charAt(i) != need) {
                    if (Character.isUpperCase(ch))
                        res.append(Character.toUpperCase(need));
                    else
                        res.append(need);
                } else {
                    if (need == 'a') {
                        if (Character.isUpperCase(ch))
                            res.append('B');
                        else
                            res.append('b');
                    } else {
                        if (Character.isUpperCase(ch))
                            res.append('A');
                        else
                            res.append('a');
                    }
                }
            } else {
                res.append(ch);
            }
        }
        writer.println(res.toString());
    }

    public static void main(String[] args) {
        new JavaSolution().run();
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