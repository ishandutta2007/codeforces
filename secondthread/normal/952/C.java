import java.util.Scanner;

public class Ravioli {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++)
			a[i]=s.nextInt();
		for (int i=0; i<n-1; i++)
			if (Math.abs(a[i]-a[i+1])>=2) {
				System.out.println("NO");
				return;
			}
		System.out.println("YES");

	}

}