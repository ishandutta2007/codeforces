import java.util.Scanner;


public class A116 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int max = 0;
		int k = 0;
		int n = in.nextInt();
		for(int x=0;x<n;x++) {
			k-=in.nextInt();
			k+=in.nextInt();
			if(k>max) max = k;
		}
		System.out.println(max);
	}
}