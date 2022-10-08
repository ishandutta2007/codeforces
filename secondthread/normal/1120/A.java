import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int wreathSize=fs.nextInt();
		int nPeople=fs.nextInt();
		int nTotalRequired=fs.nextInt();
		int nRemovable=n-wreathSize*nPeople;
		int[] a=fs.readArray(n);
		int[] nRequired=new int[6_000_00];
		int nUnique=0;
		for (int i=0; i<nTotalRequired; i++) {
			int type=fs.nextInt();
			if (nRequired[type]==0)
				nUnique++;
			nRequired[type]++;
		}
		int[] unique=new int[nUnique];
		int[] indexInUnique=new int[6_000_00];
		Arrays.fill(indexInUnique, -1);
		int index=0;
		for (int i=0; i<nRequired.length; i++) {
			if (nRequired[i]!=0) {
				indexInUnique[i]=index;
				unique[index++]=i;
			}
		}
		int[][] beforeStop=new int[n/wreathSize+1][nUnique];
		int[] seenOfUnique=new int[nUnique];
		for (int i=0; i<=n/wreathSize; i++) {
			beforeStop[i]=seenOfUnique.clone();
			for (int j=0; j<wreathSize&&i*wreathSize+j<n; j++) {
				index=i*wreathSize+j;
				if (indexInUnique[a[index]]!=-1) {
					seenOfUnique[indexInUnique[a[index]]]++;
				}
			}
		}
		
		int[][] indexOfIthUnique=new int[nUnique][];
		for (int i=0; i<nUnique; i++)
			indexOfIthUnique[i]=new int[seenOfUnique[i]];
		
		Arrays.fill(seenOfUnique, 0);
		for (int i=0; i<n; i++) {
			if (indexInUnique[a[i]]==-1)
				continue;
			indexOfIthUnique[indexInUnique[a[i]]][seenOfUnique[indexInUnique[a[i]]]]=i;
			seenOfUnique[indexInUnique[a[i]]]++;
		}
		PrintWriter out=new PrintWriter(System.out);
		
		start:for (int startPoint=0; startPoint<=n/wreathSize; startPoint++) {
			int startIndex=startPoint*wreathSize;
			if (startIndex+wreathSize>n)
				continue;
			int lastNeeded=startIndex;
			for (int i=0; i<nUnique; i++) {
				int neededOfI=nRequired[unique[i]]+beforeStop[startPoint][i];
				if (indexOfIthUnique[i].length<neededOfI)
					continue start;
				lastNeeded=Math.max(lastNeeded, indexOfIthUnique[i][neededOfI-1]);
			}
			if (startIndex+wreathSize+nRemovable>lastNeeded) {
				ArrayList<Integer> toRemove=new ArrayList<>();
				
				for (int i=startIndex; i<n&&nRemovable>0; i++) {
					if (nRequired[a[i]]==0) {
						nRemovable--;
						toRemove.add(i+1);
					}
					else {
						nRequired[a[i]]--;
					}
				}
				
				out.println(toRemove.size());
				for (int i:toRemove)
					out.print(i+" ");
				out.close();
				return;
			}
		}
		out.println(-1);
		out.close();
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreElements())
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}