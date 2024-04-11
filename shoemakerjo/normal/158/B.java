import java.util.Scanner;

public class Taxi {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int ones=0;
		int twos=0;
		int threes=0;
		int fours=0;
		int total=0;
		for (int i = 0; i < n; i++) {
			int temp = s.nextInt();
			if (temp==4) fours++;
			else if(temp==3) threes++;
			else if (temp==2) twos++;
			else ones++;
		}
		total += fours;
		
		int min31 = (int) Math.min(threes, ones);
		total += min31;
		threes-=min31;
		ones-=min31;
		total+=threes;
		total+=twos/2;
		twos=twos%2;
		
		if (twos > 0) {
			total++;
			ones-=2;
			if (ones > 0) {
				total += ones/4;
				ones=ones%4;
				if (ones >0) total++;
			}
		}
		else {
			total += ones/4;
			ones = ones % 4;
			if (ones > 0) total++;
		}
		System.out.println(total);

	}

}