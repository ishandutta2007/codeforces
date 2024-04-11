import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*\
1
3
1 2 3

 */
public class B {
	static ArrayList<Integer> ans=new ArrayList<>();

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), oa[]=fs.readArray(n);
			int[] a=oa.clone();
			sort(oa);
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) if (oa[j]==a[i]) {
					oa[j]=2_000_000_000;
					a[i]=j+1;
					break;
				}
			}
//			System.out.println(Arrays.toString(a));
			
			
			
			for (int i=n; i>1; i--) {
				int index=0;
				for (int j=0; j<n; j++) if (a[j]==i) index=j;
				shiftBy(i-1, index+1, a);
			}
			System.out.println(ans.size()/3);
			for (int i=0; i<ans.size(); i+=3) {
				System.out.println(ans.get(i)+" "+ans.get(i+1)+" "+ans.get(i+2));
			}
			ans.clear();
		}
	}
	
	static void shiftBy(int last, int shiftBy, int[] a) {
		if (shiftBy==0 || shiftBy==last+1) return;
		int[] nA=a.clone();
		for (int i=0; i<=last; i++) {
			a[i]=nA[(i+shiftBy)%(last+1)];
		}
		ans.add(1);
		ans.add(last+1);
		ans.add(shiftBy);
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