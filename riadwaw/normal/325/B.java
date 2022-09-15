import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.io.Writer;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        long n = in.nextLong();
        TreeSet<BigInteger> possibilities = new TreeSet<BigInteger>();

        /*for(long teamsInFinal = 1; true; teamsInFinal += 2) {
           // t/2 + t/4 ... + t/2^k + f(t/2^k) = n
           // t - t/2^k + (t/2^k)^2/2 - t/2^k /2

            long gamesInFinal = teamsInFinal * (teamsInFinal - 1) / 2;
            if(gamesInFinal > n) {
                break;
            }

            long t = n + teamsInFinal - gamesInFinal;
            if(isPowerOf2(t / teamsInFinal) && t % teamsInFinal == 0) {
                possibilities.add(t);
            }

        }*/

        for(int playoffRounds = 0; playoffRounds < 70; ++playoffRounds) {
            // t - t/2^k + (t/2^k)^2/2 - t/2^k /2 = n
            BigInteger A = BigInteger.ONE;
            BigInteger B = BigInteger.ONE.shiftLeft(playoffRounds + 1).subtract(BigInteger.valueOf(3));
            BigInteger C = BigInteger.valueOf(-2 * n);

            BigInteger D = B.multiply(B).subtract(C.multiply(BigInteger.valueOf(4)));


            BigInteger sqrtD = sqrt(D);
            //out.println(A + " " + B + " " + C + " " + D + " " + sqrtD);
            if(sqrtD == null)
                continue;

            BigInteger numerator = B.negate().add(sqrtD);
            //out.println(numerator);
            if(numerator.testBit(0)){
                continue;
            }

            BigInteger answer = numerator.shiftRight(1);

            if(answer.testBit(0))
                possibilities.add(answer.shiftLeft(playoffRounds));


        }

        if(possibilities.isEmpty()) {
            out.println(-1);
        }
        else {
            for (BigInteger possibility : possibilities) {
                out.println(possibility);
            }
        }
    }

    private BigInteger sqrt(BigInteger d) {
        BigInteger l = BigInteger.ZERO, r = d.add(BigInteger.ONE);

        while (!l.add(BigInteger.ONE).equals(r)) {
            BigInteger m = l.add(r).shiftRight(1);
            if(m.multiply(m).compareTo(d) <= 0){
                l = m;
            }
            else
                r = m;
        }

        return l.multiply(l).equals(d) ? l : null;


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

    public long nextLong() {
        return Long.parseLong(nextString());
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class OutputWriter extends PrintWriter {

	public OutputWriter(OutputStream out) {
		super(out);
	}

	public OutputWriter(java.io.Writer writer){
		super(writer);
	}

	}