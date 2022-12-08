import java.util.Arrays;
import java.util.Scanner;

public class HelpfulMaths {

	public static void main(String[] args) {
		// TODO Auto-generated method stub]
		Scanner s = new Scanner(System.in);
		String line = s.nextLine();
		int[] numbers = new int[line.length()/2+1];
		int counter = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line.charAt(i)!='+') {
			
				numbers[counter] = Character.getNumericValue(line.charAt(i));
				counter++;
			}
		}
	
		Arrays.sort(numbers);
		for (int i = 0; i < numbers.length; i++) {
			System.out.print(numbers[i]);
			if(i!=numbers.length-1) {
				System.out.print("+");
			}
		}

	}

}