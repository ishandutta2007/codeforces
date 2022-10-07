import java.util.Arrays;
import java.util.Scanner;

public class B132 {
	static char[][] ar;

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int m = in.nextInt(), n = in.nextInt() - 1;
		in.nextLine();
		ar = new char[m][];
		int[][][][] vis = new int[50][50][4][2];
		for(int x=0;x<50;x++) {
			for(int y=0;y<50;y++) {
				for(int z=0;z<4;z++) {
					vis[x][y][z][0]=vis[x][y][z][1]=-1;
				}
			}
		}
		for (int x = 0; x < m; x++) {
			ar[x] = in.nextLine().toCharArray();
		}
		char[] col = new char[20000];
		int[] dpx = { 0, 1, 0, -1 };
		int[] dpy = { 1, 0, -1, 0 };
		int x;
		int bpx = 0, bpy = 0;
		int dp = 0;
		int cp = -1;
		int period = 0;
		for (x = 0; x < 20000; x++) {
//			int hash = ((bpx * 50 + bpy) * 4 + dp) * 2 + (cp + 1) / 2;
			if (vis[bpx][bpy][dp][(cp+1)/2] > -1) {
				period = x - vis[bpx][bpy][dp][(cp+1)/2];
				break;
			}
			vis[bpx][bpy][dp][(cp+1)/2] = x;
			int xi = bpx, yi = bpy;
			while (inr(xi, yi) && ar[xi][yi] == ar[bpx][bpy]) {
				xi += dpx[dp];
				yi += dpy[dp];
			}
			xi -= dpx[dp];
			yi -= dpy[dp];
			int dir2 = (4 + dp + cp) % 4;
			while (inr(xi, yi) && ar[xi][yi] == ar[bpx][bpy]) {
				xi += dpx[dir2];
				yi += dpy[dir2];
			}
			xi -= dpx[dir2];
			yi -= dpy[dir2];
			xi += dpx[dp];
			yi += dpy[dp];
			if (!inr(xi, yi) || ar[xi][yi] == '0') {
				col[x] = ar[bpx][bpy];
				if (cp == 1)
					dp = (dp + 1) % 4;
				cp = -cp;
			} else {
				col[x] = ar[xi][yi];
				bpx = xi;
				bpy = yi;
			}
		}

		int ind = n;
		if (ind >= x)
			ind = n - ((n - x) / period + 1) * period;
		System.out.println(col[ind]);
	}

	static boolean inr(int a, int b) {
		return a >= 0 && a < ar.length && b >= 0 && b < ar[a].length;
	}
}