import java.util.Scanner;

public class GenomeDec {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int Ac = 0;
		int Cc = 0;
		int Gc = 0;
		int Tc = 0;
		s.nextLine();
		String line = s.nextLine();
		for (int i = 0; i < line.length(); i++) {
			if (line.charAt(i)=='A') Ac++;
			if (line.charAt(i)=='C') Cc++;
			if (line.charAt(i)=='G') Gc++;
			if (line.charAt(i)=='T') Tc++;
		}
		if (n%4!=0) {
			System.out.println("===");
		}
		else {
			int targ = n/4;
			if (Ac > targ || Cc > targ || Gc > targ || Tc > targ) {
				System.out.println("===");
			}
			else {
				for (int i = 0; i < line.length(); i++) {
					if (line.charAt(i)=='?') {
						if (Ac < targ) {
							System.out.print("A");
							Ac++;
						}
						else {
							if (Cc < targ) {
								System.out.print("C");
								Cc++;
							}
							else {
								if (Gc < targ) {
									System.out.print("G");
									Gc++;
								}
								else {
									System.out.print("T");
									Tc++;
								}
							}
						}
					}
					else {
						System.out.print(line.charAt(i));
					}
				}
				System.out.println();
			}
			
		}

	}

}