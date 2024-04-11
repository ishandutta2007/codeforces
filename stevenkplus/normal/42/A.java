import java.util.Scanner;


public class A042 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		double min = in.nextDouble();
		int[] ar = new int[n];
		double sum = 0;
		for(int x = 0;x<n;x++ ){
			ar[x] = in.nextInt();
			sum+=ar[x];
		}
		for(int x = 0;x<n;x++ ){
			double k = in.nextInt();
			k*=sum/ar[x];
			if(k<min) min = k;
		}
		System.out.println(min);
	}
}