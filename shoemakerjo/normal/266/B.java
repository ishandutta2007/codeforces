import java.util.Scanner;

public class QueueSchool {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int t = s.nextInt();
		String line = s.next();
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < n-1; j++) {
				if (line.charAt(j)=='B' && line.charAt(j+1)=='G') {
					line = line.substring(0,j)+"GB"+line.substring(j+2);
					j++;
				}
			}
		}
		System.out.println(line);

	}

}