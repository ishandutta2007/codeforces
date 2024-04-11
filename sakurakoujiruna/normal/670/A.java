import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int ans = n / 7 * 2; n %= 7;
		int min = ans, max = ans;
		if(n == 6) min ++;
		if(n == 1) max ++;
		if(n >= 2) max += 2;
		System.out.print(min);
		System.out.print(' ');
		System.out.println(max);
	}
}