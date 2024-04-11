import java.util.ArrayList;
import java.util.Scanner;


public class B059 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int min = 0;
		int sum = 0;
		for(int x = 0;x<n;x++) {
			int next = in.nextInt();
			if(next%2==1) {
				if(next<min ||min==0) min = next;
			}
			sum+=next;
		}
		if(sum%2==0) {
			sum-=min;
			if(min==0) sum = 0;
		}
		System.out.println(sum);
	}
}