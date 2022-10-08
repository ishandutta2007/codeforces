import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int b=fs.nextInt(), g=fs.nextInt(), t=fs.nextInt();
		int a=0;
		for (int bb=0; bb<=b; bb++) {
			for (int gg=0; gg<=g; gg++) {
				if (bb+gg==t) a++;
			}
		}
		System.out.println(a);
		
	}

}