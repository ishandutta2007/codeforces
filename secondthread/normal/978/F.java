import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		Programmer[] programmers=new Programmer[n];
		int[] skills=fs.readArray(n);
		compress(skills);
		int[] cs=new int[210_000];
		for (int i:skills) {
			cs[i]++;
		}
		int[] presums=new int[cs.length];
		for (int i=0; i<presums.length; i++)
			presums[i]=cs[i]+(i!=0?presums[i-1]:0);
		
		for (int i=0; i<n; i++)
			programmers[i]=new Programmer(skills[i]);
		for (int i=0; i<m; i++) {
			int first=fs.nextInt()-1;
			int second=fs.nextInt()-1;
			programmers[first].adj.add(programmers[second]);
			programmers[second].adj.add(programmers[first]);
		}
//		Arrays.sort(programmers);
		for (int i=0; i<n; i++) {
			programmers[i].indexOf=i;
		}
		
		for (Programmer p:programmers) {
			int total=p.skill==0?0:presums[p.skill-1];
			for (Programmer q:p.adj)
				if (q.skill<p.skill) total--;
			System.out.print(total+" ");
		}
	}
	
	static void compress(int[] a) {
		HashSet<Integer> set=new HashSet<>();
		for (int i:a)
			set.add(i);
		int[] clone=new int[set.size()];
		int index=0;
		for (int i:set)
			clone[index++]=i;
		Arrays.sort(clone);
		HashMap<Integer, Integer> compress=new HashMap<>();
		for (int i=0; i<clone.length; i++)
			compress.put(clone[i], i);
		for (int i=0; i<a.length; i++)
			a[i]=compress.get(a[i]);
	}
	
	static class Programmer implements Comparable<Programmer> {
		int skill;
		int indexOf;
		ArrayList<Programmer> adj=new ArrayList<>();
		public Programmer(int skill) {
			this.skill=skill;
		}

		public int compareTo(Programmer o) {
			return skill-o.skill;
		}
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
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
}