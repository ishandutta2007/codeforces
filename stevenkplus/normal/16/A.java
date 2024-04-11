import java.util.Scanner;


public class A016 {
	public static void main(String[] args) {
		System.out.println(b()?"YES":"NO");
	}
	static boolean b() {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(),m=in.nextInt();
		char prev = 'X';
		for(int x = 0;x<n;x++) {
			String s=  in.next();
			char first = s.charAt(0);
			if(prev==first) return false;
			prev = first;
			for(int y = 0;y<m;y++) {
				if(first!=s.charAt(y)) {
					return false;
				}
			}
		}
		return true;
	}
}