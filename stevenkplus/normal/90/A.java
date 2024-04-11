import java.util.Scanner;


public class A090 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int r = in.nextInt(),g=in.nextInt(),b=in.nextInt();
		r++;g++;b++;
		r/=2;g/=2;b/=2;
		int time = 0;
		if(b>=g&&b>=r) {
			time = b*3-1;
		}
		else if (g>=r) {
			time = g*3-2;
		}
		else time = r*3-3;
		System.out.println(time+30);
		
	}
}