import java.util.Scanner;


public class A124 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(),a=in.nextInt(),b=in.nextInt();
		a = n-a;
		b=b+1;
		if(a<b) b = a;
		System.out.println(b);
	}
}