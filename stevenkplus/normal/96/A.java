import java.util.Scanner;
import java.util.StringTokenizer;


public class A096 {
	public static void main(String[] args) throws Exception {
		String li = new Scanner(System.in).next();
		StringTokenizer a = new StringTokenizer(li,"0");
		boolean b=  false;
		while(a.hasMoreTokens()) {
			if(a.nextToken().length()>=7) b = true;
		}
		a = new StringTokenizer(li,"1");
		while(a.hasMoreTokens()) {
			if(a.nextToken().length()>=7) b = true;
		}
		System.out.println(b?"YES":"NO");
	}
}