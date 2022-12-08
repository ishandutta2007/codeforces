import java.util.Scanner;

public class StonesontheTable {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.nextLine();
		String line = s.nextLine();
		int bad = 1;
		int total = 0;
		while (bad > 0) {
			bad = 0; 
			for(int i = 1; i < line.length(); i++) {
				if(line.charAt(i)==line.charAt(i-1)) {
					line = line.substring(0,i) + line.substring(i+1);
					i--;
					bad++;
					total++;
				}
			}
		}
		System.out.println(total);

	}

}