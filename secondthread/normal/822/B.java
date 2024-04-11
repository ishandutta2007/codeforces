import java.util.Scanner;

public class Substrings {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		s.nextLine();
		String a=s.nextLine();
		String b=s.nextLine();
		int[] matches=new int[b.length()-a.length()+1];
		int max=-1;
		for (int i=0; i<matches.length; i++) {
			int total=0;
			for (int j=0; j<a.length(); j++) {
				if (a.charAt(j)==b.charAt(i+j)) {
					total++;
				}
			}
			matches[i]=total;
			max=Math.max(max, total);
		}
		System.out.println(a.length()-max);
		
	
		
		for (int i=0; i<matches.length; i++) {
			if (matches[i]!=max) {
				continue;
			}
			for (int j=0; j<a.length(); j++) {
				if (b.charAt(i+j)!=a.charAt(j)) {
					System.out.print((j+1)+" ");
				}
			}
			return;
		}

	}

}