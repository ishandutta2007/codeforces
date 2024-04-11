import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		ArrayDeque<Integer> stk=new ArrayDeque<>();
		int[] matchWith=new int[n];
		Arrays.fill(matchWith, -1);
		for (int i=0; i<n; i++) {
			int curChar=line[i];
			if (!stk.isEmpty() && curChar!=line[stk.peekLast()]) {
				matchWith[stk.removeLast()]=i;
			}
			else {
				stk.addLast(i);
			}
		}
		if (!stk.isEmpty()) {
			System.out.println(-1);
			return;
		}
//		System.out.println(Arrays.toString(matchWith));
		int index=0;
		long length=0;
		while (index<n) {
//			System.out.println("At "+index);
			if (matchWith[index]==-1||line[index]=='(') {
				index++;
			}
			else {
				int far=matchWith[index];
				length+=far-index+1;
				index=far+1;
			}
		}
		System.out.println(length);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}