import java.util.Scanner;

public class Diplomas {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		long totalStudents=s.nextLong();
		long	k=s.nextLong();
		
		long maxWinners=totalStudents/2;
		long diplomas=maxWinners/(k+1);
		long certificates=k*diplomas;
		System.out.println(diplomas+" "+certificates+" "+(totalStudents-diplomas-certificates));

	}

}