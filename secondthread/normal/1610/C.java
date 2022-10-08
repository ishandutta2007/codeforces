import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
2
1 0
0 1
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Person[] people=new Person[n];
			for (int i=0; i<n; i++) people[i]=new Person(fs.nextInt(), fs.nextInt());
			int min=0, max=n;
			while (min!=max) {
				int mid=(min+max+1)/2;
				if (possible(people, mid)) {
					min=mid;
				}
				else {
					max=mid-1;
				}
			}
			System.out.println(min);
		}
	}
	
	static boolean possible(Person[] people, int target) {
		int used=0;
		for (Person p:people) {
			if (p.a<used) continue;
			if (p.b<target-1) continue;
			target--;
			used++;
		}
		return target<=0;
	}
	
	static class Person {
		int a, b;
		public Person(int a, int b) {
			this.b=a;
			this.a=b;
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