import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a1=fs.readArray(n);
			int[] a2=fs.readArray(n);
			for (int i=0; i<n; i++) {
				a1[i]--; a2[i]--;
			}
			int[] indexOf1=new int[n], indexOf2=new int[n];
			for (int i=0; i<n; i++) indexOf1[a1[i]]=i;
			for (int i=0; i<n; i++) indexOf2[a2[i]]=i;
			boolean[] hit=new boolean[n];
			int nGroups=0;
			for (int i=0; i<n; i++) {
				if (hit[i]) continue;
				ArrayDeque<Integer> queue=new ArrayDeque<>();
				nGroups++;
				hit[i]=true;
				queue.add(i);
				while (!queue.isEmpty()) {
					int next=queue.remove();
					int[] toCheck= {a1[next], a2[next]};
					for (int cand:toCheck) {
						int[] posOfCand= {indexOf1[cand], indexOf2[cand]};
						for (int otherPos:posOfCand) {
							if (!hit[otherPos]) {
								hit[otherPos]=true;
								queue.add(otherPos);
							}
						}
					}
				}
			}
			
			long ans=1;
			for (int i=0; i<nGroups; i++) ans=(ans+ans)%1_000_000_007;
			System.out.println(ans);
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