import java.util.Scanner;


public class B118 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		int c = 1;
		for(int x = 0;x>=0;x+=c) {
			if(x==k) c = -1;
			int c2=1;
			for(int y=-k;y>=-k;y+=c2) {
				if(y==0)c2 = -1;
				int p = y+x;
				if(p<0){if(c2==1) System.out.print("  ");}
				else {System.out.print(p);
				if(p!=0||c2==1) System.out.print(" ");
				}
				
			}
			System.out.println();
		}
		
	}
}