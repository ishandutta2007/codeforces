import java.util.Scanner;

public class BookReading {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int totalPages=s.nextInt();
		int pagesFirstDay=s.nextInt();
		int maxPages=s.nextInt();
		int pageAcceleration=s.nextInt();
		int rereadPages=s.nextInt();
		int counter=0;
		while (totalPages>0) {
			if (counter!=0) {
				totalPages+=rereadPages;
			}
			totalPages-=pagesFirstDay;
			pagesFirstDay=Math.min(pagesFirstDay+pageAcceleration, maxPages);
			counter++;
			
		}
		System.out.println(counter);

	}

}