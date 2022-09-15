import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int[] a = in.nextIntArray(4);
        int d = a[1] - a[0];
        if(a[2] - a[1] == d && a[3] - a[2] == d) {
            out.println(a[3] + d);
            return;
        }
        if(a[1] == 0 && a[2] == 0 && a[3] == 0){
            out.println(0);
            return;
        }
        if(a[0] == 0) {
            out.println(42);
            return;
        }

        Rational fraction1 = new Rational(a[1], a[0]);
        Rational fraction2 = new Rational(a[2], a[1]);
        Rational fraction3 = new Rational(a[3], a[2]);
        if(fraction1.equals(fraction2) && fraction1.equals(fraction3)) {
            Rational next = new Rational(a[3]).multiply(fraction1);
            if(next.denominator.equals(BigInteger.ONE)){
                out.println(next.numerator);
                return;
            }
        }
        
        out.println(42);
        
        
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

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public int[] nextIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextInt();
        }
        return array;
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

class Rational implements Comparable<Rational> {
    public BigInteger numerator, denominator;

    public Rational(BigInteger numerator, BigInteger denominator) {
        if (denominator.equals(BigInteger.ZERO))
            throw new IllegalArgumentException();
        BigInteger gcd = numerator.gcd(denominator);
        this.numerator = numerator.divide(gcd);
        this.denominator = denominator.divide(gcd);
        if (denominator.compareTo(BigInteger.ZERO) < 0) {
            this.numerator = numerator.negate();
            this.denominator = denominator.negate();
        }
    }

	public Rational(BigInteger numerator) {
		this.numerator = numerator;
		this.denominator = BigInteger.ONE;
	}


	public Rational(long numerator) {
		this(BigInteger.valueOf(numerator));
	}

	public Rational(long numerator, long denominator) {
		this(BigInteger.valueOf(numerator), BigInteger.valueOf(denominator)) ;
	}


	public Rational multiply(Rational r) {
        BigInteger y = denominator.multiply(r.denominator);
        BigInteger x = numerator.multiply(r.numerator);
        return new Rational(x, y);
    }

    public String toString() {
        return numerator + "/" + denominator;
    }

    public int compareTo(Rational other) {
        return numerator.multiply(other.denominator).compareTo(denominator.multiply(other.numerator));
    }

    public int hashCode() {
        int result = numerator.hashCode();
        return 31 * result + denominator.hashCode();
    }

    public boolean equals(Object obj) {
        if (obj == this)
            return true;
        if (obj == null || obj.getClass() != getClass())
            return false;
        Rational r = (Rational) obj;
        return numerator.equals(r.numerator) && denominator.equals(r.denominator);
    }

	}