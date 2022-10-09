import java.util.Scanner;

public class BinaryProtocal {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		s.nextLine();
		String line=s.nextLine();
		int count=0;
		for (int i=0; i<line.length(); i++) {
			if (line.charAt(i)=='1') {
				count++;
			}
			else {
				System.out.print(count);
				count=0;
			}
		}
		System.out.println(count);

	}

}