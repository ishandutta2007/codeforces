import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class D {
	static final boolean debug=false;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long querySum=fs.nextLong();
		int[] a=fs.readArray(n);
		long total=0;
		AVLTree tree=new AVLTree();
		for (int nextNode=0; nextNode<n; nextNode++) {
			tree.addOffset(a[nextNode]);
			tree.add(a[nextNode]);
			int sumsInRange=tree.firstIndexOf(querySum);
			total+=sumsInRange;
		}
		System.out.println(total);
	}
	
	static class AVLTree {
		//added: 0, -5, -4, -7, -11
		// 
		AVLNode root;
		long offset;
		
		public void addOffset(long offset) {
			this.offset+=offset;
		}
		
		public void add(long l) {
			l-=offset;
			if (root==null)
				root=new AVLNode(l);
			else
				root=root.add(l);
		}
		
		public int firstIndexOf(long l) {
			l-=offset;
			if (root==null)
				return 0;
			return root.firstIndexOf(l);
		}
	}
	
	static class AVLNode {
		AVLNode lChild, rChild;
		long value;
		int height;
		int size;
		
		public AVLNode(long value) {
			height=1;
			this.value=value;
			size=1;
		}
		
		public AVLNode add(long v) {
			AVLNode toReturn=this;
			if (v<=value) {
				if (lChild==null) {
					lChild=new AVLNode(v);
					size++;
				}
				else {
					lChild=lChild.add(v);
					toReturn=balance();
				}
			}
			else {
				if (rChild==null) {
					rChild=new AVLNode(v);
					size++;
				}
				else {
					rChild=rChild.add(v);
					toReturn=balance();
				}
			}
			height=Math.max(lHeight(), rHeight())+1;
			size=lSize()+rSize()+1;
			return toReturn;
		}
		
		public AVLNode balance() {
			if (lChild==null&&rChild==null) {
				height=1;
				return this;
			}
			if (Math.abs(lHeight()-rHeight())>1) {
				if (lHeight()>rHeight()) {
					if (lChild.rHeight()>lChild.lHeight())
						lChild=lChild.leftRot();
					return rightRot();
				}
				else {
					if (rChild.lHeight()>rChild.rHeight())
						rChild=rChild.rightRot();
					return leftRot();
				}
			}
			return this;
		}
		
		public AVLNode leftRot() {
			//    A			->		C
			//  B   C			  A    E
			//     D  E  		B  D    F
			//         F			
			AVLNode oldRight=rChild;
			rChild=rChild.lChild;
			oldRight.lChild=this;
			height=Math.max(lHeight(), rHeight())+1;
			oldRight.height=Math.max(oldRight.lHeight(), oldRight.rHeight())+1;
			size=lSize()+rSize()+1;
			oldRight.size=oldRight.lSize()+oldRight.rSize()+1;
			return oldRight;
		}
		
		public AVLNode rightRot() {
			AVLNode oldLeft=lChild;
			lChild=lChild.rChild;
			oldLeft.rChild=this;
			height=Math.max(lHeight(), rHeight())+1;
			oldLeft.height=Math.max(oldLeft.lHeight(), oldLeft.rHeight())+1;
			size=lSize()+rSize()+1;
			oldLeft.size=oldLeft.lSize()+oldLeft.rSize()+1;
			return oldLeft;
		}
		
		int lHeight() {
			return lChild==null?0:lChild.height;
		}
		
		int rHeight() {
			return rChild==null?0:rChild.height;
		}
		
		int lSize() {
			return lChild==null?0:lChild.size;
		}
		
		int rSize() {
			return rChild==null?0:rChild.size;
		}
		
		//returns the index in this subtree where val would be placed if inserted
		//in a left-biased way
		public int firstIndexOf(long val) {
			if (val>value) {
				return (rChild==null?0:rChild.firstIndexOf(val))+lSize()+1;
			}
			else {
				return lChild==null?0:lChild.firstIndexOf(val);
			}
		}
		public String toString() {
			return "("+(lChild==null?"":lChild.toString())+") "+value+" ("+(rChild==null?"":rChild.toString())+")";
		}
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}