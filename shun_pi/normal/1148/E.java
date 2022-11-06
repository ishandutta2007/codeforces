import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	Stone[] stone = new Stone[n];
    	long ssum = 0;
    	for(int i=0; i<n; i++) {
    		long s = sc.nextLong();
    		stone[i] = new Stone(i+1, s);
    		ssum += s;
    	}
    	long[] t = new long[n];
    	long tsum = 0;
    	for(int i=0; i<n; i++) {
    		t[i] = sc.nextLong();
    		tsum += t[i];
    	}
    	if(ssum != tsum) {
    		System.out.println("NO");
    		return;
    	}
    	Arrays.sort(t);
    	Arrays.sort(stone, (a, b) -> (int)a.s - (int)b.s);
    	ArrayList<Integer> moveright = new ArrayList<>();
    	ArrayList<Integer> moveleft = new ArrayList<>();
    	for(int i=0; i<n; i++) {
    		stone[i].t = t[i];
    		if(stone[i].s < stone[i].t) {
    			moveright.add(i);
    		} else if(stone[i].s > stone[i].t) {
    			moveleft.add(i);
    		}
    	}

    	int ri = 0;
    	int li = 0;
    	int opnum = 0;
    	StringBuilder sb = new StringBuilder();
    	while(ri < moveright.size() && li < moveleft.size()) {
    		Stone r = stone[moveright.get(ri)];
    		Stone l = stone[moveleft.get(li)];
    		if(r.s >= l.s) {
    			System.out.println("NO");
    			return;
    		}
    		long d = Math.min(r.t - r.s, l.s - l.t);
    		sb.append(r.idx + " " + l.idx + " " + d + "\n");
    		r.s += d;
    		l.s -= d;
    		if(r.s > l.s) {
    			System.out.println("NO");
    			return;
    		}
    		if(r.s == r.t) {
    			ri++;
    		}
    		if(l.s == l.t) {
    			li++;
    		}
    		opnum++;
    	}
    	if((ri == moveright.size() && li >= moveleft.size() - 1) || (ri >= moveright.size() - 1 && li == moveleft.size())) {
    		System.out.println("YES");
    		System.out.println(opnum);
    		System.out.print(sb);
    	} else {
    		System.out.println("NO");
    	}
    }

    static class Stone{
    	int idx;
    	long s;
    	long t;
		public Stone(int idx, long s) {
			this.idx = idx;
			this.s = s;
		}
    }

    static void debug(long... args) {
    	if(!DEBUG_FLG) return;
    	boolean flg = false;
    	for(long s : args) {
    		if(flg) System.out.print(" ");
    		flg = true;
    		System.out.print(s);
    	}
    	System.out.println();
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