import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int x=s.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) {
			a[i]=s.nextInt();
		}
		boolean[] cs=new boolean[101];
		for (int i:a) {
			cs[i]=true;
		}
		int count=0;
		for (int i=0; i<x; i++) {
			if (!cs[i]) {
				count++;
			}
		}
		if (cs[x]) {
			count++;
		}
		System.out.println(count);
	}

}