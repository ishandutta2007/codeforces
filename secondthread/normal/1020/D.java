


import java.io.IOException;
import java.util.Scanner;

public class A {
	
	static int n;
	static Scanner fs;

	public static void solve(Scanner fs) {
		A.fs=fs;
		n=fs.nextInt();
		if (n/2%2!=0) {
			System.out.println("! -1");
			System.out.flush();
			return;
		}
		int zeroRes=guess(0);
		if (zeroRes==0) {
			answer(0);
			return;
		}
		boolean normallyPositive=zeroRes>0;
		int l=0, r=n/2-1;
		while (true) {
			int mid=(l+r)/2;
			int res=guess(mid);
			if (res==0) {
				answer(mid);
				return;
			}
			if ((res>0)==normallyPositive) {
				l=mid+1;
			}
			else {
				r=mid-1;
			}
		}
	}

	private static int guess(int i) {
		int d=n/2;
		i++;
		System.out.println("? "+i);
		System.out.flush();
		System.out.println("? "+(i+d));
		System.out.flush();
		
		int first=fs.nextInt();
		int second=fs.nextInt();
		return second-first;
	}
	
	private static void answer(int i) {
		i++;
		System.out.println("! "+i);
		System.out.flush();
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scanner = new Scanner(System.in);
		solve(scanner);
	}
	
}