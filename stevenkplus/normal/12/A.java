import java.util.Scanner;


public class A012 {
	public static void main(String[] args) {
		System.out.println(b()?"YES":"NO");
	}
	public static boolean b() {
		Scanner in = new Scanner(System.in);
		char[][] ar = new char[3][];
		for(int x = 0;x<3;x++) {
			ar[x] = in.nextLine().toCharArray();
		}
		for(int x = 0;x<3;x++) {
			for(int y = 0;y<3;y++) {
				if(ar[x][y]=='X'^ar[2-x][2-y]=='X') return false;
			}
		}
		return true;
	}
}