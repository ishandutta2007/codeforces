import java.util.Arrays;
import java.util.Scanner;

public class TeaParty {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfCups=s.nextInt();
		int totalTea=s.nextInt();
		Cup[] cups=new Cup[numberOfCups];
		Cup[] sorted=new Cup[numberOfCups];
		for (int i=0; i<numberOfCups; i++) {
			cups[i]=new Cup(s.nextInt());
			sorted[i]=cups[i];
		}
		
		Arrays.sort(sorted);
		for (int i=0; i<cups.length; i++) {
			int change=cups[i].maxTea-cups[i].maxTea/2;
			totalTea-=change;
			cups[i].teaInCup+=change;
		}
		int index=sorted.length-1;
		while (totalTea>0) {
			while (sorted[index].teaInCup==sorted[index].maxTea) {
				index--;
			}
			sorted[index].teaInCup++;
			totalTea--;
		}
		if (totalTea<0) {
			System.out.println(-1);
		}
		else {
			for (Cup c:cups) {
				System.out.print(c.teaInCup+" ");
			}
		}
		
	}

}

class Cup implements Comparable<Cup> {
	public int maxTea;
	public int teaInCup=0;
	
	public Cup(int maxTea) {
		this.maxTea=maxTea;
	}
	
	public int compareTo(Cup o) {
		return maxTea-o.maxTea;
	}
	
}