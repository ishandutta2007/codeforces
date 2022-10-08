import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class E {
	
	static final long MOD=998244353;

	static int[] minSubtreeSumOfSize=new int[2_000_000];
	static int[][] dp=new int[10000][2];
	
	public static void main(String[] args) {
		precomp();
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		for (int i=0; i<400; i++) {
			int ways=go(i, true, true);
			ways+=go(i, false, true);
//			if (ways!=0) System.out.println(i);
//			System.out.println(i+": "+ways);
		}
		FastScanner fs=new FastScanner();
//		int nNodes=fs.nextInt();
		boolean[] works=new boolean[2_000_000];
		int cur=1;
		while (cur<works.length) {
			works[cur]=true;
			cur++;
			if (cur<works.length) works[cur]=true;
			cur*=2;
			if (cur<works.length) works[cur]=true;
			cur++;
			if (cur<works.length) works[cur]=true;
			cur=cur*2-1;
			if (cur<works.length) works[cur]=true;
		}
		System.out.println(works[fs.nextInt()]?1:0);
	}
	
	static int go(int nNodes, boolean rootOdd, boolean lowestOdd) {
		if (nNodes==0) return 1;
		if (nNodes==1) {
			if (rootOdd==lowestOdd) return 1;
			else return 0;
		}
		if (dp[nNodes][(rootOdd^lowestOdd)?1:0]!=-1) return dp[nNodes][(rootOdd^lowestOdd)?1:0];
		long total=0;
		for (int toGiveLeft=0; toGiveLeft<nNodes; toGiveLeft++) {
			//make sure this leaves the root the right pairity
			if ((lowestOdd==rootOdd) ^ (toGiveLeft%2==0) )  {
				continue;
			}
			
			int rightSize=nNodes-toGiveLeft-1;
			//make sure this would leave the tree balanced
			if (minSubtreeSumOfSize[toGiveLeft]+toGiveLeft+minSubtreeSumOfSize[rightSize]+rightSize != minSubtreeSumOfSize[nNodes])  {
				continue;
			}
			
			long leftWays=go(toGiveLeft, rootOdd^true, lowestOdd);
			boolean rightOdd=lowestOdd^(toGiveLeft%2!=0)^true;
			long rightWays=go(rightSize, rootOdd, rightOdd);
			total+=leftWays*rightWays%MOD;
		}
		return dp[nNodes][(rootOdd^lowestOdd)?1:0]=(int)(total%MOD);
	}
	
	static void precomp() {
		for (int i=1; i<minSubtreeSumOfSize.length; i++)
			minSubtreeSumOfSize[i]=minSubtreeSumOfSize[i-1]+Integer.numberOfTrailingZeros(Integer.highestOneBit(i));
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
	}
	
}