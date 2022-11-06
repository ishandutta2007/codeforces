import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	static Node[] V;
	static int knum = 1;
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int q = sc.nextInt();
		
		while(Math.pow(2, knum) <= n) {
			knum++;
		}
		
		V = new Node[n+1];
		V[1] = new Node();
		V[1].parent[0] = -1;
		
		for(int i=2; i<=n; i++) {
			V[i] = new Node();
		}
		
		for(int i=2; i<=n; i++) {
			V[i].parent[0] = sc.nextInt();
			V[V[i].parent[0]].child.add(i);
		}
		
		V[1].dfs(0);
		
		for(int k=1; k<=knum; k++) {
			for(int i=1; i<=n; i++) {
				if(V[i].parent[k-1] == -1) {
					V[i].parent[k] = -1;
				} else {
					V[i].parent[k] = V[V[i].parent[k-1]].parent[k-1];
				}
			}
		}
		
		StringBuilder ans = new StringBuilder();
		for(int i=0; i<q; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			
			int x = lca(a, b);
			int y = lca(b, c);
			int z = lca(c, a);
			
			int d = 0;
			if(x == y) {
				d = Math.max(Math.max(V[a].depth - V[z].depth, V[c].depth - V[z].depth), (V[b].depth - V[x].depth) + (V[z].depth - V[x].depth));
			} else if(y == z) {
				d = Math.max(Math.max(V[a].depth - V[x].depth, V[b].depth - V[x].depth), (V[c].depth - V[y].depth) + (V[x].depth - V[y].depth));
			} else if(z == x){
				d = Math.max(Math.max(V[b].depth - V[y].depth, V[c].depth - V[y].depth), (V[a].depth - V[z].depth) + (V[y].depth - V[z].depth));
			} else {
				System.out.println("bug");
				return;
			}
			
			ans.append(d + 1);
			ans.append("\n");
		}
		
		System.out.print(ans);
	}
	
	static class Node {
		int[] parent = new int[knum+1];
		HashSet<Integer> child = new HashSet<>();
		int depth;
		
		void dfs(int d) {
			depth = d;
			for(int x : child) {
				V[x].dfs(d+1);
			}
		}
	}
	
	static int lca(int u, int v) {
		if(V[u].depth > V[v].depth) {
			return lca(v, u);
		}
		
		for(int k=0; k<=knum; k++) {
			if(((V[v].depth - V[u].depth) >> k & 1) == 1) {
				v = V[v].parent[k];
			}
		}
		
		if (u == v) {
			return u;
		}
		
		for(int k=knum; k>=0; k--) {
			if(V[u].parent[k] != V[v].parent[k]) {
				u = V[u].parent[k];
				v = V[v].parent[k];
			}
		}
		
		return V[u].parent[0];
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