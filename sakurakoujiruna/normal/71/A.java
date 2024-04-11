import java.io.*;
import java.util.*;

public class Main {
	public static void main(String argc[]) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while(T -- > 0) {
			String s = in.next();
			int n = s.length();
			if(n <= 10)
				System.out.println(s);
			else {
				System.out.print(s.charAt(0));
				System.out.print(n - 2);
				System.out.println(s.charAt(n - 1));
			}
		}
	}
}