import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
/*
4 1
0
2
1
3
3
3

7 6
1 6 4 2 3 5 4
 */
public class D {
	
	static Scanner fs;

	static int[] realAns= {1, 6, 4, 2, 3, 5, 4};
	
	public static void main(String[] args) {
//		FastScanner fs=new FastScanner();
		fs=new Scanner(System.in);
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int k=fs.nextInt();
			int abAnd=queryAnd(0, 1);
			int bcAnd=queryAnd(1, 2);
			int caAnd=queryAnd(0, 2);
			int abOr=queryOr(0, 1);
			int bcOr=queryOr(1, 2);
			int caOr=queryOr(0, 2);
			int[] values=new int[n];
			for (int bit=0; bit<=30; bit++) {
//				System.out.println("Checking bit "+bit);
				int perfectCount=0;
				for (int mask=0; mask<1<<3; mask++) {
					boolean[] has=new boolean[3];
					for (int i=0; i<3; i++) has[i]=(mask&(1<<i))!=0;
					if (((abAnd&(1<<bit))!=0) !=(has[0] && has[1])) continue;
					if (((caAnd&(1<<bit))!=0) !=(has[0] && has[2])) continue;
					if (((bcAnd&(1<<bit))!=0) !=(has[1] && has[2])) continue;
					
					if (((abOr&(1<<bit))!=0) !=(has[0] || has[1])) continue;
					if (((caOr&(1<<bit))!=0) !=(has[0] || has[2])) continue;
					if (((bcOr&(1<<bit))!=0) !=(has[1] || has[2])) continue;
					for (int i=0; i<3; i++)
						if (has[i]) values[i]+=1<<bit;
//					System.out.println("Mask "+mask+" is perfect");
					perfectCount++;
				}
				if (perfectCount!=1) throw null;
			}
			for (int i=3; i<n; i++) {
				int and=queryAnd(0, i);
				int or=queryOr(0, i);
				int xor=and^or;
				values[i]=values[0]^xor;
			}
			
			Arrays.sort(values);
//			System.err.println("Values: "+Arrays.toString(values));
			System.out.println("finish "+(values[k-1]));
		}
	}
	
	static int queryAnd(int a, int b) {
		System.out.println("and "+(a+1)+" "+(b+1));
//		return realAns[a]&realAns[b];
		return fs.nextInt();
	}
	
	static int queryOr(int a, int b) {
		System.out.println("or "+(a+1)+" "+(b+1));
//		return realAns[a]|realAns[b];
		return fs.nextInt();
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