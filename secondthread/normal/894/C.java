import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++)
			a[i]=s.nextInt();
		
		boolean[] contains=new boolean[1000001];
		int min=Integer.MAX_VALUE;
		for (int i:a) {
			contains[i]=true;
			min=Math.min(min, i);
		}
		boolean works=true;
		for (int i:a)
			if (i%min!=0)
				works=false;
		
		if (works) {
			System.out.println(2*n);
			for (int i:a)
				System.out.print(i+" "+min+" ");
			return;
		}

		for (int i=0; i<n; i++) {
			int gcd=a[i];
			for (int j=i+1; j<n; j++) {
				gcd=gcd(gcd, a[j]);
				if (!contains[gcd]) {
					System.out.println(-1);
					return;
				}
			}
		}
		System.out.println(n);
		for (int i:a)
			System.out.print(i+" ");
	}
	
	private static int gcd(int a, int b) {
		if (b==0)
			return a;
		return gcd(b, a%b);
	}

}