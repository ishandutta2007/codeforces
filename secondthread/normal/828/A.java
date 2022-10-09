import java.util.Scanner;

public class RestrauntTables {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int oneTables=s.nextInt();
		int twoTables=s.nextInt();
		int halfTables=0;
		int counter=0;
		for (int i=0; i<n; i++) {
			if (s.nextInt()==2) {
				if (twoTables>0) {
					twoTables--;
				}
				else {
					counter+=2;
				}
			}
			else {
				if (oneTables>0) {
					oneTables--;
				}
				else if (twoTables>0) {
					twoTables--;
					halfTables++;
				}
				else if (halfTables>0) {
					halfTables--;
				}
				else {
					counter++;
				}
			}
		}
		System.out.println(counter);

	}

}