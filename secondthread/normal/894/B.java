import java.math.BigInteger;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		long aa=s.nextLong(), bb=s.nextLong();
		BigInteger a=new BigInteger(""+aa);
		BigInteger b=new BigInteger(""+bb);
		a=a.subtract(BigInteger.ONE);
		b=b.subtract(BigInteger.ONE);
		BigInteger prod=a.multiply(b);
		BigInteger mod=new BigInteger(1000000007+"");
		BigInteger two=new BigInteger("2");
		int k=s.nextInt();
		if (k==1) {
			BigInteger ans=two.modPow(prod, mod);
			System.out.println(ans.toString());
			//2^(a-1*b-1)
		}
		else {
			if (aa%2==0^bb%2==0) {
				System.out.println(0);
				return;
			}
			BigInteger ans=two.modPow(prod, mod);
			System.out.println(ans.toString());
		}

	}

}