import java.util.Scanner;


public class A001 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		long n = in.nextInt(),m=in.nextInt(),s=in.nextInt();
		System.out.println(((n-1)/s+1)*((m-1)/s+1));
		
	}
}