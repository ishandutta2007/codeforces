import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] array=new int[n];
		for (int i=0; i<n; i++) {
			array[i]=s.nextInt();
		}
		if (n%2==0) {
			System.out.println("No");
		}
		else if (array[0]%2==0||array[n-1]%2==0) {
			System.out.println("NO");
		}
		else {
			System.out.println("Yes");
		}
	}

}