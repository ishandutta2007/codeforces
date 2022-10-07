import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;



public class D131 {
	static class lol {
		ArrayList<lol> c,d;
		int dist;
		public lol() {
			c = new ArrayList<lol>();
			dist = -1;
		}

		public boolean o() {
			return c.size() == 1;
		}

		public void r() {
			for (lol lol : c) {
				lol.c.remove(this);
			}
			c.clear();
		}

		public void conn(lol lol) {
			lol.c.add(this);
			c.add(lol);
		}
	}
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		lol[] lol = new lol[n];
		for(int x=0;x<n;x++) {
			lol[x] = new lol();
		}
		for(int x=0;x<n;x++) {
			lol[in.nextInt()-1].conn(lol[in.nextInt()-1]);
		}
		LinkedList<lol> hurr = new LinkedList<lol>(Arrays.asList(lol));
		for(lol l:lol) 
			l.d=(ArrayList<lol>)l.c.clone();
		for (int x = 0; true; x++) {
			ArrayList<lol> ha = new ArrayList<lol>();
			for (lol lo : lol) {
				if (lo.o()) {
					ha.add(lo);
				}
			}
			if (ha.isEmpty())
				break;
			for (lol lo : ha) {
				lo.r();
				hurr.remove(lo);
			}
		}
		for(lol l:hurr) {
			l.dist = 0;
		}
		while(!hurr.isEmpty()) {
			lol f = hurr.poll();
			int d = f.dist+1;
			for(lol g:f.d) {
				if(g.dist==-1) {
					g.dist = d;
					hurr.add(g);
				}
			}
		}
		String sep = "";
		for(lol l:lol) {
			System.out.print(sep+l.dist);
			sep = " ";
		}
		System.out.println();
	}
}