import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	static Node[] V = new Node[26];
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		char[] S = sc.next().toCharArray();
		char[] T = sc.next().toCharArray();
		for(int i=0; i<26; i++) {
			V[i] = new Node();
			V[i].id = i;
		}
		ArrayList<String> con = new ArrayList<>();
		for(int i=0; i<n; i++) {
			int a = S[i] - 'a';
			int b = T[i] - 'a';
			if(!V[a].dfs(b)) {
				con.add((char)('a'+a) + " " + (char)('a'+b));
				V[a].nbr.add(b);
				V[b].nbr.add(a);
			}
			for(int j=0; j<26; j++) {
				V[j].visited = false;
			}
		}
		System.out.println(con.size());
		for(String s : con) {
			System.out.println(s);
		}
	}
	
	static class Node {
		int id;
		HashSet<Integer> nbr = new HashSet<>();
		boolean visited = false;
		
		boolean dfs(int toid) {
			visited = true;
			if(id == toid) return true;
			for(int x : nbr) {
				if(V[x].visited) continue;
				if(V[x].dfs(toid)) {
					return true;
				}
			}
			return false;
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