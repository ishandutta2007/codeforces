import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int p=fs.nextInt();
		int[] a=fs.readArray(n);
		sort(a);
		ArrayList<Integer> validXs=new ArrayList<>();
		for (int x=0; x<2001; x++) {
			if (tryX(x, a, p)) validXs.add(x);
		}
		System.out.println(validXs.size());
		for (int i:validXs)//
			System.out.print(i+" ");
		System.out.println();
	}
	
	static boolean tryX(int start, int[] a, int p) {
		int n=a.length;
		//some element of a can only be in a spot that is >= a[i]
		int[] spots=new int[n];
		for (int i=0; i<n; i++) spots[i]=start+i;
		int nextA=n-1;
		int spotsEarlier=0;
		
		for (int spotToFill=n-1; spotToFill>=-1; spotToFill--) {
			int needToPlace=0;
			while (nextA>=0 && (spotToFill==-1 || a[nextA]>spots[spotToFill])) {
				needToPlace++;
				nextA--;
				
			}
			//nWays*= num ways to place needToPlace things in spotsEarlier spots
			//      = spotsEarlier * (spotsEarlier-1) * (spotsEarlier-2) ... (spotsEarlier-needToPlace+1)
			if (p<=spotsEarlier) {
				return false;
			}
			spotsEarlier-=needToPlace;
			if (spotsEarlier<0) return false;
			
			
			spotsEarlier++;
		}
		return true;
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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