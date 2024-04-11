import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
5 7
5 3 2 1 4
2 1 1 2 1

1 3
2
1
5 10
2 3 2 3 2
1 2 1 2 1
4 10
5 1 3 4
1 2 1 2
4 5
3 2 1 2
2 1 2 1

1
2 5
5 7
2 2

 */

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nApplications=fs.nextInt(), toFree=fs.nextInt();
			int[] memoryForApp=fs.readArray(nApplications);
			int[] importanceOfApp=fs.readArray(nApplications);
			ArrayList<Integer> cost1=new ArrayList<>(), cost2=new ArrayList<>();
			for (int i=0; i<nApplications; i++) {
				if (importanceOfApp[i]==1) cost1.add(memoryForApp[i]);
				else cost2.add(memoryForApp[i]);
			}
			Collections.sort(cost1);
			Collections.reverse(cost1);
			Collections.sort(cost2);
			Collections.reverse(cost2);

			//brute force the number of cost1 apps we remove
			long totalMemory=0;
			int cost=0;
			int p2=-1;
			int ans=Integer.MAX_VALUE;
			
			while (p2+1<cost2.size() && totalMemory<toFree) {
				p2++;
				totalMemory+=cost2.get(p2);
				cost+=2;
			}
			if (totalMemory>=toFree) {
				ans=Math.min(ans, cost);
			}
			
			for (int p1=0; p1<cost1.size(); p1++) {
				totalMemory+=cost1.get(p1);
				cost++;
				while (p2>=0 && totalMemory-cost2.get(p2)>=toFree) {
					totalMemory-=cost2.get(p2);
					p2--;
					cost-=2;
				}
				if (totalMemory>=toFree) {
					ans=Math.min(ans, cost);
				}
			}
			if (ans==Integer.MAX_VALUE) {
				System.out.println(-1);
			}
			else {
				System.out.println(ans);
			}
		}
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