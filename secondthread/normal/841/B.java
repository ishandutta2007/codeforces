import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Sums {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader s=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(s.readLine());
		String[] line=s.readLine().split(" ");
		int oddNumbers=0;
		
		for (int i=0; i<n; i++) {
			int a=Integer.parseInt(line[i]);
			if (a%2!=0) {
				oddNumbers++;
			}
		}
		if (oddNumbers!=0) {
			System.out.println("First");
		}
		else {
			System.out.println("Second");
		}

	}

}