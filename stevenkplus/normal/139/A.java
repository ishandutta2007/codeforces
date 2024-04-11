import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;


public class A139 {
	public static void main(String[] args) throws Exception { 
	
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int day = 0;
		int count = 0;
		int[] ar = new int[7];
		for(int x = 0;x<7;x++) {
			ar[x] = in.nextInt();
		}
		
		while(count<n) {
			count+=ar[(day++)%7];
		}
		System.out.println((day-1)%7+1);
	}
}