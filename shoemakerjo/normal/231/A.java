import java.util.Scanner;

public class Team {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int total2=0;
		for(int i = 0; i < n; i++) {
			int total = s.nextInt()+s.nextInt()+s.nextInt();
			if(total>=2) total2++;
		}
		System.out.println(total2);

	}

}