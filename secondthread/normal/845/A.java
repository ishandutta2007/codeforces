import java.util.Arrays;
import java.util.Scanner;

public class chess {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] a=new int[n*2];
		for (int i=0; i<n*2; i++) {
			a[i]=s.nextInt();
		}
		Arrays.sort(a);
		if (a[n-1]==a[n]) {
			System.out.println("NO");
		}
		else {
			System.out.println("YES");
		}
	}

}