import java.io.*;
import java.util.Scanner;

public class R183qALuckyPermutation {

	static PrintWriter w;
	
	public static void main(String args[]) throws Exception{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		if(n % 2 == 0){
			System.out.println(-1);
			sc.close();
			return;
		}
		
		int a[] = new int[n];
		int b[] = new int[n];
		int c[] = new int[n];
		
		for(int i=0;i<n;i++){
			a[i] = b[i] = i;
			c[i] = (2*i) % n;
		}
		
		w = new PrintWriter(System.out);
		
		print(a,n);
		print(b,n);
		print(c,n);
		
		w.close();
		sc.close();
	}
	
	public static void print(int[] a,int n){
		for(int i=0;i<n;i++)
			w.print(a[i] + " ");
		w.println();
	}
}