import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class drivingTest {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(reader.readLine());
		
		int overtakeCounter=0;
		Stack<Integer> speedLimitStack=new Stack<>();
		int totalSignsMissed=0;
		int currentSpeed=0;
		for (int command=0; command<n; command++) {
			String[] line=reader.readLine().split(" ");
			switch(Integer.parseInt(line[0])) {
				case 1:
					currentSpeed=Integer.parseInt(line[1]);
					while ((!speedLimitStack.isEmpty())&&speedLimitStack.peek()<currentSpeed) {
						speedLimitStack.pop();
						totalSignsMissed++;
					}
					break;
				case 2:
					totalSignsMissed+=overtakeCounter;
					overtakeCounter=0;
					break;
				case 3:
					int requiredSpeed=Integer.parseInt(line[1]);
					if (requiredSpeed<currentSpeed) {
						totalSignsMissed++;
					}
					else {
						speedLimitStack.push(Integer.parseInt(line[1]));
					}
					break;
				case 4:
					overtakeCounter=0;
					break;
				case 5:
					speedLimitStack.clear();
					break;
				case 6:
					overtakeCounter++;
					break;
			}
		}
		System.out.println(totalSignsMissed);

	}

}