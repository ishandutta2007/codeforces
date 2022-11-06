import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	private static FastScanner sc = new FastScanner();

	public static void main(String[] args) {
		int n = sc.nextInt();
		int f = sc.nextInt();
		
		Day[] day = new Day[n];
		for(int i=0; i<n; i++) {
			day[i] = new Day(sc.nextInt(), sc.nextInt());
		}
		
		Arrays.sort(day, (x, y) -> x.value - y.value);
		
		long sum = 0;
		for(int i=n-1; i>n-1-f; i--) {
			sum += Math.min(2 * day[i].k, day[i].l);
		}
		
		for(int i=0; i<=n-1-f; i++) {
			sum += Math.min(day[i].k, day[i].l);
		}
		System.out.println(sum);
	}
	
	static class Day {
		int k;
		int l;
		int value;
		
		Day(int k, int l) {
			this.k = k;
			this.l = l;
			value = Math.min(2 * k, l) - Math.min(k, l);
		}
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