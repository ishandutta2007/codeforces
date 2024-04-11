import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	private static Node[] V;
	private static int step = 0;
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		V = new Node[n];
		for(int i=0; i<n; i++) {
			V[i] = new Node();
		}
		for(int i=1; i<n; i++) {
			int p = sc.nextInt() - 1;
			V[i].nbr.add(p);
			V[p].nbr.add(i);
		}
		for(int i=0; i<n; i++) {
			V[i].c = sc.nextInt();
		}
		V[0].dfs(0);
		System.out.println(step);
	}
	
	static class Node {
		int c = 0;
		HashSet<Integer> nbr = new HashSet<>();
		boolean visited;
		
		void dfs(int cb) {
			visited = true;
			if(cb != c) step++;
			for(int x : nbr) {
				if(!V[x].visited) {
					V[x].dfs(c);
				}
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