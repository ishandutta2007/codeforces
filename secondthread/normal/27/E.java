import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class NumberWithNFactors {

	static long[] twoPows=new long[60];
	static long[] threePows=new long[38];
	static long[] fivePows=new long[26];
	static long[] sevenPows=new long[26];
	static long[] elevenPows=new long[26];
	
	//128 = 2^7
	public static void main(String[] args) {
		twoPows[0]=threePows[0]=fivePows[0]=sevenPows[0]=elevenPows[0]=1;
		for (int i=1; i<twoPows.length; i++)
			twoPows[i]=2*twoPows[i-1];
		for (int i=1; i<threePows.length; i++)
			threePows[i]=3*threePows[i-1];
		for (int i=1; i<fivePows.length; i++)
			fivePows[i]=5*fivePows[i-1];
		for (int i=1; i<sevenPows.length; i++)
			sevenPows[i]=7*sevenPows[i-1];
		for (int i=1; i<elevenPows.length; i++)
			elevenPows[i]=11*elevenPows[i-1];
//		System.out.println(primeFactorize(294053760));
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt();
		BigInteger ans=null;
		for (int nTwos=0; nTwos<60; nTwos++) {
			if (n%(nTwos+1)!=0) continue;
			for (int nThrees=0; nThrees<38 && nThrees<=nTwos; nThrees++) {
				if (n/(nTwos+1)%(nThrees+1)!=0) continue;
				for (int nFives=0; nFives<26 && nFives<=nThrees; nFives++) {
					if (n/(nTwos+1)/(nThrees+1)%(nFives+1)!=0) continue;
					for (int nSevens=0; nSevens<10 && nSevens<=nFives; nSevens++) {
						if (n/(nTwos+1)/(nThrees+1)/(nFives+1)%(nSevens+1)!=0) continue;
//						System.out.println(nTwos+" "+nThrees+" "+nFives+" "+nSevens);
						for (int n11s=0; n11s<5 && n11s<=nSevens; n11s++) {
							if (n/(nTwos+1)/(nThrees+1)/(nFives+1)/(nSevens+1)%(n11s+1)!=0) continue;
//							System.out.println(nTwos+" "+nThrees+" "+nFives+" "+nSevens+" "+n11s);
							if (tooBig(nTwos, nThrees, nFives, nSevens, n11s)) break;
							BigInteger curAns=solve(nTwos, nThrees, nFives, nSevens, n11s, n);
//							System.out.println("small enough "+curAns);
							if (ans==null || curAns.compareTo(ans)<0)
								ans=curAns;
						}
					}
				}
			}
		}
		System.out.println(ans);
	}
	
	static boolean tooBig(int nTwos, int nThrees, int nFives, int nSevens, int nElevens) {
		try {
			Math.multiplyExact(twoPows[nTwos], Math.multiplyExact(threePows[nThrees], Math.multiplyExact(sevenPows[nSevens], Math.multiplyExact(fivePows[nFives], elevenPows[nElevens]))));
			return false;
		}
		catch(Exception e) {
			return true;
		}
	}
	
	static BigInteger solve(int nTwos, int nThrees, int nFives, int nSevens, int nElevens, int nFactors) {
		BigInteger ans=BigInteger.valueOf(twoPows[nTwos]*threePows[nThrees]*fivePows[nFives]*sevenPows[nSevens]*elevenPows[nElevens]);
		nFactors/=(nTwos+1)*(nThrees+1)*(nFives+1)*(nSevens+1)*(nElevens+1);
		ArrayList<Integer> primes=new ArrayList<>();
		for (int i=13; i<60; i++) {
			if (isPrime(i)) primes.add(i);
		}
		ArrayList<Integer> factors=primeFactorize(nFactors);
		for (int i=0; i<factors.size(); i++) {
			ans=ans.multiply(BigInteger.valueOf(primes.get(i)).pow(factors.get(factors.size()-1-i)-1));
		}
		return ans;
	}
	
	static boolean isPrime(int n) {
		for (int i=2; i<n; i++) {
			if (n%i==0) return false;
		}
		return true;
	}
	
	static ArrayList<Integer> primeFactorize(int n) {
		ArrayList<Integer> toReturn=new ArrayList<>();
		for (int i=2; i<=n; i++) {
			while (n%i==0) {
				n/=i;
				toReturn.add(i);
			}
		}
		return toReturn;
	}

}