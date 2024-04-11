import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Dragons {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s2 = new Scanner(System.in);
		int s = s2.nextInt();
		int n = s2.nextInt();
		HashMap<Integer,Integer> enemies = new HashMap<Integer,Integer>();
		HashSet<Integer> strength = new HashSet<Integer>();
		for (int i = 0; i < n; i++)  {
			int st = s2.nextInt();
			int bo = s2.nextInt();
			if (enemies.containsKey(st)) {
				enemies.put(st, enemies.get(st)+bo);
			}
			else {
				enemies.put(st, bo);
			}
			strength.add(st);
		}
		ArrayList<Integer> stra = new ArrayList<Integer>();
		stra.addAll(strength);
		Collections.sort(stra);
		boolean pass = true;
		for (int i = 0; i < stra.size(); i++) {
			if (s <= stra.get(i)) {
				pass = false;
				break;
			}
			s += enemies.get(stra.get(i));
		}
		if (pass) System.out.println("YES");
		else System.out.println("NO");

	}

}