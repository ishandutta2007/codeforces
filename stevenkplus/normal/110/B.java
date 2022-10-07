import java.util.Scanner;


public class B110 {
	public static void main(String[] args) {
		char[] ar = "abcd".toCharArray();
		Scanner in = new Scanner(System.in);
		StringBuffer b =new StringBuffer();
		int n = in.nextInt();
		for(int x =0;x<n;x++) {
			b.append(ar[x%4]);
		}
		System.out.println(b.toString());
	}
}