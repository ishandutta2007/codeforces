import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	static Node[] V;
	static double lensum = 0;
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		V = new Node[n];
		for(int i=0; i<n; i++) {
			V[i] = new Node();
			V[i].id = i;
		}
		
		for(int i=0; i<n-1; i++) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			V[u].nbr.add(v);
			V[v].nbr.add(u);
		}
		
		V[0].dfs(1, 0);
		
		System.out.println(lensum);
	}
	
	static class Node {
		int id;
		HashSet<Integer> nbr = new HashSet<>();
		boolean visited = false;
		
		void dfs(double p, int d) {
			visited = true;
			boolean flag = false;
			
			int size = nbr.size();
			for(int x : nbr) {
				if(V[x].visited) {
					size--;
				}
			}
			for(int x : nbr) {
				if(!V[x].visited) {
					flag = true;
					V[x].dfs(p / size, d+1);
				} else {
					
				}
			}
			if(!flag) {
//				System.out.println(id + " " + p + " " + d);
				lensum += p * d;
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