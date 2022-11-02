import java.io.*;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int ans = 0;
		while(n -- > 0) {
			String s = in.next();
			if(s.charAt(1) == '+')
				ans ++;
			else
				ans --;
		}
		System.out.println(ans);
	}
}