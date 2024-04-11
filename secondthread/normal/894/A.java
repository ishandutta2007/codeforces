import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner sn=new Scanner(System.in);
		char[] s=sn.next().toCharArray();
		long count=0;
		for (int i=0; i<s.length; i++) {
			if (s[i]!='Q') {
				continue;
			}
			for (int j=i+1; j<s.length; j++) {
				if (s[j]!='A') {
					continue;
				}
				for (int k=j+1; k<s.length; k++) {
					if (s[k]!='Q') {
						continue;
					}
					count++;
				}
			}
		}
		System.out.println(count);

	}

}