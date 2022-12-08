import java.util.Scanner;

public class YoungPhysicist {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int xs = 0;
		int ys = 0;
		int zs = 0;
		for (int i = 0; i < n; i++) {
			xs+=s.nextInt();
			ys+=s.nextInt();
			zs+=s.nextInt();
		}
		if (xs==0&&ys==0&&zs==0) {
			System.out.println("YES");
		}
		else System.out.println("NO");

	}

}