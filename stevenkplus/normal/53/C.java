import java.util.Scanner;


public class C053 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String sep = "";
		int n = in.nextInt();
		int a = 1;
		int fac = 1;
		for(int diff = n-1;diff>=0;diff--) {
			System.out.print(sep+a);
			sep = " ";
			a+=fac*diff;
			fac*=-1;
		}
		System.out.println();
		
	}
}