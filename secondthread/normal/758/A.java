import java.util.Scanner;

public class Holiday {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfPeople=s.nextInt();
		int[] people=new int[numberOfPeople];
		int max=-1;
		for (int i=0; i<numberOfPeople; i++) {
			people[i]=s.nextInt();
			max=Math.max(max, people[i]);
		}
		int total=0;
		for (int i:people) {
			total+=max-i;
		}
		System.out.println(total);

	}

}