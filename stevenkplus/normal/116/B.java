import java.util.Scanner;


public class B116 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x = in.nextInt(),y=in.nextInt();
		in.nextLine();
		char[][] ar = new char[x][];
		int[] mx = {0,1,0,-1},my={1,0,-1,0};
		for(int i=0;i<x;i++) ar[i] = in.nextLine().toCharArray();
		int s = 0;
		for(int i=0;i<x;i++) {
			for(int j=0;j<y;j++) {
				if(ar[i][j]=='W') {
					boolean found = false;
					for(int p =0;p<4;p++) {
						int xI=i+mx[p],yI=j+my[p];
						if(xI<0||xI>=x||yI<0||yI>=y) continue;
						if(ar[xI][yI]=='P') {
							found = true; break;
						}
					}
					if(found) s++;
				}
			}
		}
		System.out.println(s);
	}
}