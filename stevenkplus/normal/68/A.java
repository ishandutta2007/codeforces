import java.util.Scanner;


public class A068 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int min =  Integer.MAX_VALUE;
		for(int x =0;x<4;x++) {
			int n =in.nextInt();
			if(n<min) min = n;
		}
		int k = in.nextInt();
		int n = in.nextInt()+1;
		if(n<min) min = n;
		if(min<k) min = k;
		System.out.println(min-k);
	}
}