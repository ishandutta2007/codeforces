import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] p = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			p[i] = in.nextInt();
		}
		int m = in.nextInt();
		
		int k = 0;
		StringBuilder s = new StringBuilder("");
		while (true) {
			int fp = n;
			int[] a = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) {
					fp--;
					int j = i;
					while (a[j] != i) {
						a[j] = i;
						j = p[j];
					}
				}
			}
			
			if (fp == m) {
				break;
			}
			k++;
			
			int i = 0, j = 0;
			if (fp > m) {
				for (i = 1; i <= n; i++) {
					if (p[i] != i) {
						break;
					}
				}
				for (j = i + 1; j <= n; j++) {
					if (a[j] == i) {
						break;
					}
				}
			}
			if (fp < m) {
				i = 1;
				for (j = 1; j <= n; j++) {
					if (a[j] != 1) {
						break;
					}
				}
			}
			int tmp = p[i];
			p[i] = p[j];
			p[j] = tmp;
			s.append(i);
			s.append(" ");
			s.append(j);
			s.append(" ");
		}
		
		System.out.println(k);
		System.out.println(s);
	}
}