import java.util.Arrays;
import java.util.Scanner;


public class A033 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n =in.nextInt(),m=in.nextInt(),z=in.nextInt();
		int[] ar = new int[m];
		Arrays.fill(ar,Integer.MAX_VALUE);
		for(int x = 0;x<n;x++) {
			int k = in.nextInt()-1,c = in.nextInt();
			if(c<ar[k]) ar[k] = c;
		}
		int sum = 0;
		for(int x:ar) sum+=x;
		if(sum>z) sum = z;
		System.out.println(sum);
	}
}