import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int x = sc.nextInt();
		
		ArrayList<ArrayList<Voucher>> durationList = new ArrayList<>();
		for(int i=0; i<=x; i++) {
			durationList.add(new ArrayList<Voucher>());
		}
		
		for(int i=0; i<n; i++) {
			Voucher v = new Voucher(sc.nextInt(), sc.nextInt(), sc.nextInt());
			int d = v.r - v.l + 1;
			if(d < x) {
				durationList.get(d).add(v);
			}
		}
		
		int allmin = Integer.MAX_VALUE;
		
		for(int i=1; i<x; i++) {
			int j = x - i;
			
			ArrayList<Voucher> iset = durationList.get(i);
			iset.sort((a, b) -> a.r - b.r);
			int min = Integer.MAX_VALUE;
			ArrayList<Voucher> iseta = new ArrayList<>();
			for(int k=0; k<iset.size(); k++) {
				if(iset.get(k).c < min) {
					min = iset.get(k).c;
					iseta.add(iset.get(k));
				}
			}
			
			ArrayList<Voucher> jset = durationList.get(j);
			jset.sort((a, b) -> b.l - a.l);
			min = Integer.MAX_VALUE;
			ArrayList<Voucher> jseta = new ArrayList<>();
			for(int k=0; k<jset.size(); k++) {
				if(jset.get(k).c < min) {
					min = jset.get(k).c;
					jseta.add(jset.get(k));
				}
			}
			
			Collections.reverse(jseta);
			
			int isetptr = 0;
			int jsetptr = 0;
			min = Integer.MAX_VALUE;
			while(true) {
				
				if(jsetptr >= jseta.size() || isetptr >= iseta.size()) {
					break;
				}
				
//				System.out.println(iseta.get(isetptr).r + " " + jseta.get(jsetptr).l + " " + (iseta.get(isetptr).c + jseta.get(jsetptr).c));
				
				if(iseta.get(isetptr).r < jseta.get(jsetptr).l &&  iseta.get(isetptr).c + jseta.get(jsetptr).c < min) {
					min = iseta.get(isetptr).c + jseta.get(jsetptr).c;
				}
				
				if(jsetptr == jseta.size()-1 && isetptr == iseta.size()-1) {
					break;
				} else if(jsetptr == jseta.size()-1) {
					isetptr++;
				} else if(isetptr == iseta.size()-1) {
					jsetptr++;
				} else if(iseta.get(isetptr+1).r < jseta.get(jsetptr).l) {
					isetptr++;
				} else {
					jsetptr++;
				}
			}
			
			if(min < allmin) {
				allmin = min;
			}
		} 
		if(allmin == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(allmin);
		}
		
	}
	
	static class Voucher {
		int l;
		int r;
		int c;
		
		Voucher(int l, int r, int c) {
			this.l = l;
			this.r = r;
			this.c = c;
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