import java.util.Scanner;


public class B078 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt()-3;
		String a = "ROYG";
		String b=  "BIV";
		StringBuffer res = new StringBuffer();
		while(n>3) {
			res.append(a);
			n-=4;
		}
		res.append(a.substring(0,n));
		res.append(b);
		System.out.println(res.toString());
	}
}