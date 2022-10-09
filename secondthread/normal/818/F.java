import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class LevelGeneration {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nQueries=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int nNodes=fs.nextInt();
			long minNodesToTree=0, maxNodesToTree=nNodes;
			long bestAnswer=nNodes-1;
			while (minNodesToTree<=maxNodesToTree) {
				long mid=(minNodesToTree+maxNodesToTree)/2;
				long nodesLeft=nNodes-mid;
				long cliqueEdges=nodesLeft*(nodesLeft-1)/2;
				long curAnswer=cliqueEdges+mid;
//				System.out.println("getting rid of "+mid+" gives answer: "+curAnswer);
				if (cliqueEdges>mid) {
					long optionalEdges=cliqueEdges-(nodesLeft-1);
					if (cliqueEdges-(optionalEdges)<=mid) {
						bestAnswer=Math.max(bestAnswer, mid*2);
					}
					minNodesToTree=mid+1;
				}
				else {
					bestAnswer=Math.max(bestAnswer, curAnswer);
					maxNodesToTree=mid-1;
				}
			}
			out.println(bestAnswer);
		}
		out.close();
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
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