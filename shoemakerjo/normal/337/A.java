import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Puzzles {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int[] puzzles = new int[m];
		for(int i = 0; i < m; i++) {
			puzzles[i]=s.nextInt();
		}
		Arrays.sort(puzzles);
		int min=10000;
		for(int i = n-1; i<m;i++) {
			min=Math.min(min, puzzles[i]-puzzles[i-n+1]);
		}
		System.out.println(min);

	}

}