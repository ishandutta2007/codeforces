import java.util.Scanner;

public class Backspace {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			char[] a=fs.next().toCharArray(), b=fs.next().toCharArray();
			int bInd=b.length-1;
			int aInd=a.length-1;
			while (bInd>=0 && aInd>=bInd) {
				if (a[aInd]==b[bInd]) {
					aInd--;
					bInd--;
				}
				else {
					// need to delete here 
					aInd--;
					aInd--;
					if (aInd<bInd) break;
				}
			}
			System.out.println(bInd<0?"YES":"NO");
		}
	}

}