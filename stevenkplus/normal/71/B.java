import java.util.Scanner;


public class B071 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(),k=in.nextInt(),t=in.nextInt();
		int s = n*k*t/100;
		String sep = "";
		for(int i=0;i<n;i++) {
			int next = (s>=k)?k:s;
			System.out.print(sep+next);
			sep = " ";
			s-=next;
			
		}
		System.out.println();
	}
}