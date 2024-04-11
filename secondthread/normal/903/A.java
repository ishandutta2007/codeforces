import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		for (int j=0; j<n; j++) {
			int i=s.nextInt();
			if (works(i))
				System.out.println("YES");
			else 
				System.out.println("NO");
		}

	}
	
	private static boolean works(int i) {
		if (i==3||i==6||i==7||i==9||i==10||i>=12)
			return true;
		return false;
	}

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}
		
		
	}
	
}