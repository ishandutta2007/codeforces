import java.util.Scanner;

public class Football {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.nextLine();
		char cur = ' ';
		int total= 0;
		boolean dangerous = false;
		for(int i = 0; i < line.length(); i++) {
			if (line.charAt(i)==cur) {
				total++;
				if (total >= 7) dangerous = true;
			}
			else {
				total = 1;
				cur = line.charAt(i);
			}
		}
		if(dangerous) System.out.println("YES");
		else System.out.println("NO");
		
	
	}

}