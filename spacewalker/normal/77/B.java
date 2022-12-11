import java.lang.*;
import java.util.*;

public class testprog {
	public static float solve(Scanner sc) {
		long a = sc.nextInt(), b = sc.nextInt();
		if (b == 0) {
			return 1;
		} else if (a == 0) {
			return (float)0.5;
		}
		b *= 4;
		long totalArea = (long)a * (2 * b);
		float coveredArea = (float) a * b;
		if (a >= b) {
			coveredArea += a * b - b * b / 2.0;
		} else {
			coveredArea += a * a / 2.0;
		}
		return coveredArea / totalArea;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // read using nextInt, nextString, etc
		int t = sc.nextInt();
		while (t-- > 0) {
			System.out.printf("%.7f\n", solve(sc));
		}
	}
}