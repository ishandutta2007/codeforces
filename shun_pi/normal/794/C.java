import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	private static FastScanner sc = new FastScanner();

	public static void main(String[] args) {
		char[] oleg = sc.next().toCharArray();
		char[] igor = sc.next().toCharArray();	
		int n = oleg.length;
		char[] ans = new char[n];
		
		Arrays.sort(oleg);
		Arrays.sort(igor);
		
		ArrayDeque<Character> ol = new ArrayDeque<Character>();
		ArrayDeque<Character> ig = new ArrayDeque<Character>();
		for(int i=0; i<=(n-1)/2; i++) {
			ol.add(oleg[i]);
		}
		for(int i=n-1; i>=(n+1)/2; i--) {
			ig.add(igor[i]);
		}
				
		int first = 0;
		int last = n-1;
		for(int i=0; i<n; i++) {
			if(i%2 == 0) {
				if(ig.size() != 0 && ol.peek() >= ig.peek()) {
					ans[last] = ol.pollLast();
					last--;
				} else {
					ans[first] = ol.poll();
					first++;
				}
				
			} else {
				if(ol.size() != 0 && ol.peek() >= ig.peek()) {
					ans[last] = ig.pollLast();
					last--;
				} else {
					ans[first] = ig.poll();
					first++;
				}
			}
		}
		
		System.out.println(ans);
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