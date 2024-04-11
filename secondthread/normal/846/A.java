import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		boolean[] successful=new boolean[n];
		for (int i=0; i<n; i++) {
			successful[i]=s.nextInt()==1;
		}

		int total1s=0, total0s=0;
		for (boolean b:successful) {
			if (b) {
				total1s++;
			}
			else {
				total0s++;
			}
		}
		
		int zeros=0;
		int total=total1s;
		for (int i=0; i<n; i++) {
			if (!successful[i]) {
				zeros++;
			}
			else {
				total1s--;
			}
			total=Math.max(total, zeros+total1s);
		}
		System.out.println(total);
	}

}