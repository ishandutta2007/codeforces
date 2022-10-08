import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
/*
1
3 10
6 3
8 2
1 4
 */
public class B {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int T=fs.nextInt();
		while (T-->0) {
			int n=fs.nextInt(); long h=fs.nextInt();
			Attack[] attacks=new Attack[n];
			for (int i=0; i<n; i++)
				attacks[i]=new Attack(fs.nextInt(), fs.nextInt());
			long best=Long.MAX_VALUE;
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					long toLose=h-attacks[i].damage;
					if (toLose<=0)
						best=1;
					else {
						if (attacks[j].damage<=attacks[j].growBack) continue;
						long sub=attacks[j].damage-attacks[j].growBack;
						best=Math.min(best, 1+(toLose+sub-1)/sub);
					}
				}
			}
			System.out.println(best==Long.MAX_VALUE?-1:best);
		}
	}
	
	static class Attack implements Comparable<Attack> {
		long damage, growBack;
		public Attack(int damage, int growBack) {
			this.damage=damage; this.growBack=growBack;
		}
		
		public int compareTo(Attack o) {
			return -Long.compare(damage-growBack, o.damage-o.growBack);
		}
	}

}