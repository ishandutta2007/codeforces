import java.util.Scanner;


public class A069 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int x,y,z;
		x=y=z=0;
		for(int i=0;i<n;i++) {
			x+=in.nextInt();
			y+=in.nextInt();
			z+=in.nextInt();
		}
		System.out.println(x==y&&y==z&&x==0?"YES":"NO");
	}
}