import java.util.Scanner;


public class A038 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] ar = new int[n];
		for(int x=1;x<n;x++)
			ar[x] = in.nextInt();
		int sum = 0;
		int s = in.nextInt(),e=in.nextInt();
		for(int x=s;x<e;x++) sum+=ar[x];
		System.out.println(sum);
	}
}