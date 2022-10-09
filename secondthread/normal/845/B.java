import java.util.Arrays;
import java.util.Scanner;

public class lucky {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String line=s.next();
		int[] firstHalf=new int[3], secondHalf=new int[3];
		for (int i=0; i<3; i++) {
			firstHalf[i]=Integer.parseInt(line.charAt(i)+"");
		}
		for (int i=0; i<3; i++) {
			secondHalf[i]=Integer.parseInt(line.charAt(3+i)+"");
		}
		
		int firstSum=0, secondSum=0;
		for (int i=0; i<3; i++) {
			firstSum+=firstHalf[i];
			secondSum+=secondHalf[i];
		}
		Arrays.sort(firstHalf);
		Arrays.sort(secondHalf);
		
		if (firstSum>secondSum) {
			int[] temp=secondHalf;
			secondHalf=firstHalf;
			firstHalf=temp;
			
			int t=firstSum;
			firstSum=secondSum;
			secondSum=t;
		}
		
		int max1Change=Math.max(9-firstHalf[0], secondHalf[2]);
		int max2Change=0;
		if (max1Change==secondHalf[2]) {
			max2Change=Math.max(9-firstHalf[0], secondHalf[1])+max1Change;
		}
		if (max1Change==9-firstHalf[0]) {
			max2Change=Math.max(max2Change, max1Change+Math.max(secondHalf[2], 9-firstHalf[1]));
		}
		
		if (firstSum==secondSum) {
			System.out.println(0);
			return;
		}
		if (secondSum-firstSum>max1Change) {
			if (secondSum-firstSum>max2Change) {
				System.out.println(3);
			}
			else {
				System.out.println(2);
			}
		}
		else {
			System.out.println(1);
		}
	}

}