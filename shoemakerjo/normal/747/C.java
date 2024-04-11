import java.util.ArrayList;
import java.util.Scanner;

public class Servers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int q = s.nextInt();
		int[] free = new int[n+1];
		for (int i = 0; i < q; i++) {
			int t =s.nextInt();
			int k = s.nextInt();
			int d = s.nextInt();
			int sum = 0;
			int taken = 0;
			ArrayList<Integer> serv = new ArrayList<Integer>();
			for (int j = 1; j <= n; j++) {
				if (taken >= k) break;
				if (t >= free[j]) {
					taken++;
					sum+=j;
					serv.add(j);
				}
			}
			if (taken < k) System.out.println(-1);
			else {
				System.out.println(sum);
				for (int j = 0; j < serv.size(); j++) {
					free[serv.get(j)] = t+d;
				}
			
			}
		}
		s.close();

	}

}