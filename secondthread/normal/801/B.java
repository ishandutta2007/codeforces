import java.util.Scanner;

public class Keys {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String x=s.nextLine();
		String z=s.nextLine();
		
		for (int i=0; i<x.length(); i++) {
			if (x.charAt(i)<z.charAt(i)) {
				System.out.println(-1);
				return;
			}
		}
		System.out.println(z);
	}

}