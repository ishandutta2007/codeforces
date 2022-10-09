import java.util.Arrays;
import java.util.Scanner;

public class SellOut {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfDays=s.nextInt();
		int daysToChoose=s.nextInt();
		Day[] days=new Day[numberOfDays];
		
		for (int i=0; i<days.length; i++) {
			days[i]=new Day(s.nextInt(), s.nextInt());
		}
		Arrays.sort(days);
		
		long total=0;
		for (int i=0; i<days.length; i++) {
			int index=days.length-i-1;
			if (i<daysToChoose) {
				total+=Math.min(days[index].itemsForSale, days[index].customers)+days[index].potentialIncrease;
			}
			else {
				total+=Math.min(days[index].itemsForSale, days[index].customers);
			}
			//System.out.println(total);
		}
		System.out.println(total);
	}

}

class Day implements Comparable<Day> {
	int itemsForSale;
	int customers;
	int potentialIncrease;
	
	public Day(int itemsForSale, int customers) {
		this.itemsForSale=itemsForSale;
		this.customers=customers;
		potentialIncrease=Math.min(itemsForSale, customers-itemsForSale);
		if (potentialIncrease<0) {
			potentialIncrease=0;
		}
	}

	public int compareTo(Day o) {

		return potentialIncrease-o.potentialIncrease;
	}
}