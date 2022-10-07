import java.util.Scanner;


public class B122 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		int max = 0;
		char win = '*';
		for(char c:new char[]{'4','7'}) {
			int sum = 0;
			for(int x =0;x<s.length();x++) {
				if(s.charAt(x)==c) sum++;
			}
			if(sum>max) {
				max = sum;
				win = c;
			}
		}
		if(max==0) System.out.println(-1);
		else System.out.println(win);
	}
}