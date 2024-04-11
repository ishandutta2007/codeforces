import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;
/*
1
2 3
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] maxes=new int[1_000_001];
		int[] mins=new int[1_000_001];
		long withAscent=0;
		for (int i=0; i<n; i++) {
			int l=fs.nextInt();
			int minSeen=Integer.MAX_VALUE, maxSeen=-1;
			boolean ascent=false;
			for (int j=0; j<l; j++) {
				int next=fs.nextInt();
				if (next>minSeen) {
					ascent=true;
				}
				minSeen=Math.min(minSeen, next);
				maxSeen=Math.max(maxSeen, next);
			}
			if (ascent) {
				withAscent++;
			}
			else {
				maxes[maxSeen]++;
				mins[minSeen]++;
			}
		}
		long ans=0;
//		System.out.println("Initial ascent: "+withAscent);
		ans+=withAscent*n + (n-withAscent)*withAscent;
//		System.out.println("Initial ans: "+ans);
		long maxSeen=0;
		for (int i=maxes.length-1; i>=0; i--) {
			ans+=mins[i]*maxSeen;
			maxSeen+=maxes[i];
		}
		System.out.println(ans);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
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
	}

}