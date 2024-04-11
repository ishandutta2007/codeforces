import java.util.Scanner;

public class Lucky {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String line=s.nextLine();
		int a=Integer.parseInt(line.charAt(0)+"");
		int b=Integer.parseInt(line);
		a++;
		for (int i=0; i<line.length()-1; i++) {
			a*=10;
		}
		System.out.println(a-b);
	}

}