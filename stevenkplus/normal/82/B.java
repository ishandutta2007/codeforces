import java.util.ArrayList;
import java.util.Scanner;

public class B082 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		if(n==2) {
			int k = in.nextInt();
			System.out.println ("1 "+in.nextInt());
			System.out.println((k-1)+""+in.nextLine());
			return;
		}
		int size = 201;
		boolean[][] arr = new boolean[n*(n-1)/2][size];
		int lol = -1;
		for (int x = 0; x < n*(n-1)/2; x++) {
			int k = in.nextInt();
			for (int i = 0; i < k; i++) {
				int kk = in.nextInt();
				if (lol == -1)
					lol = kk;
				arr[x][kk] = true;
			}
		}
		ArrayList<boolean[]> heh = new ArrayList<boolean[]>();
		for (boolean[] b : arr) {
			if (b[lol])
				heh.add(b);
		}
		boolean[] f = arr[0],g = heh.get(1);
		boolean[] arrr = new boolean[size];
		ArrayList<Integer> hurr = new ArrayList<Integer>();
		for (int x = 0; x < size; x++) {
			arrr[x] = f[x]&&g[x];
			if(arrr[x])hurr.add(x);
		}
		System.out.print(hurr.size()+" ");
		for(int x:hurr) System.out.print(x+" ");
		System.out.println();
		for(boolean[] b:heh) {
			hurr.clear();
			for(int x = 0;x<size;x++) {
				if(b[x]&&!arrr[x]) hurr.add(x);
			}
			System.out.print(hurr.size()+" ");
			for(int x:hurr) System.out.print(x+" ");
			System.out.println();
		}
	}
}