import java.util.Scanner;


public class A129 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int e=0,o=0;
		for(int x=0;x<n;x++) {
			if(in.nextInt()%2==0) {
				e++;
			}
			else
				o++;
		}
		if(o%2==0) {
			System.out.println(e);
		}
		else
			System.out.println(o);
	}
}