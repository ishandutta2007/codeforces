import java.util.Scanner;

public class A109 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int f = 0,num=0;
		for(f=0;f<7;f++) {
			num = n-f*4;
			if(num%7==0) break;
		}
		if(num<0) {
			System.out.println(-1);
			return;
		}
		int s = num/7;
		StringBuffer ret = new StringBuffer();
		for(int x = 0;x<f;x++) {
			ret.append(4);
		}
		for(int x = 0;x<s;x++) {
			ret.append(7);
		}
		System.out.println(ret);
	}
}