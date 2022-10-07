import java.util.Scanner;


public class A058 {
	public static void main(String[] args) throws Exception {
		String line = new Scanner(System.in).next();
		String hello = "hello";
		int x,y=0;
		for(x=0;x<line.length();x++) {
			
			if(line.charAt(x)==hello.charAt(y)) y++;
			if(y==5) break;
		}
		System.out.println(y==5?"YES":"NO");
	}
}