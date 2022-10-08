import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

public class C {

	static class Rect {
		int x1, y1, x2, y2;
		public Rect(int x1, int y1, int x2, int y2) {
			this.x1=x1;
			this.x2=x2;
			this.y1=y1;
			this.y2=y2;
		}
		
		public boolean contains(int x, int y) {
			if (x<x1||x>x2||y<y1||y>y2) return false;
			return true;
		}
	}
	
	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		ArrayList<Integer> xs=new ArrayList<>(), ys=new ArrayList<>();
		int x1=fs.nextInt(), y1=fs.nextInt(), x2=fs.nextInt(), y2=fs.nextInt();
		int x3=fs.nextInt(), y3=fs.nextInt(), x4=fs.nextInt(), y4=fs.nextInt();
		int x5=fs.nextInt(), y5=fs.nextInt(), x6=fs.nextInt(), y6=fs.nextInt();
		xs.add(x1);
		xs.add(x2);
		xs.add(x3);
		xs.add(x4);
		xs.add(x5);
		xs.add(x6);
		ys.add(y1);
		ys.add(y2);
		ys.add(y3);
		ys.add(y4);
		ys.add(y5);
		ys.add(y6);
		HashMap<Integer, Integer> xComp=compress(xs);
		HashMap<Integer, Integer> yComp=compress(ys);
		Rect r1=new Rect(xComp.get(x1), yComp.get(y1), xComp.get(x2), yComp.get(y2));
		Rect r2=new Rect(xComp.get(x3), yComp.get(y3), xComp.get(x4), yComp.get(y4));
		Rect r3=new Rect(xComp.get(x5), yComp.get(y5), xComp.get(x6), yComp.get(y6));
		for (int i=0; i<100; i++) {
			for (int j=0; j<100; j++) {
				if (r1.contains(i, j) && !(r2.contains(i, j)||r3.contains(i, j))) {
					System.out.println("YES");
					return;
				}
			}
		}
		System.out.println("NO");
	}
	
	static HashMap<Integer, Integer> compress(ArrayList<Integer> xs) {
		TreeSet<Integer> set=new TreeSet<>();
		for (int i:xs) set.add(i);
		int ind=0;
		HashMap<Integer, Integer> toReturn=new HashMap<>();
		for (int i:set)
			toReturn.put(i, 2*ind++);
		return toReturn;
	}

}