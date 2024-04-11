import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProblemB {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(reader.readLine());
		String[] line=reader.readLine().split(" ");
		int[] endingArray=new int[n];
		for (int i=0; i<n; i++) {
			endingArray[i]=Integer.parseInt(line[i]);
		}
		int[] startingArray=new int[n];
		for (int i=0; i<(n+1)/2; i++) {
			if (i%2==0) {
				startingArray[i]=endingArray[n-i-1];
				startingArray[n-i-1]=endingArray[i];
			}
			else {
				startingArray[i]=endingArray[i];
				startingArray[n-i-1]=endingArray[n-i-1];
			}
		}

		for (int i:startingArray) {
			System.out.print(i+" ");
		}
		System.out.println();
	}

}