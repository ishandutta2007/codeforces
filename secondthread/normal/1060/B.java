import java.math.BigInteger;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		char[] line=s.next().toCharArray();
		if (line.length==1) {
			System.out.println(line[0]);
			return;
		}
		long total=0;
		boolean carry=false;
		for (int i=line.length-1; i>=0; i--) {
			int cur=Integer.parseInt(line[i]+"");
			if (carry) {
				cur--;
			}
			if (cur==9||i==0) {
				total+=cur;
				carry=false;
			}
			else {
				total+=10+cur;
				carry=true;
			}
		}
		System.out.println(total);
	}
}