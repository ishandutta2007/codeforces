import java.util.Scanner;

public class B060 {
	static boolean[][][] grid;
	static int count;

	static int x,y,z;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		z=in.nextInt();
		x=in.nextInt();
		y=in.nextInt();
		grid = new boolean[x][y][z];
		for(int xi = 0;xi<z;xi++) {
			for(int yi=0;yi<x;yi++) {
				String n=in.next();
				for(int zi=0;zi<y;zi++) {
					if(n.charAt(zi)=='.') 
						grid[yi][zi][xi] = true;
				}
			}
		}
		int a = in.nextInt(),b=in.nextInt();
		visit(a-1,b-1,0);
		System.out.println(count);
	}
	static boolean inr(int a,int b,int c) {
		return a>=0&&b>=0&&c>=0&&a<x&&b<y&&c<z;
	}
	static void visit(int x, int y, int z) {
		if(!grid[x][y][z]) return;
		count++;
		grid[x][y][z] = false;
		int[] xm = { -1, 0, 1, 0, 0, 0 };
		int[] ym = { 0, 1, 0, -1, 0, 0, };
		int[] zm = { 0, 0, 0, 0, 1, -1 };
		for (int i = 0; i < 6; i++) {
			int xi = x + xm[i], yi = y + ym[i], zi = z + zm[i];
			if( inr(xi,yi,zi)) {
				visit(xi,yi,zi);
			}
		}
	}
}