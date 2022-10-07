import java.util.Scanner;


public class B070 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		String line = in.nextLine();
		String[] sentences = line.split("\\s*[.?!]\\s*");
		int count = 1;
		int cur = 0;
		for(String a:sentences) {
			if(cur==0) {
				cur =a.length()+1;
				if(cur>n) {
					System.out.println("Impossible");
					return;
				}
			}
			else {
				cur+=a.length()+2;
				if(cur>n) {
					cur = a.length()+1;
					count++;
					if(cur>n) {
						System.out.println("Impossible");
						return;
					}
				}
			}
		}
		System.out.println(count);
	}
}