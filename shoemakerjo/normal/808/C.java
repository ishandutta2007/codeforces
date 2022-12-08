import java.io.*;
import java.util.*;
public class TeaParty {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int w = s.nextInt();
		
		ArrayList<cup> cs = new ArrayList<cup>();
		for (int i = 0; i < n; i++) {
			int val = s.nextInt();
			cs.add(new cup(i,val));
		}
		
		Collections.sort(cs, new CapC());
		
		for (int i = 0; i < cs.size(); i++) {
			cup cur = cs.get(i);
			int cap = cur.capacity;
			int add =Math.round((cap/2.0f));
			cur.filled+=add;
			w-=add;
		}
		if (w < 0) {
			System.out.println(-1);
		}
		else {
			Collections.reverse(cs);
			for (int i = 0; i < cs.size(); i++) {
				cup cur = cs.get(i);
				int left = cur.capacity-cur.filled;
				if (w==0) break;
				if (left >= w) {
					cur.filled+=w;
					break;
				}
				cur.filled =cur.capacity;
				w-=left;
			}
			Collections.sort(cs, new InC());
			for (int i = 0; i < cs.size(); i++) {
				System.out.print(cs.get(i).filled);
				if (i < cs.size()-1) System.out.print(" ");
			}
			System.out.println();
		}
		

	}
	
	static class CapC implements Comparator<cup> {

		@Override
		public int compare(cup o1, cup o2) {
			// TODO Auto-generated method stub
			return Integer.compare(o1.capacity, o2.capacity);
		}
		
	}
	
	static class InC implements Comparator<cup> {

		@Override
		public int compare(cup o1, cup o2) {
			// TODO Auto-generated method stub
			return Integer.compare(o1.index, o2.index);
		}
		
	}
	
	static class cup {
		public int index;
		public int capacity;
		public int filled = 0;
		
		public cup(int i, int c) {
			this.index = i;
			this.capacity = c;
		}
		
		
	}

}