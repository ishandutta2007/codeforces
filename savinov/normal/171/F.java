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

    boolean isPrime(int a) {
        for (int i = 2; i * i <= a; ++i) {
            if ((a % i) == 0)
                return false;
        }
        return true;
    }

    public void solve(InputReader in, PrintWriter out) {

        int n = in.nextInt();


        for (int i = 3; ; ++i) {
            if (isPrime(i) && i != rev(i) && isPrime(rev(i))) {
                --n;
                if (n == 0) {
                    out.println(i);
                    return;
                }
            }
        }


    }

    private int rev(int a) {
        int [] digits = new int[10];

        int sz = 0;

        while (a > 0) {
            digits[sz++] = a % 10;
            a /= 10;
        }

        int res = 0;

        for (int i = 0; i < sz; ++i) {
            res = res * 10 + digits[i];
        }
        return res;
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