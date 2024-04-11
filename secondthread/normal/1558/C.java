import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {
	
	static ArrayList<Integer> answers=new ArrayList<>();

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			answers.clear();
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			//TODO: check if possible;
			for (int i=0; i<a.length; i++) {
				if (a[i]%2==i%2) {
					System.out.println("-1");
					continue outer;
				}
			}
			
			if (n%2==0) throw null;
			for (int biggerVal=n, smallerVal=n-1, gotoPos=n-1; 
					biggerVal>1; 
					biggerVal-=2, smallerVal-=2, gotoPos-=2) {
				swap(indof(biggerVal, a), a);
				swap(indof(smallerVal, a)-1, a);
				swap(indof(smallerVal, a)+1, a);
				swap(2, a);
				swap(gotoPos, a);
			}
			for (int i=0; i<n; i++) if (a[i]!=i+1) throw null;
			System.out.println(answers.size());
			for (int i:answers)
				System.out.print(i+" ");
			System.out.println();
		}
	}
	
	static int indof(int x, int[] a) {
//		System.out.println("Looking for "+x+" in "+Arrays.toString(a));
		for (int i=0; i<a.length; i++) if (a[i]==x) return i;
		throw null;
	}
	
	static void swap(int prefixSize, int[] a) {
		prefixSize++;
		if (prefixSize%2!=1) throw null;
		int[] newA=a.clone();
		for (int i=0; i<prefixSize; i++) {
			a[i]=newA[prefixSize-1-i];
		}
		answers.add(prefixSize);
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