import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
//System.out.println((char)(1+'Z')+" "+(0+'z'));
		String line=new Scanner(System.in).nextLine().toLowerCase();
		System.out.println(line.replaceAll("[aeiouy]", "").replaceAll(".", ".$0"));

	}

}