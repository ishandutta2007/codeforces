import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MishkaAndGame {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int mishka=0;
		int chris=0;
		for (int i = 0; i < N ;i++){
			int mtemp = s.nextInt();
			int ctemp = s.nextInt();
			if(mtemp>ctemp) mishka++;
			if(ctemp>mtemp) chris++;
		}
		if(mishka>chris)System.out.println("Mishka");
		if(mishka<chris)System.out.println("Chris");
		if(mishka==chris)System.out.println("Friendship is magic!^^");

	}

}