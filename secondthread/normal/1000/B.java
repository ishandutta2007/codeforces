import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int maxTime=fs.nextInt();
		int[] flips=fs.readArray(n);
		int[] sections=new int[n+1];
		sections[0]=flips[0];
		sections[n]=maxTime-flips[n-1];
		for (int i=1; i<n; i++)
			sections[i]=flips[i]-flips[i-1];
		
		int normal=0;
		for (int i=0; i<sections.length; i+=2)
			normal+=sections[i];
		
		int onTime=0, offTime=0;
		for (int i=0; i<sections.length; i++) if (i%2==0) onTime+=sections[i]; else offTime+=sections[i];
		
//		System.out.println("normal: "+normal);
		int bestOnTime=normal;
		int onPostTime=0, offPostTime=0;
		for (int i=sections.length-1; i>=0; i--) {
			if (i%2==0) {
				onTime-=sections[i];
				offPostTime+=sections[i];
				if (sections[i]!=1)bestOnTime=Math.max(bestOnTime, onTime+onPostTime+1);
			}
			else {
				offTime-=sections[i];
				onPostTime+=sections[i];
				if (sections[i]!=1)bestOnTime=Math.max(bestOnTime, onTime+onPostTime-1);
			}
		}
		System.out.println(bestOnTime);
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}