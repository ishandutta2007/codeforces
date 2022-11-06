import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		String s = sc.next();
		
		ArrayList<Character> c = new ArrayList<>();
		for(int i=0; i<s.length(); i++) {
			c.add(s.charAt(i));
		}
		
		char[] vowel = {'a', 'e', 'i', 'o', 'u'};
		a:
		for(int i=s.length()-3; i>=0; i--) {
			for(int j=i; j<=i+2; j++) {
				for(char x : vowel) {
					if(c.get(j) == x) {
						continue a;
					}
				}
			}
			if(c.get(i) == c.get(i+1) && c.get(i) == c.get(i+2)) {
				continue a;
			}
			c.add(i+1, ' ');
			i--;
		}
		
		String ans = "";
		for(int i=0; i<c.size(); i++) {
			ans += c.get(i);
		}
		System.out.println(ans);
	}
	
	static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if(ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch(IOException e) {
                    e.printStackTrace();
                }
                if(buflen <= 0) {
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
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}