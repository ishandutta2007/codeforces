import java.util.Scanner;

public class CountTRatings {

	public static void main(String[] args) {
		//max, index of the max, index of 3796?
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		int maxDex=0;
		int sum=0;
		for (int i=0; i<n; i++) {
//			if (a[i]>a[maxDex])maxDex=i;
			sum+=a[i];
		}
		int max=a[maxDex];
		// 3637 3638
		
		//max is 3638
//		if (max==3638)
//		if (n==1)
			System.out.println(sum);
	}

}