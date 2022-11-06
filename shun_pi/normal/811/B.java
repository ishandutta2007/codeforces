import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	private static FastScanner sc = new FastScanner();

	public static void main(String[] args) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int[] p = new int[n];
		for(int i=0; i<n; i++) {
			p[i] = sc.nextInt();
		}
		
		StringBuilder ans = new StringBuilder();
		for(int i=0; i<m; i++) {
			int l = sc.nextInt() - 1;
			int r = sc.nextInt() - 1;
			int x = sc.nextInt() - 1;
			
			if(x < l || x > r) {
				ans.append("Yes\n");
				continue;
			}
			
			int[] psub = Arrays.copyOfRange(p, l, r+1);
			int standing = 0;
			for(int j=0; j<psub.length; j++) {
				if(psub[j] < psub[x-l]) {
					standing++;
				}
			}
			if(x-l == standing) {
				ans.append("Yes\n");
			} else {
				ans.append("No\n");
			}
		}
		System.out.print(ans);
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