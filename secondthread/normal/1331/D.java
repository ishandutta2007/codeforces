import java.util.Scanner;

public class D {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		String next=fs.next();
		System.out.println(Integer.parseInt(next.charAt(next.length()-1)+"")%2);
	}

}