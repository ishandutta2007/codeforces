import java.util.Scanner;


public class A005 {
	public static void main(String[] johnny) throws Exception {
		Scanner in = new Scanner(System.in);
		int count = 0,sum=0;
		while(in.hasNextLine()) {
			String next = in.nextLine();
			if(next.equals("quit")) break;
			switch(next.charAt(0)) {
			case '+': count++;break;
			case '-':count--;break;
				default:sum+=count*(next.length()-next.indexOf(":")-1);
			}
		}
		System.out.println(sum);
	}
}