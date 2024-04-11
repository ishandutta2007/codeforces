import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class NextRound {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		int[] scores = new int[n];
		for (int i = 0; i < n; i++) {
			scores[i] = s.nextInt();
		}
		int x = scores[k-1];
		if(x > 0) {
			for (int j = k-1; j < n; j++) {
				if(scores[j]!=x) {
					System.out.println(j);
					break;
				}
				if (j==n-1) System.out.println(n);
			}
		}
		else {
			for (int j = k-1; j >= 0; j--) {
				if (scores[j] > 0) {
					System.out.println(j+1);
					break;
				}
				if(j==0) System.out.println(0);
			}
		}

	}

}