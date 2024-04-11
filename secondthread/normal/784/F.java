import java.util.Arrays;
import java.util.Scanner;

public class CrunchingNumbers {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] a=new int[n];
		long time=System.currentTimeMillis()+1000;
		while (System.currentTimeMillis()<time);
		for (int i=0; i<n; i++)
			a[i]=s.nextInt();
		Arrays.sort(a);
		for (int i:a)
			for (int j=0; j<1; j++) System.out.print(i+" ");

	}

}