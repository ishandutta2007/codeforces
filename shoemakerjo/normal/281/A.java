import java.util.Scanner;

public class WordCapitalization {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.next();
		String ans = line.substring(0,1).toUpperCase() + line.substring(1);
		System.out.println(ans);

	}

}