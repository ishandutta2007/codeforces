import java.util.Scanner;

public class B056 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int state = 0;
		int p = -1;
		int a = 0,b=0;
		for (int x = 1; x <= n; x++) {
			int k = in.nextInt();
			if(state==0) {
				if(k!=x) {
					a = k;
					b= x;
					state = 1;
				}
			}
			else if(state==1) {
				if(a-x+b==k) {
					if(a==x) {
						state++;
					}
				}
				else {
					System.out.println("0 0");
					return;
				}
			}
			else {
				if(k!=x) {
					System.out.println("0 0");
					return;
				}
			}
		}
		System.out.println(b+" "+a);
	}
}