import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*
3
2 1 2

18
5 4 3 2 1 2 3 4 5 1 2 3 4 5 4 3 2 1

20
3 2 1 2 3 1 2 3 2 1 3 2 1 2 3 1 2 3 2 1
 */
public class D {

	static final boolean debug=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=1;//fs.nextInt();
//		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			Stack positive=new Stack(), negative=new Stack();
			positive.push(n-1, 0, a[n-1]);
			negative.push(n-1, 0, -a[n-1]);
			int[] dp=new int[n];
			for (int i=n-2; i>=0; i--) {
				int ans=1+Math.min(positive.prep(i, a[i]), negative.prep(i, -a[i]));
				if(debug) System.out.println("For i "+i+" got "+ans);
				dp[i]=ans;
				positive.push(i, ans, a[i]);
				negative.push(i, ans, -a[i]);
			}
			System.out.println(dp[0]);
		}
	}
	
	//assuming heights are positive
	static class Stack {
		ArrayDeque<Integer> indecies=new ArrayDeque<>(), 
				values=new ArrayDeque<>(), 
				heights=new ArrayDeque<>();
		
		//returns the min reachable dp value
		public int prep(int index, int height) {
			int ans=(int)1e9;
			while (!indecies.isEmpty() && heights.peekFirst()<height) {
				ans=Math.min(ans, values.peekFirst());
				if(debug) System.out.println("Popping "+heights.peek());
				pop(); //we will replace it
			}
			if (!indecies.isEmpty()) {
				ans=Math.min(ans, values.peekFirst());
				if (heights.peekFirst()==height) {
					pop();
				}
			}
			return ans;
		}
		
		public void push(int index, int value, int height) {
			indecies.addFirst(index);
			values.addFirst(value);
			heights.addFirst(height);
		}
		
		public void pop() {
			indecies.removeFirst();
			values.removeFirst();
			heights.removeFirst();
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}