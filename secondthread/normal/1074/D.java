import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

/*

12
2 1 2
2 1 1073741822
1 0 3 4
2 0 0
2 3 3
2 0 3
1 6 7 3
2 4 4
1 0 2 1
2 0 0
2 4 4
2 0 0


7
1 1 2 5
1 2 3 6
2 1 1
1 1 3 0
2 1 1
2 2 2
2 3 3

4
1 1 2 5
1 2 3 6
1 1 3 0
2 1 1

2
1 1 1 5
2 1 1
 */
public class _LiftLevel5D {

	static boolean encode=true;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nQueries=fs.nextInt();
		int last=0;
		DisjointSet dj=new DisjointSet();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int type=fs.nextInt();
			int lPrime=fs.nextInt(), rPrime=fs.nextInt();
			int l=lPrime^last, r=rPrime^last;
			if (l>r) {
				int temp=r;
				r=l;
				l=temp;
			}
			if (type==1) {
				int x=fs.nextInt()^last;
//				System.out.println("Got query "+type +" "+l+" "+r+" "+x);
				r++;
				dj.union(l, r, x);
			}
			else {
//				System.out.println("Got query "+type +" "+l+" "+r);
				r++;
				int lPar=dj.find(l), rPar=dj.find(r);
//				System.out.println("lPar: "+lPar+" rPar: "+rPar);
				if (lPar!=rPar) {
					out.println(-1);
					if (encode) last=1;
				}
				else {
					int ans=dj.xorToParent.get(l)^dj.xorToParent.get(r);
					out.println(ans);
					if (encode) last=ans;
				}
			}
		}
		out.close();
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreElements()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
	static class DisjointSet {
		HashMap<Integer, Integer> parent=new HashMap<>();
		HashMap<Integer, Integer> xorToParent=new HashMap<>();
		
		public int find(int i) {
			if (!parent.containsKey(i))
				return i;
			int curPar=parent.get(i);
			int res=find(curPar);
			
			if (res!=curPar) doubleJumpParent(i, curPar);
			return res;
		}
		
		public void doubleJumpParent(int child, int oldPar) {
			int newXor=xorToParent.get(child)^xorToParent.get(oldPar);
			int newPar=parent.get(oldPar);
//			System.out.println("Setting the new parent of "+child+" to "+newPar);
			parent.put(child, newPar);
			xorToParent.put(child, newXor);
		}
		
		public void union(int i, int j, int distanceBetween) {
			int iParent=find(i), jParent=find(j);
			if (iParent==jParent) return;
			//TODO: actually union them here
			if (i!=iParent) distanceBetween ^= xorToParent.get(i);
			if (j!=jParent) distanceBetween ^= xorToParent.get(j);
//			System.out.println("Making the parent of "+iParent+" "+jParent);
			parent.put(iParent, jParent);
			xorToParent.put(iParent, distanceBetween);
			xorToParent.put(jParent, 0);
		}
	}
	
}