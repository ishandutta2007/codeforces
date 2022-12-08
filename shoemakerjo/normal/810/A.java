import java.io.*;
import java.util.*;
public class StraightA {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		double n = s.nextInt()+0.0;
		long k = s.nextInt();
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum+=s.nextLong();
		}
		
		int added = 0;
		while (Math.round(sum/n)!=k) {
			added++;
			n++;
			sum+=k;
		}
		System.out.println(added);
//		for (int i = 0; i < 100; i++) {
//			System.out.print(1);
//			if (i < 99) System.out.print(" ");
//		}
	}

}