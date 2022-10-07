import java.util.Scanner;


public class A007 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[][] ar = new int[8][8];
		for(int x = 0;x<8;x++) {
			String l = in.nextLine();
			for(int y = 0;y<8;y++) {
				if(l.charAt(y)=='B')
					ar[x][y]=2;
			}
		}
		int count = 0;
		for(int x = 0;x<8;x++) {
			boolean good = true;
			for(int y=0;y<8;y++) {
				if(ar[x][y]==0) good = false;
			}
			if(good) {
				for(int y =0;y<8;y++) {
					ar[x][y]=0;
				}
				count++;
			}
		}
		for(int x = 0;x<8;x++) {
			boolean good = false;
			for(int y = 0;y<8;y++) {
				if(ar[y][x] ==2) good = true;
			}
			if(good)count++;
		}
		System.out.println(count);
	}
}