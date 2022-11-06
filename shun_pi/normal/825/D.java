import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		
		int[] schar = new int[26];
		int sq = 0;
		int[] tchar = new int[26];
		
		for(int i=0; i<s.length; i++) {
			if(s[i] == '?') {
				sq++;
			} else {
				schar[s[i] - 'a']++;
			}
		}
		
		for(int i=0; i<t.length; i++) {
			tchar[t[i] - 'a']++;
		}
		
		int l = 0;
		int r = s.length / t.length;
		int m = (l + r) / 2;
		while(l < r) {
			int needq = 0;
			for(int i=0; i<26; i++) {
				if(schar[i] < tchar[i] * m) {
					needq += tchar[i] * m - schar[i];
				}
			}
			
			if(sq >= needq) {
				needq = 0;
				for(int i=0; i<26; i++) {
					if(schar[i] < tchar[i] * (m+1)) {
						needq += tchar[i] * (m+1) - schar[i];
					}
				}
				
				if(sq < needq) {
					break;
				} else {
					l = m+1;
				}
			} else {
				r = m-1;
			}
			
			m = (l + r) / 2;
		}
		
		
		
//		System.out.println(m);
		
		int[] needchar = new int[26];
		for(int i=0; i<26; i++) {
			if(schar[i] < tchar[i] * m) {
				needchar[i] = tchar[i] * m - schar[i];
			}
		}
		
		int pos = 0;
		for(int i=0; i<s.length; i++) {
			if(s[i] == '?') {
				while(true) {
					if(pos == 26) {
						s[i] = 'a';
						break;
					} else if(needchar[pos] != 0) {
						s[i] = (char)('a' + pos);
						needchar[pos]--;
						break;
					} else {
						pos++;
					}
				}
			}
		}
		
		System.out.println(s);
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