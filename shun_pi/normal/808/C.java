import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {
	private static FastScanner sc = new FastScanner();

	public static void main(String[] args) {
		int n = sc.nextInt();
		int w = sc.nextInt();
		
		Cup[] cup = new Cup[n];
		for(int i=0; i<n; i++) {
			cup[i] = new Cup();
			cup[i].id = i;
			cup[i].a = sc.nextInt();		
		}
		Arrays.sort(cup, (x, y) -> x.a - y.a);
		
		boolean flag = true;
		for(int i=0; i<n; i++) {
			cup[i].b = (cup[i].a + 1) / 2;
			w -= cup[i].b;
			if(w < 0) {
				flag = false;
				break;
			}
		}
		
		if(!flag) {
			System.out.println(-1);
			return;
		}
		
		for(int i=n-1; i>=0; i--) {
			int c = Math.min(cup[i].a - cup[i].b, w);
			w -= c;
			cup[i].b += c;
			if(w == 0) {
				break;
			}
		}
		
		Arrays.sort(cup, (x, y) -> x.id - y.id);
		
		StringBuilder ans = new StringBuilder();
		for(int i=0; i<n; i++) {
			ans.append(cup[i].b);
			ans.append(" ");
		}
		System.out.println(ans);
	}
	
	static class Cup {
		int id;
		int a;
		int b;
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