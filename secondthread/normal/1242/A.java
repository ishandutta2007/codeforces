import java.util.ArrayList;
import java.util.Scanner;
/*
83 299

answer: 77
 */
public class A {
	public static void main(String args[]) {
		Scanner fs=new Scanner(System.in);
		long n=fs.nextLong();
		ArrayList<Long> facts=facts(n);
		if (facts.size()==1) {
			System.out.println(facts.get(0));
		}
		else {
			System.out.println(1);
		}
		
	}
	
	
	static ArrayList<Long> facts(long n) {
		long on=n;
		ArrayList<Long> toReturn=new ArrayList<>();
		for (long i=2; i*i<=on; i++) {
			if (n%i==0) {
				toReturn.add(i);
				while (n%i==0) n/=i;
			}
		}
		if (n!=1) toReturn.add(n);
		return toReturn;
	}
}