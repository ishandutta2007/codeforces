import java.util.ArrayList;
import java.util.Scanner;

public class B124 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		char[][] strs = new char[n][k];
		for (int x = 0; x < n; x++) {
			strs[x] = in.next().toCharArray();
		}
		int[] indices = new int[k];
		int mind = Integer.MAX_VALUE;
		while(indices[0] < k) {
			int[] map = new int[k];
			ArrayList<Integer> pq = new ArrayList<Integer>();
			for(int x = 0;x<k;x++) {
				pq.add(x);
			}
			for(int x = 0;x<k;x++) {
				map[x] = pq.remove(indices[x]);
			}
			int max = 0;
			int min = Integer.MAX_VALUE;
			for(int x = 0;x<n;x++) {
				char[] c = new char[k];
				for(int y=0;y<k;y++) {
					c[y] = strs[x][map[y]];
				}
				int i = Integer.parseInt(new String(c));
				if(i>max) max = i;
				if(i<min) min = i;
			}
			int diff = max-min;
			if(diff<mind) mind = diff;
			int x = k-1;
			indices[x]++;
			while(x>0&&indices[x]>=(k-x)) {
				indices[x] = 0;
				x--;
				indices[x]++;
			}
		}
		System.out.println(mind);
	}
}