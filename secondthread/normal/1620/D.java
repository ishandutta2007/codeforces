import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;
/*


3
2 3 4
3

3
29 31 30

 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			boolean[] valuesMod3=new boolean[3];
//			boolean hit2=false, hit4=false, hitNon24=false;
			boolean have1=false;
			int max=0;
			int n=fs.nextInt();
			HashSet<Integer> values=new HashSet<>();
			for (int i=0; i<n; i++) {
				int x=fs.nextInt();
				max=Math.max(max, x);
				values.add(x);
				valuesMod3[x%3]=true;
				if (x==1) have1=true;
			}
			//everything %3 == 0, easy
			if (!valuesMod3[1] && !valuesMod3[2]) {
				System.out.println(max/3);
				continue;
			}
			//only 0s and one other value
			if (!valuesMod3[1] || !valuesMod3[2]) { //maybe?
				System.out.println(max/3+1);
				continue;
			}
			
			//have at least a 1 and a 2, %3
			if (have1) {
				System.out.println((max+2)/3+1);	
				continue;
			}
			else {
				//this is the 2 3 4 case => 2, 2, 3
//				if (valuesMod3[0] && valuesMod3[1] && valuesMod3[2] && max==4) {
//					System.out.println(3);
//					continue;
//				}
				if (max%3==1 && values.contains(max-1)) {
					System.out.println((max+1)/3+1+1);
					continue;
				}
			}
			//take 2 2s, and all 3s
			System.out.println((max+1)/3+1);
		}
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