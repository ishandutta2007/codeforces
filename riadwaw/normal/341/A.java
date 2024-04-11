import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Collections;
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
        int n = in.nextInt();
        int[] a = in.nextIntArray(n);
        ArrayUtils.sort(a);

        long res = 0;
        long sum = 0;
        for(int i = 0; i < n; ++i) {
            res += 2 * (a[i] * 1L * i - sum);
            res += a[i];
            sum += a[i];
        }

        Rational ans = new Rational(res, n);
        out.println(ans.numerator + " " + ans.denominator);
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

class ArrayUtils {
    public static void sort(int[] array) {
        Collections.sort(new IntArray(array));
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
        if (this.denominator.compareTo(BigInteger.ZERO) < 0) {
            this.numerator = this.numerator.negate();
            this.denominator = this.denominator.negate();
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

class IntArray extends Array<Integer> {
    private final int[] array;

    public IntArray(int... array) {
        this.array = array;
    }

    public Integer get(int i) {
        return array[i];
    }

    public Integer set(int index, Integer element) {
        Integer res = array[index];
        array[index] = element;
        return res;
    }

    public int size() {
        return array.length;
    }
}

abstract class Array<T> extends AbstractList<T> implements RandomAccess {
}