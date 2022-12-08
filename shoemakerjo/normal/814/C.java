import java.io.*;
import java.util.*;
public class ImpassionedCirculation {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(bf.readLine());
		String line = bf.readLine();
		int q = Integer.parseInt(bf.readLine());
		
		String alph = "abcdefghijklmnopqrstuvwxyz";
		
		int[][] ans = new int[26][n+1];
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j <= n; j++) {
				ans[i][j] = j;
			}
		}
		
		for (int i = 0; i < 26; i++) {
			
			
			char c = alph.charAt(i); //examining current character as if favorite
			ArrayList<block> bl = new ArrayList<block>(); //creating list of runs
			
			boolean inRun = false; //whether or not the sequence is in a block (starts off as not)
			int start = 0; //start of a current block (means nothing here)
			
			for (int j = 0; j < n; j++) {
				
				if (line.charAt(j)==c) {
					if (!inRun) { //start a block
						inRun = true;
						start = j;
					}
				}
				else {
					if (inRun) {
						inRun = false;
						bl.add(new block(start, j-1)); //block ended at previous character
					}
				}
			}
			if (inRun) { //add a block for the last section
				bl.add(new block(start, n-1));
			}
			
			//calculated runs
			
			for (int j = 0; j < bl.size(); j++) {
				//start at this block
				
				block st = bl.get(j);
				int cursize = st.size();
				int cost = 0;
				int prevh = st.high;
				ans[i][cost] = Math.max(ans[i][cost], cursize);
				
				for (int k = j+1; k < bl.size(); k++) {
					
					block b = bl.get(k);
					int ccost = b.low-prevh-1; //cost of going between the blocks
					
					for (int l = 0; l <= ccost; l++) {
						ans[i][l+cost] = Math.max(ans[i][l+cost], cursize+l);
					}
					
					cost+=ccost; //this adds the cost of appending the next item to the current cost
					
					cursize += b.size(); // adds size of next block
					
					cursize+=ccost; //this adds the size we appended
					
					prevh = b.high;//update previous high 
					
					ans[i][cost] = Math.max(ans[i][cost], cursize); //update current position just in case
				}
				for (int k = cost; k <= n; k++) { //run with appending to open ends (extra check / add on for end or beginning)
					int cur = cursize+(k-cost);
					cur = Math.min(cur, n);
					ans[i][k] = Math.max(ans[i][k], cur);
				}
//				if (i == 0) System.out.println(j + " " + Arrays.toString(ans[0]));

			}
		}
		
		//double checking ...
		for (int i = 0; i < 26; i++) {
			for (int j = 1; j <= n; j++) {
				ans[i][j] = Math.max(ans[i][j], ans[i][j-1]);
			}
		}
		//everything should be calculated??
		
		for (int i = 0; i < q; i++) {
			String[] cs = bf.readLine().split(" ");
			int num = Integer.parseInt(cs[0]);
			int index = alph.indexOf(cs[1].charAt(0));
			pw.println(ans[index][num]);
		}
//		System.out.println(Arrays.toString(ans[0]));
		pw.close();
	}
	
	static class block  {
		public int low, high;
		public block (int low, int high) {
			this.low = low;
			this.high = high;
		}
		
		public int size() {
			return (high-low)+1;
		}
		
		public String toString() {
			return "{" + low + ", " + high + "}";
		}
	}

}