import java.util.Scanner;


public class A136 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		int[] ar = new int[n=in.nextInt()];
		for(int x = 0;x<n;x++) {
			ar[in.nextInt()-1] = x;
		}
		String sep = "";
		for(int x = 0;x<n;x++) {
			System.out.print(sep+(ar[x]+1));
			sep = " ";
		}
		System.out.println();
	}
}