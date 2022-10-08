import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long[] a=fs.readLongArray(n);
		long[] oa=a.clone();
		final boolean[] usedZero=new boolean[n];
		int[] b=fs.readArray(n);
		for (int i=0; i<n; i++) b[i]--;
		int[] inDeg=new int[n];
		for (int i:b) if (i!=-2) inDeg[i]++;
		ArrayDeque<Integer> toRemove=new ArrayDeque<>();
		ArrayList<Integer> topSort=new ArrayList<>();	
		final int[] indexInTopsort=new int[n];
		for (int i=0; i<n; i++) if (inDeg[i]==0) toRemove.add(i);
		while (!toRemove.isEmpty()) {
			int next=toRemove.removeFirst();
			indexInTopsort[next]=topSort.size();
			topSort.add(next);
			if (b[next]==-2)
				continue;
			inDeg[b[next]]--;
			if (inDeg[b[next]]==0)
				toRemove.addLast(b[next]);
		}
		
		long ans=0;
		for (int i:topSort) {
			ans+=a[i];
			if (b[i]==-2) continue;
			if (a[i]>0) {
				usedZero[i]=false;
				a[b[i]]+=a[i];
			}
			else {
				usedZero[i]=true;
			}
		}
//		System.out.println("Topsort: "+topSort);
//		System.out.println("used zero: "+Arrays.toString(usedZero));
		ArrayList<Integer> perm=new ArrayList<>();
		for (int i=0; i<n; i++) perm.add(i);
		Collections.sort(perm, (aa, bb) -> {
			//put zeros last
			if (usedZero[aa] != usedZero[bb]) {
				if (usedZero[aa]) return 1;
				else return -1;
			}
			if (usedZero[aa]) {
				//zeros right to left
				return -Integer.compare(indexInTopsort[aa], indexInTopsort[bb]);
			}
			return Integer.compare(indexInTopsort[aa], indexInTopsort[bb]);
		});
		System.out.println(ans);
		for (int i:perm) {
			System.out.print(i+1+" ");
		}
		System.out.println();
		
		long ansCheck=0;
		for (int i:perm) {
			ansCheck+=oa[i];
			if (b[i]!=-2) {
				oa[b[i]]+=oa[i];
			}
		}
//		System.out.println(ansCheck);
		if (ansCheck!=ans) throw null;
	}
	
	void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
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
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}