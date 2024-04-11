import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int next=s.nextInt();
		int last=Integer.parseInt(""+((""+next).charAt((""+next).length()-1)));
		if (last<5)
			next-=last;
		else {
			next=next-last+10;
		}
		System.out.println(next);
	}

}