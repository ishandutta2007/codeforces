import java.util.Arrays;
import java.util.Scanner;

public class SummoningMinions2 {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[][] cost=new int[k][n];
			for (int i=0; i<n; i++) {
				int a=fs.nextInt(), b=fs.nextInt();
				for (int spot=0; spot<k; spot++)
					cost[spot][i]=-(-(k-1)*b+spot*b+a);
			}
			hungarian(cost);
			boolean[] chosen=new boolean[n];
			for (int i=0; i<k; i++) chosen[rowMatchesWith[i]]=true;
			System.out.println(k-1 + 2*(n-k) + 1);
			for (int i=0; i+1<k; i++) {
				System.out.print(1+rowMatchesWith[i]+" ");
			}
			for (int i=0; i<n; i++) if (!chosen[i]) System.out.print((1+i)+" -"+(1+i)+" ");
			System.out.println(rowMatchesWith[k-1]+1);
		}
	}

	// finds MINIMUM total matching cost of 
	// each row to some column, using each col at most once
	// **nRows must be <= nCols**
	//rowMatchWith[i] = the column that row i matched with
	static int[] rowMatchesWith; 
	static int hungarian(int[][] a) {
		int n=a.length, m=a[0].length; if (n>m) throw null;
		int[] u=new int[n], v=new int[m+1]; //edge (i->j) >= u[i]+v[j]
		int[] p=new int[m+1]; //p[j] = left match for right node j
		Arrays.fill(p, -1);
		for (int i=0; i<n; i++) {//find alternating path for node i
			int j0=m; p[j0]=i;
			int[] dist=new int[m+1], from=new int[m+1];
			boolean[] seen=new boolean[m+1];
			Arrays.fill(dist, Integer.MAX_VALUE);
			Arrays.fill(from, -1);
			while (p[j0]!=-1) {
				seen[j0]=true; int i0=p[j0], delta=Integer.MAX_VALUE, j1=-1;
				for (int j=0; j<m; j++) {//consider edges i0 -> everything
					if (seen[j]) continue;
					int candDist=a[i0][j]-u[i0]-v[j];
					if (candDist<dist[j]) {dist[j]=candDist; from[j]=j0;}
					if (dist[j]<delta) {delta=dist[j]; j1=j;}
				}
				//it costs at least delta to get somewhere else,
				//subtract that from all distances and add cost to u, v, arrays
				//from all done -> not done edges
				for (int j=0; j<=m; j++) {
					if (seen[j]) {u[p[j]]+=delta; v[j]-=delta;}
					else dist[j]-=delta;
				}
				j0=j1;
			}
			//flip alternating path
			while (j0!=m) { int j1=from[j0]; p[j0]=p[j1]; j0=j1; }
		}
		//sum of deltas is stored at v[m] coincidentally
		int ans=-v[m];
		rowMatchesWith=new int[n];
		for (int j=0; j<m; j++) if (p[j]!=-1) rowMatchesWith[p[j]]=j;
		return ans;
	}

}