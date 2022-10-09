import java.util.Scanner;

public class NumberOnBoard {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int total=s.nextInt();
		s.nextLine();
		String line=s.nextLine();
		int[] countingSort=new int[10];
		for (int i=0; i<line.length(); i++) {
			countingSort[line.charAt(i)-'0']++;
		}
		for (int i=0; i<countingSort.length; i++) {
			total-=i*countingSort[i];
		}
		if (total<=0) {
			System.out.println(0);
			return;
		}
		
		int totalNumbersChanged=0;
		for (int i=0; i<10; i++) {
			int numberToChange=total/(9-i)+(total%(9-i)==0?0:1);
			//System.err.println(i+" "+numberToChange);
			if (numberToChange<=countingSort[i]) {
				System.out.println(totalNumbersChanged+numberToChange);
				return;
			}
			totalNumbersChanged+=countingSort[i];
			total-=countingSort[i]*(9-i);
		}
	}

}