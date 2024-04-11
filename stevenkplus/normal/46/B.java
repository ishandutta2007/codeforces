import java.util.Arrays;
import java.util.Scanner;

public class B046 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] siz = new int[5];
		for (int x = 0; x < 5; x++) {
			siz[x] = in.nextInt();
		}
		String[] str = "S,M,L,XL,XXL".split(",");
		int[] mov = {0,1,-1,2,-2,3,-3,4,-4};
		int n = in.nextInt();
		for(int x = 0;x<n;x++) {
			int s = indexOf(str,in.next());
			for(int i = 0;i<mov.length;i++) {
				int si = s+mov[i];
				if(si<0||si>4) continue;
				if(siz[si]>0) {
					siz[si]--;
					System.out.println(str[si]);
					break;
				}
			}
		}
	}
	static int indexOf(String[] s,String k) {
		for(int x = 0;x<s.length;x++) {
			if(s[x].equals(k)) return x;
		}
		return -1;
	}
}