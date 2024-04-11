import java.util.Scanner;

public class A024 {
	static class node {
		node a=null, b=null;
		boolean ab, bb;
		int ac,bc;

		public node() {
		}

		public void add(node c,int dist) {
			if (a == null) {
				a = c;
				ab = true;
				ac = dist;
			} else {
				b = c;
				bb = true;
				bc = dist;
			}
			if (c.a == null) {
				c.a = this;
				c.ab = false;
				c.ac = dist;
			} else {
				c.b = this;
				c.bb = false;
				c.bc = dist;
			}
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		node[] nodes = new node[n];
		for (int x = 0; x < n; x++) {
			nodes[x] = new node();
		}
		int s = 0;
		for (int x = 0; x < n; x++) {
			int a = in.nextInt() - 1, b = in.nextInt() - 1;
			int c = in.nextInt();
			s+=c;
			nodes[a].add(nodes[b],c);
		}
		node cur = nodes[0];
		node prev = null;
		int sum = 0;
		for(int x = 0;x<n;x++){
			node a = cur.a, b = cur.b;
			boolean d = cur.ab,e=cur.bb;
			int f = cur.ac,g=cur.bc;
			if(a==prev) {
				a = b;
				d = e;
				f = g;
			}
			if(!d) {
				sum+=f;
			}
			prev = cur;
			cur = a;
		}
		int sumb = s - sum;
		System.out.println(sumb<sum?sumb:sum);
	}
}