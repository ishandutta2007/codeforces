import java.util.Scanner;

public class IlyaBank {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		String line = Integer.toString(n);
		if (line.length() < 1) {
			System.out.println(n);
		}
		else {
			if (line.length() < 2) {
				System.out.println(Math.max(n, 0));
			}
			else {
				String rm = line.substring(0,line.length()-1);
				String r2m = line.substring(0,line.length()-2) + line.charAt(line.length()-1);
				int r = Integer.parseInt(rm);
				int r2 = Integer.parseInt(r2m);
				n= Math.max(n, r);
				n = Math.max(n, r2);
				System.out.println(n);
			}
			
		}

	}

}