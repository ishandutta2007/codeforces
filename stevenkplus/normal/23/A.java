import java.util.Scanner;

public class A023 {
	public static void main(String[] args) {
		System.out.println(f());
	}

	static int f() {
		Scanner in = new Scanner(System.in);
		String line = in.next();
		for (int length = line.length(); length > 0; length--) {
			for (int start = 0; start + length <= line.length(); start++) {
				if(line.indexOf(line.substring(start,start+length),start+1)>=0) {
					return length;
				}
			}
		}
		return 0;
	}
}