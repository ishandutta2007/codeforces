import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nBoxes=fs.nextInt();
		long[] sums=new long[nBoxes];
		HashMap<Long, Integer> boxOf=new HashMap<>();
		int[][] boxes=new int[nBoxes][];
		long total=0;
		for (int i=0; i<nBoxes; i++) {
			int size=fs.nextInt();
			boxes[i]=new int[size];
			for (int j=0; j<size; j++) {
				boxes[i][j]=fs.nextInt();
				boxOf.put((long)boxes[i][j], i);
				sums[i]+=boxes[i][j];
			}
			total+=sums[i];
		}
		if (total%nBoxes!=0) {
			System.out.println("No");
			return;
		}
		
		long target=total/nBoxes;
		int[][] masks=new int[nBoxes][];
		ArrayList<Integer>[][] maskLoops=new ArrayList[nBoxes][];
		for (int i=0; i<nBoxes; i++) {
			masks[i]=new int[boxes[i].length];
			maskLoops[i]=new ArrayList[boxes[i].length];
			for (int j=0; j<maskLoops[i].length; j++) maskLoops[i][j]=new ArrayList<>();
			
			inner:for (int j=0; j<boxes[i].length; j++) {
				long startVal=boxes[i][j], lookingFor=target-(sums[i]-startVal);
				maskLoops[i][j].add((int)lookingFor);
				int mask=1<<i;
				while (lookingFor!=startVal) {
					if (!boxOf.containsKey(lookingFor)) continue inner;
					int nextBox=boxOf.get(lookingFor);

					//if we have already used this box, it won't work
					if ((mask&(1<<nextBox))!=0) continue inner;
					
					mask|=1<<nextBox;
					lookingFor=target-(sums[nextBox]-lookingFor);
					/*if (lookingFor!=startVal) */maskLoops[i][j].add((int)lookingFor);
				}
//				System.out.println("Mask loops for box: "+i+" starting at "+startVal+" gives "+);
				
				//otherwise it worked
				masks[i][j]=mask;
			}
		}
		
		boolean[] possible=new boolean[1<<nBoxes];
		int[] maskFrom=new int[1<<nBoxes];
		int[] indexToUse=new int[1<<nBoxes];
		possible[0]=true;
		for (int mask=1; mask<1<<nBoxes; mask++) {
			int lowestBit=Integer.numberOfTrailingZeros(Integer.lowestOneBit(mask));
			/*
			for (int i:masks[lowestBit]) {
				if ((mask&i)==i && possible[mask^i]) {
					possible[mask]=true;
					break;
				}
			}
			*/
			
			for (int i=0; i<masks[lowestBit].length; i++) {
				int m=masks[lowestBit][i];
				if ((mask&m)==m && possible[mask^m]) {
					possible[mask]=true;
					maskFrom[mask]=mask^m;
					indexToUse[mask]=i;
					break;
				}
			}
		}
		if (!possible[(1<<nBoxes)-1]) {
			System.out.println("No");
			return;
		}
		System.out.println("Yes");
		ArrayList<ArrayList<Integer>> loops=new ArrayList<>();
		int mask=(1<<nBoxes)-1;
		while (mask!=0) {
//			System.out.println("At mask: "+Integer.toBinaryString(mask));
			int lowestBit=Integer.numberOfTrailingZeros(Integer.lowestOneBit(mask));
			loops.add(maskLoops[lowestBit][indexToUse[mask]]);
			mask=maskFrom[mask];
		}
		
//		System.out.println("Loops: "+loops);
		
		int[] takeFrom=new int[nBoxes];
		int[] boxGiveTo=new int[nBoxes];
		for (ArrayList<Integer> loop:loops) {
			for (int i=0; i<loop.size(); i++) {
				int cur=loop.get(i), next=loop.get((i+1)%loop.size());
				int curBox=boxOf.get((long)cur), nextBox=boxOf.get((long)next);
				takeFrom[nextBox]=next;
				boxGiveTo[nextBox]=curBox;
			}
		}
		for (int i=0; i<nBoxes; i++) {
			System.out.println(takeFrom[i]+" "+(boxGiveTo[i]+1));
		}
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