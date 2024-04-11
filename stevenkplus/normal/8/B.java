import java.awt.Point;
import java.util.Hashtable;
import java.util.Scanner;

public class B008 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Hashtable<Point, Integer> ht = new Hashtable<Point, Integer>();
		String line = in.nextLine();
		int i = 1;
		int[] x = new int[line.length() + 1], y = new int[line.length() + 1];
		int cx = 0, cy = 0;
		for (int j = 0; j < line.length(); j++) {
			switch (line.charAt(j)) {
			case 'L':
				cx--;
				break;
			case 'R':
				cx++;
				break;
			case 'U':
				cy++;
				break;
			case 'D':
				cy--;
			}
			for (int k = 0; k < j - 1; k++) {
				if (touches(cx, cy, x[k], y[k])) {
					System.out.println("BUG");
					return;
				}
			}
			x[i] = cx;
			y[i++] = cy;
		}
		System.out.println("OK");
	}

	static boolean touches(int x, int y, int x1, int y1) {
		int[] mx = { 0, 0, 1, -1 }, my = { 1, -1, 0, 0 };
		for (int i = 0; i < 4; i++) {
			if (x + mx[i] == x1 && y + my[i] == y1)
				return true;
		}
		return false;
	}
}