import java.util.Scanner;


public class B136 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(),b=in.nextInt();
		StringBuffer aa = new StringBuffer(Integer.toString(a,3));
		StringBuffer bb = new StringBuffer(Integer.toString(b,3));
		while(aa.length()>bb.length()) {
			bb.insert(0,'0');
		}
		while(bb.length()>aa.length()) {
			aa.insert(0,'0');
		}
		StringBuffer c = new StringBuffer();
		for(int x = 0;x<aa.length();x++) {
			c.append((int)(-(aa.charAt(x)-'0')+(bb.charAt(x)-'0')+30)%3);
		}
		System.out.println(Integer.parseInt(c.toString(),3));
	}
}