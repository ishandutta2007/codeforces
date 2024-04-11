import java.io.*;
import java.util.*;
public class TShirtHunt {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int p = s.nextInt();
		int x = s.nextInt();
		int y = s.nextInt();
		int added = 0;
		boolean done = false;
		int ox = x;
		while (ox >= y) {
			boolean cur = check(ox, p);
			if (cur) {
				System.out.println(0);
				done = true;
				break;
			
			}
			ox-=50;
		}
		
		while (x < y) {
			x+=50;
			added+=50;
		}
		if (!done) {
			while (true) {
				boolean cur = check(x, p);
				if (cur) {
					System.out.println(Math.round(Math.ceil(added/100.0)));
					break;
				}
				x+=50;
				added+=50;
			}
		}
		
	}
	
	public static boolean check(int score, int p) {
		int i = (score / 50) % 475;
		for (int j = 0; j < 25; j++) {
			i = (i * 96 + 42) % 475;
			if (i+26 == p) return true;
		}
		return false;
	}

}