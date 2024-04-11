import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FS s=new FS(System.in);
		int n=s.nextInt();
		int minutesBroken=s.nextInt();
		PlaneTrip[] planes=new PlaneTrip[n];
		for (int i=0; i<n; i++) {
			planes[i]=new PlaneTrip(i+1, s.nextInt());
		}
		
		Arrays.sort(planes);
		
		Node tree=new Node();
		tree.generateRange(minutesBroken+1, minutesBroken+n);
		long penalty=0;
		int[] timeLeaving=new int[n];
		for (int planeIndex=planes.length-1; planeIndex>=0; planeIndex--) {
			PlaneTrip plane=planes[planeIndex];
			int importance=plane.importance;
			int minTime=plane.scheduledTime;
			int leaveTime=tree.getFirstEmptySpace(minTime);
			timeLeaving[minTime-1]=leaveTime;
			tree.markAsUsed(leaveTime);
			long penaltyCurrent=importance*(long)(leaveTime-minTime);
			penalty+=penaltyCurrent;
			minutesBroken++;
			/*if (planeIndex%10000==0) {
				System.out.println(planeIndex);
			}*/
		}
		PrintWriter pw=new PrintWriter(System.out);
		pw.write(penalty+"\n");
		for (int i:timeLeaving) {
			pw.write(i+" ");
		}
		pw.close();
	}

	private static class FS {
		BufferedReader br;
		StringTokenizer st;

		public FS(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}

class Node {
	Node left, right;
	int index;
	int leftmostChild=-1, rightmostChild=-1;
	boolean used=false;
	boolean haveEmptyChildren=false;
	
	public void generateRange(int left, int right) {
		if (left>right) {
			return;
		}
		leftmostChild=left;
		rightmostChild=right;
		int mid=(left+right)/2;
		index=mid;
		if (left<mid) {
			this.left=new Node();
			this.left.generateRange(left, mid-1);
			haveEmptyChildren=true;
		}
		if (right>mid) {
			this.right=new Node();
			this.right.generateRange(mid+1, right);
			haveEmptyChildren=true;
		}
	}
	
	public boolean getIsUsed(int index) {
		if (this.index==index) {
			return used;
		}
		if (index<this.index) {
			return left.getIsUsed(index);
		}
		else {
			return right.getIsUsed(index);
		}
	}
	
	public void markAsUsed(int index) {
		if (index==this.index) {
			used=true;
			return;
		}
		if (index<this.index) {
			left.markAsUsed(index);
			haveEmptyChildren=hasSpace(left)||hasSpace(right);
		}
		else {
			right.markAsUsed(index);
			haveEmptyChildren=hasSpace(left)||hasSpace(right);
		}
	}
	
	public int getFirstEmptySpace(int minEmptySpace) {
		//System.err.println("In first empty space, index: "+index+", minEmptySpace: "+minEmptySpace);
		if (!hasSpace(this)||rightmostChild<minEmptySpace) {
			return Integer.MAX_VALUE;
		}
		int leftIndex=left==null?Integer.MAX_VALUE:left.getFirstEmptySpace(minEmptySpace);
		if (leftIndex<Integer.MAX_VALUE) {
			return leftIndex;
		}
		if (!used&&this.index>=minEmptySpace) {
			return this.index;
		}
		
		return right==null?Integer.MAX_VALUE:right.getFirstEmptySpace(minEmptySpace);
	}
	
	public boolean hasSpace(Node n) {
		if (n==null) {
			return false;
		}
		return n.haveEmptyChildren||!n.used;
	}
	
}

class PlaneTrip implements Comparable<PlaneTrip> {
	public int scheduledTime, importance;
	
	public PlaneTrip(int scheduledTime, int importance) {
		this.scheduledTime=scheduledTime;
		this.importance=importance;
	}

	public int compareTo(PlaneTrip o) {
		
		return importance-o.importance;
	}
	
	
}