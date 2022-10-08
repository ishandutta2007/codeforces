import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

public class B {
	
	static boolean debug=false;
	static int target=1_000_000_001;
	static int guesses=0;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		//find max
		while (true) {
			target=new Random().nextInt(1_000_000_001);
			guesses=0;
			String line=fs.next();
			if (line.equals("end")||line.equals("mistake"))
				return;
			long max=1, prev=0;
			String input;
			while (true) {
				System.out.println("? "+prev+" "+max);
				System.out.flush();
				guesses++;
				if (debug)
					input=(prev%target)>=(max%target)?"x":"y";
				else
					input=fs.next();
				if (input.equals("e"))
					while (true);
				if (input.equals("x")) {
					break;
				}
				else {
					prev=max;
					max*=2;
				}
			}
			long min=prev+1;
			while (min!=max) {
				long mid=(max+min)/2;
//				System.out.println("min: "+min+" max: "+max);
				
				if (min+1==max) {
					System.out.println("? "+min+" "+max);
					System.out.flush();
					guesses++;
					if (debug)
						input=(min%target)>=(max%target)?"x":"y";
					else 
						input=fs.next();
					if (input.equals("e"))
						while (true);
					if (input.equals("x")) {
						min=max;
					}
					else {
						max=min;
					}
					break;
				}
				
				System.out.println("? "+(prev)+" "+mid);
				System.out.flush();
				guesses++;
				if (debug)
					input=(prev%target)>=(mid%target)?"x":"y";
				else 
					input=fs.next();
				if (input.equals("e"))
					while (true);
				if (input.equals("x")) {
					max=mid;
				}
				else {
					min=mid+1;
				}
			}
			System.out.println("! "+min);
			System.out.flush();
//			System.err.println(guesses);
		}
		//bs for mod
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}