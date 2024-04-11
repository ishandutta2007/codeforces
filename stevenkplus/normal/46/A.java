import java.util.Scanner;


public class A046 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int cur = 2;
		String sep = "";
		for(int x = 1;x<n;x++) {
			System.out.print(sep+cur);
			sep = " ";
			cur +=x+1;
			if(cur>n) cur-=n;
		}
		System.out.println();
	}
}