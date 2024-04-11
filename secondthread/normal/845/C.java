import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class twoTVs {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(reader.readLine());
		Show[] shows=new Show[n];
		for (int i=0; i<n; i++) {
			String[] line=reader.readLine().split(" ");
			shows[i]=new Show(Integer.parseInt(line[0]), Integer.parseInt(line[1]));
		}
		
		Arrays.sort(shows);
		int nextTime1=-1, nextTime2=-1;
		for (int i=0; i<shows.length; i++) {
			if (shows[i].startTime>nextTime1) {
				nextTime1=shows[i].endTime;
			}
			else if (shows[i].startTime>nextTime2) {
				nextTime2=shows[i].endTime;
			}
			else {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}

}

class Show implements Comparable<Show> {
	int startTime, endTime;
	public Show(int startTime, int endTime) {
		this.startTime=startTime;
		this.endTime=endTime;
	}

	public int compareTo(Show o) {
		return startTime-o.startTime;
	}
	
	
}