import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Parallelogram {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int x1 = s.nextInt();
		int y1 = s.nextInt();
		int x2 = s.nextInt();
		int y2 = s.nextInt();
		int x3 = s.nextInt();
		int y3 = s.nextInt();
		ArrayList<Integer> c1 = new ArrayList<Integer>();
		c1.add(x1);
		c1.add(y1);
		ArrayList<Integer> c2 = new ArrayList<Integer>();
		c2.add(x2);
		c2.add(y2);
		ArrayList<Integer> c3 = new ArrayList<Integer>();
		c3.add(x3);
		c3.add(y3);
		HashSet<ArrayList<Integer>> ans = new HashSet<ArrayList<Integer>>();
		ans.add(c1);
		ans.add(c2);
		ans.add(c3);
		
		int diffx = x1-x2;
		int diffy = y1-y2;
		ArrayList<Integer> new1 = new ArrayList<Integer>();
		int co1 = x3+diffx;
		int co2 = y3+diffy;
		new1.add(co1);
		new1.add(co2);
		ans.add(new1);
		
		ArrayList<Integer> new2 = new ArrayList<Integer>();
		co1 = x3-diffx;
		co2 = y3-diffy;
		new2.add(co1);
		new2.add(co2);
		ans.add(new2);
		
		diffx = x1-x3;
		diffy = y1-y3;
		ArrayList<Integer> new3 = new ArrayList<Integer>();
		co1 = x2+diffx;
		co2 = y2+diffy;
		new3.add(co1);
		new3.add(co2);
		ans.add(new1);
		
		ArrayList<Integer> new4 = new ArrayList<Integer>();
		co1 = x2-diffx;
		co2 = y2-diffy;
		new4.add(co1);
		new4.add(co2);
		ans.add(new4);
		
		diffx = x2-x3;
		diffy = y2-y3;
		ArrayList<Integer> new5 = new ArrayList<Integer>();
		co1 = x1+diffx;
		co2 = y1+diffy;
		new5.add(co1);
		new5.add(co2);
		ans.add(new5);
		
		ArrayList<Integer> new6 = new ArrayList<Integer>();
		co1 = x1-diffx;
		co2 = y1-diffy;
		new6.add(co1);
		new6.add(co2);
		ans.add(new6);
		
		System.out.println(ans.size()-3);
		ArrayList<ArrayList<Integer>> ans_new  = new ArrayList<ArrayList<Integer>>();
		ans_new.addAll(ans);
		for (int i = 0; i < ans.size(); i++) {
			ArrayList<Integer> cur = ans_new.get(i);
			if (cur == c1 || cur==c2 || cur==c3) continue;
			System.out.println(cur.get(0) + " " + cur.get(1));
		}

	}

}