import java.util.Scanner;

public class ArpaExam {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		//8 4 2 6
		int mod = n%4;
		if (n==0) System.out.println(1);
		else {
			switch(mod) {
			case 0: System.out.println(6); break;
			case 1: System.out.println(8); break;
			case 2: System.out.println(4); break;
			case 3: System.out.println(2); break;
		}
		}
		

	}

}