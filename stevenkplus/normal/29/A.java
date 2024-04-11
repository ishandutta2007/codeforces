import java.util.Scanner;

public class A029 {
	public static void main(String[] args) {
		System.out.println(b() ? "YES" : "NO");
	}

	public static boolean b() {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] p = new int[n],d=new int[n];
		for(int x = 0;x<n;x++) {
			p[x] = in.nextInt();
			d[x] = in.nextInt();
			int l = p[x]+d[x];
			for(int i = 0;i<x;i++ ){
				if(p[i]==l&&d[i]==-d[x]) return true;
			}
		}
		return false;
	}
}