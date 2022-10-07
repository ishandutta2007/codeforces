import java.util.Scanner;


public class A078 {
	public static void main(String[] args) throws Exception {
		int[] h = {5,7,5};
		String vowel = "aeiou";
		Scanner in = new Scanner(System.in);
		for(int x = 0;x<3;x++) {
			String line = in.nextLine();
			int s = 0;
			for(char c:line.toCharArray()) {
				if(vowel.indexOf(c)>=0) s++;
			}
			if(s!=h[x]) {
				System.out.println("NO"); return;
			}
		}
		System.out.println("YES");
	}
}