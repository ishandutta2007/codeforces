import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	private static FastScanner sc = new FastScanner();
	private static final int MOD = 1000000007;
	static long[] pow;

	public static void main(String[] args) {
		int n = sc.nextInt();
		
		Integer[] x = new Integer[n];
		for(int i=0; i<n; i++) {
			x[i] = sc.nextInt();
//			x[i] = i;
		}
		
		pow = new long[n+1];
		for(int i=0; i<=n; i++) {
			pow[i] = -1;
		}
		
		Arrays.sort(x);
		
		long sum = 0;
		for(int i=1; i<n; i++) {
			long a = ((pow(n) - n - 1) + MOD * 2 - (pow(n-i) - (n-i) - 1) - (pow(i) - i - 1)) % MOD;
			long b = (x[i] - x[i-1]) * a % MOD;
			sum = (sum + b) % MOD;
//			System.out.println(a + " " + b + " " + sum);
		}
		
		System.out.println(sum);
	}
	
	static long pow(int k) {
		if(pow[k] != -1) {
			return pow[k];
		}
		long ans = 1;
		if (k == 0) {
	        ans = 1;
		} else if (k%2 == 0) {
			ans = pow(k/2)*pow(k/2) % MOD;
		} else {
			ans = 2*pow(k/2)*pow(k/2) % MOD;
		}
		
		pow[k] = ans;
		return ans;
	}

	static class FastScanner {
	    private final InputStream in = System.in;
	    private final byte[] buffer = new byte[1024];
	    private int ptr = 0;
	    private int buflen = 0;
	    private boolean hasNextByte() {
	        if (ptr < buflen) {
	            return true;
	        }else{
	            ptr = 0;
	            try {
	                buflen = in.read(buffer);
	            } catch (IOException e) {
	                e.printStackTrace();
	            }
	            if (buflen <= 0) {
	                return false;
	            }
	        }
	        return true;
	    }
	    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
	    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
	    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
	    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
	    public String next() {
	        if (!hasNext()) throw new NoSuchElementException();
	        StringBuilder sb = new StringBuilder();
	        int b = readByte();
	        while(isPrintableChar(b)) {
	            sb.appendCodePoint(b);
	            b = readByte();
	        }
	        return sb.toString();
	    }
	    public long nextLong() {
	        return Long.parseLong(next());
	    }
	    public int nextInt(){
	    	return Integer.parseInt(next());
	    }
	}
}