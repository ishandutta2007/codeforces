import java.util.ArrayList;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int aTotal=fs.nextInt(), bTotal=fs.nextInt();
		int total=aTotal+bTotal;
		int nDays=0;
		while ((nDays)*(nDays+1l)/2<=total)
			nDays++;
		int day=nDays-1;
		ArrayList<Integer> a=new ArrayList<>(), b=new ArrayList<>();
		while (day>0) {
			if (bTotal>=day) {
				bTotal-=day;
				b.add(day);
			}
			else {
				a.add(day);
			}
			day--;
		}
		System.out.println(a.size());
		for (int i:a)
			System.out.print(i+" ");
		System.out.println();
		System.out.println(b.size());
		for (int i:b)
			System.out.print(i+" ");
	}

}