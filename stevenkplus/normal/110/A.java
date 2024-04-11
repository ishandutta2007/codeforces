import java.util.Scanner;

public class A110 {
	public static void main(String[] args) throws Exception {
		String f = new Scanner(System.in).next();
		int k = 0;
		for (char c : f.toCharArray())
			if (c == '4' || c == '7')
				k++;
		boolean b = true;
		for (char c : ("" + k).toCharArray())
			if (!(c == '4' || c == '7')) {
				b = false;
				break;
			}
		System.out.println(b ? "YES" : "NO");
	}
}