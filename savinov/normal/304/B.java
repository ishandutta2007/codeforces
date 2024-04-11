import java.io.*;
import java.math.BigInteger;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Evgeny Savinov
 */
public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = System.in;//new FileInputStream("input.txt");
        OutputStream outputStream = System.out;//new FileOutputStream("output.txt");//
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}


class TaskE {

    public void solve(int testNumber, InputReader in, PrintWriter out)
    {
        SimpleDateFormat z = new SimpleDateFormat("yyyy:MM:dd");
        z.setTimeZone(TimeZone.getTimeZone("GMT+8:00"));
        Date a = null, b = null;
        try {
            a = z.parse(in.next());
        } catch (ParseException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        try {
            b = z.parse(in.next());
        } catch (ParseException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        
        long diff = Math.abs(a.getTime() - b.getTime());
        out.println(diff / 1000 / 3600 / 24);
        


    }
}


class InputReader
{
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

    public int nextInt() {
        return Integer.parseInt(next());
    }
}