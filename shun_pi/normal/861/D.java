import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		String[] pn = new String[n];
		for(int i=0; i<n; i++) {
			pn[i] = sc.next();
		}
		
		String[] ans = new String[n];
		
		for(int d=1; d<=8; d++) {
			HashMap<String, Integer> map = new HashMap<>();
			for(int i=0; i<n; i++) {
				for(int j=0; j<10-d; j++) {
					String temp = pn[i].substring(j, j+d);
					if(map.containsKey(temp) && map.get(temp) != i) {
						if(map.get(temp) != -1) {
							map.replace(temp, -1);
						}
					} else {
						map.put(temp, i);
					}
				}
			}
			
			for(String key : map.keySet()) {
				int value = map.get(key);
				if(value != -1 && ans[value] == null) {
					ans[value] = key; 
				}
			}
		}
		
		for(int i=0; i<n; i++) {
			if(ans[i] == null) {
				System.out.println(pn[i]);
			} else {
				System.out.println(ans[i]);
			}
		}
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