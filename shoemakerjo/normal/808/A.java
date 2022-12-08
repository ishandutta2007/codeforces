import java.io.*;
import java.util.*;
public class LuckyYear {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		long lg = Math.round(Math.floor(Math.log10(n)));
		long cur = Math.round(Math.pow(10, lg));
		while (cur <= n) cur+=Math.round(Math.pow(10, lg));
		System.out.println(cur-n);
	}

}