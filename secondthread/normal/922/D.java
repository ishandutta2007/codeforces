import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Block[] blocks=new Block[n];
		int totalLength=0;
		for (int i=0; i<n; i++) {
			String st=fs.next();
			totalLength+=st.length();
			blocks[i]=new Block(st);
		}
		Arrays.sort(blocks);
//		for (Block b:blocks)
//			System.out.println(b);
		boolean[] isS=new boolean[totalLength];
		int index=0;
		int seenSs=0;
		long total=0;
		for (Block b:blocks) {
			for (int i=0; i<b.s.length; i++) {
				if (b.s[i]=='s') {
					seenSs++;
				}
				else {
					total+=seenSs;
				}
			}
		}
		System.out.println(total);
	}
	
	private static class Block implements Comparable<Block> {
		char[] s;
		long sCount=0, tCount=0;
		public Block(String st) {
			s=st.toCharArray();
			for (char c:s) {
				if (c=='s')
					sCount++;
				else
					tCount++;
			}
		}
		public int compareTo(Block o) {
			long me=sCount*o.tCount;
			long him=tCount*o.sCount;
			
			return -Long.compare(me, him);
		}
		public String toString() {
			return new String (s);
		}
	}
	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}

}