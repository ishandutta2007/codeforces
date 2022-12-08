import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt(); //number of flowers
		int m = s.nextInt(); //number of subarrays
		int[] moods = new int[n];
		for(int i = 0; i < n; i++) {
			moods[i] = s.nextInt();
		}
		int max = 0;
		for (int i = 0; i < m; i++) {
			int start = s.nextInt();
			int end = s.nextInt();
			int cur = 0;
			for (int j = start; j <= end; j++) {
				cur += moods[j-1];
			}
			if (cur > 0) max += cur;
		}
		System.out.println(max);
		

	}

}