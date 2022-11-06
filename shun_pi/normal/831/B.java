import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		char[] fir = sc.next().toCharArray();
		char[] sec = sc.next().toCharArray();
		char[] str = sc.next().toCharArray();
		
		HashMap<Character, Character> map = new HashMap<>();
		for(int i=0; i<fir.length; i++) {
			map.put(fir[i], sec[i]);
		}
		
		for(int i=0; i<str.length; i++) {
			if(Character.isLowerCase(str[i])) {
				str[i] = map.get(str[i]);
			} else if(Character.isUpperCase(str[i])) {
				str[i] = Character.toLowerCase(str[i]);
				str[i] = map.get(str[i]);
				str[i] = Character.toUpperCase(str[i]);
			}
		}
		
		System.out.println(str);
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