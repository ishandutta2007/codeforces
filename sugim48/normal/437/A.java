import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] a = new int[4];
		for (int i = 0; i < 4; i++) {
			a[i] = in.next().length() - 2;
		}
		
		char ans = 0, ansNum = 0;
		for (int i = 0; i < 4; i++) {
			int j = (i + 1) % 4;
			int k = (i + 2) % 4;
			int l = (i + 3) % 4;
			if ((a[i] * 2 <= a[j] && a[i] * 2 <= a[k] && a[i] * 2 <= a[l]) ||
				(a[i] >= a[j] * 2 && a[i] >= a[k] * 2 && a[i] >= a[l] * 2)) {
				ans = (char)('A' + i);
				ansNum++;
			}
		}
		
		if (ansNum == 1) {
			System.out.println((char)(ans));
		} else {
			System.out.println('C');
		}
	}
}