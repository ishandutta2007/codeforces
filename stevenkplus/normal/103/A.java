import java.util.Scanner;


public class A103 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long sum = n;
		for(int x = 0;x<n;x++) {
			int k = in.nextInt();
			sum+=(k-1L)*(x+1);
		}
		System.out.println(sum);
	}
}