import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

public class B {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfTasks=s.nextInt();
		int numberOfSubtasks=s.nextInt();
		int amountOfTime=s.nextInt();
		ArrayList<Integer> costOfSubtasks=new ArrayList<Integer>();
		for (int i=0; i<numberOfSubtasks; i++) {
			costOfSubtasks.add(s.nextInt());
		}
		int totalCostOfTask=0;
		for (int i:costOfSubtasks) {
			totalCostOfTask+=i;
		}
		Collections.sort(costOfSubtasks);
		
		int maxPoints=0;
		for (int numberOfTasksCompletelySolved=0; numberOfTasksCompletelySolved<=numberOfTasks; numberOfTasksCompletelySolved++) {
			int timeLeft=amountOfTime-totalCostOfTask*numberOfTasksCompletelySolved;
			int currentPoints=(numberOfSubtasks+1)*numberOfTasksCompletelySolved;
			if (timeLeft<0) {
				break;
			}
			for (int i:costOfSubtasks) {
				int numberICanAfford=Math.min(timeLeft/i, numberOfTasks-numberOfTasksCompletelySolved);
				if (numberICanAfford==0) {
					break;
				}
				timeLeft-=i*numberICanAfford;
				currentPoints+=numberICanAfford;
				//System.out.println(currentPoints);
			}
			maxPoints=Math.max(maxPoints, currentPoints);
			//System.out.println(numberOfTasksCompletelySolved+" "+maxPoints);
		}
		System.out.println(maxPoints);
		
	}

}