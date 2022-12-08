import java.io.*;
import java.util.*;

public class ExpressTrain {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine());
		StringTokenizer st = new StringTokenizer(bf.readLine());
		int[] p1 = new int[n];
		int[] p2 = new int[n];
		for (int i = 0; i < n; i++) {
			p1[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; i++) {
			p2[i] = Integer.parseInt(st.nextToken());
		}
		
		
		int i1 = -1;
		int i2 = -1;
		int[] ans = new int[n];
		for (int i = 0; i < n; i++) {
			if (p1[i]!=p2[i]) {
				if (i1 == -1) {
					i1 = i;
					i2 = i;
				}
				else i2 = i;
			}
		}
		HashSet<Integer> taken = new HashSet<Integer>();
		for (int i = 0; i < n; i++) {
			if (i != i1 && i != i2) {
				ans[i] = p1[i];
				taken.add(ans[i]);
			}
		}
		if (i1==i2) {
			for (int i = 1; i <= n; i++) {
				if (!taken.contains(i) && p1[i1]!=i && p2[i1]!=i) {
					ans[i1] = i;
				}
			}
		}
		else {
			if (p1[i1]!=p2[i2] && !taken.contains(p1[i1]) && !taken.contains(p2[i2])) {
				ans[i1] = p1[i1];
				ans[i2] = p2[i2];
			}
			else if (p1[i2]!=p2[i1] && !taken.contains(p1[i2]) && !taken.contains(p2[i1])) {
				ans[i1] = p2[i1];
				ans[i2] = p1[i2];
			}
			
		}
		for (int i = 0; i < n; i++) {
			if ( i > 0) System.out.print(" ");
			System.out.print(ans[i]);
		}
		System.out.println();

	}

}