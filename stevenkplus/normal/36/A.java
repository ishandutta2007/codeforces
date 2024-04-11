import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A036 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		int prev = -1,diff = -1;
		in.next();
		String line = in.next();
		for(int x = 0;x<line.length();x++) {
			if(line.charAt(x)=='1') {
				if(prev==-1) {
					prev = x;
				}
				else if(diff==-1) {
					diff = x-prev;
				}
				else {
					if(diff!=x-prev) {
						out.println("NO");
						out.close();
						return;
					}
				}
				prev = x;
			}
		}
	out.println("YES");
		out.close();
	}
}