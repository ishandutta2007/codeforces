import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
3 2
10 1 1
2 3 1
2 1
 */
public class D {

	static long fireballCost, fireballRange, berserkCost;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int nKeep=fs.nextInt();
		fireballCost=fs.nextInt();
		fireballRange=fs.nextInt();
		berserkCost=fs.nextInt();
		int[] perm=fs.readArray(n);
		for (int i=0; i<n; i++) perm[i]--;
		int[] indexOf=new int[n];
		for (int i=0; i<n; i++) indexOf[perm[i]]=i;
		
		int lastIndexOf=-1;
		boolean[] keep=new boolean[n];
		for (int i=0; i<nKeep; i++) {
			int nextThing=fs.nextInt()-1;
			keep[nextThing]=true;
			int nextIndex=indexOf[nextThing];
			if (nextIndex<lastIndexOf) {
				System.out.println(-1);
				return;
			}
			lastIndexOf=nextIndex;
		}
		
		boolean possible=true;
		long cost=0;
		int firstIndex=-1, lastIndex=-1;
		ArrayList<Integer> prefix=new ArrayList<>();
		for (int i=0; i<n; i++) {
			if (keep[perm[i]]) {
				long res=minCost(prefix, -1, perm[i]);
				if (res==-1) possible=false;
				else cost+=res;
				firstIndex=i;
				break;
			}
			else {
				prefix.add(perm[i]);
			}
		}
		prefix.clear();
		for (int i=n-1; i>=0; i--) {
			if (keep[perm[i]]) {
				long res=minCost(prefix, perm[i], -1);
				if (res==-1) possible=false;
				else cost+=res;
				lastIndex=i;
				break;
			}
			else {
				prefix.add(perm[i]);
			}
		}
		if (!possible) {
			System.out.println(-1);
			return;
		}
		
		for (int i=firstIndex; i!=lastIndex;) {
			int next=i+1;
			prefix.clear();
			while (!keep[perm[next]]) {
				prefix.add(perm[next]);
				next++;
			}
			long res=minCost(prefix, perm[i], perm[next]);
			if (res==-1) possible=false;
			else cost+=res;
			i=next;
		}
		if (!possible) {
			System.out.println(-1);
			return;
		}
		
		System.out.println(cost);
	}
	
	//-1 if impossible, otherwise min cost
	static long minCost(ArrayList<Integer> middle, int l, int r) {
		if (middle.isEmpty()) return 0;
		long best=Long.MAX_VALUE;
		Collections.sort(middle);
		for (int toUse=0; toUse<=middle.size(); toUse++) {
			if ((middle.size()-toUse)%fireballRange!=0) {
				continue;
			}
			if (toUse==middle.size()) {
				if (Math.max(l, r)>middle.get(middle.size()-1)) {
					best=Math.min(best, berserkCost*middle.size());
				}
				continue;
			}
			best=Math.min(best, berserkCost*toUse + fireballCost*((middle.size()-toUse)/fireballRange));
		}
		return best==Long.MAX_VALUE?-1:best;
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