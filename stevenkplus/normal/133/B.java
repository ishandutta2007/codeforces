import java.util.Scanner;

public class B133 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String l = in.nextLine();
		int mod = (int) (1E6 + 3);
		int s = 0;
		int pr = 1;
		int r = 16;
		for (int x = l.length() - 1; x >= 0; x--) {
			int k = val(l.charAt(x));
			s += k * pr;
			s %= mod;
			pr *= r;
			pr %= mod;
		}
		System.out.println(s);
	}

	static int val(char c) {
		return 8 + "><+-.,[]:".indexOf(c);
	}
}