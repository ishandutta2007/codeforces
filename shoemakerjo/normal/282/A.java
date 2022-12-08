import java.util.Scanner;

public class BitPlusPlus {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n  =s.nextInt();
		s.nextLine();
		int total = 0;
		for(int i = 0; i < n; i++) {
			String line = s.nextLine();
			if(line.contains("-")) total--;
			else total++;
		}
		System.out.println(total);

	}

}