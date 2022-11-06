import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public class Main {
	private static FastScanner sc = new FastScanner();
	static int n;
	static int m;
	static int[][] t;
	static List<Op> oplist;
	
	public static void main(String[] args) {
		n = sc.nextInt();
		m = sc.nextInt();
		
		t = new int[n][m];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				t[i][j] = sc.nextInt();
			}
		}
		
		oplist = new ArrayList<>();
		
		if(n > m) {
			col();
		}
		
		while(true) {
			int befSize = oplist.size();
			
			row();
			col();
			
			if(oplist.size() == befSize) {
				for(int i=0; i<n; i++) {
					for(int j=0; j<m; j++) {
						if(t[i][j] != 0) {
							System.out.println(-1);
							return;
						}
					}
				}
				
				StringBuilder ans = new StringBuilder();
				ans.append(oplist.size());
				ans.append("\n");
				for(int k=0; k<oplist.size(); k++) {
					ans.append(oplist.get(k).str);
					ans.append(" ");
					ans.append(oplist.get(k).num);
					ans.append("\n");
				}
				System.out.print(ans);
				return;
				
			}
		}
	}
	
	public static void row() {
		for(int i=0; i<n; i++) {
			int min = 500;
			
			for(int j=0; j<m; j++) {
				if(t[i][j] < min) {
					min = t[i][j];
				}
			}
			
			for(int j=0; j<m; j++) {
				t[i][j] -= min;
			}
			
			for(int k=0; k<min; k++) {
				oplist.add(new Op("row", i+1));
			}
		}
	}
	
	public static void col() {
		for(int j=0; j<m; j++) {
			int min = 500;
			
			for(int i=0; i<n; i++) {
				if(t[i][j] < min) {
					min = t[i][j];
				}
			}
			
			for(int i=0; i<n; i++) {
				t[i][j] -= min;
			}
			
			for(int k=0; k<min; k++) {
				oplist.add(new Op("col", j+1));
			}
		}
	}
	
	static class Op {
		String str;
		int num;
		
		Op(String str, int num) {
			this.str = str;
			this.num = num;
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