import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        //InputStream inputStream = new FileInputStream("bluetube.in");//System.in;
        //OutputStream outputStream = new FileOutputStream("bluetube.out");//.out;
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;


        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }
}

class Solver {

    public void solve(InputReader in, PrintWriter out) {

        String a = in.next();
        String b = in.next();

        StringBuilder stringBuilder = new StringBuilder(b);

        for (int i = 0; i < b.length() / 2; ++i) {
            char prev = stringBuilder.charAt(i);
            stringBuilder.setCharAt(i, stringBuilder.charAt(b.length() - 1 - i));
            stringBuilder.setCharAt(b.length() - 1 - i, prev);
        }

        out.println(Long.parseLong(a) + Long.parseLong(stringBuilder.toString()));

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