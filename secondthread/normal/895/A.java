import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++)
			a[i]=s.nextInt();
		int min=Integer.MAX_VALUE;
		
		for (int i=0; i<n; i++) {
			for (int j=i; j<n; j++) {
				int s1=0, s2=0;
				for (int k=0; k<i; k++)
					s1+=a[k];
				for (int k=i; k<=j; k++)
					s2+=a[k];
				for (int k=j+1; k<n; k++)
					s1+=a[k];
				min=Math.min(min, Math.abs(s1-s2));
			}
		}
		System.out.println(min);

	}

}