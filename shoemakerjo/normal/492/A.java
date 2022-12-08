import java.util.Scanner;

public class VanyaCubes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int level = 0;
		while (true) {
			int cur_blocks = level*(level+1)/2;
			if (n-cur_blocks>=0) {
				n-=cur_blocks;
				level++;
			}
			else break;
		}
		System.out.println(level-1);

	}

}