import java.util.Scanner;

public class TimePalendrome {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String line=s.nextLine();
		int counter=0;
		while (!isPal(line)) {
			counter++;
			line=getNext(line);
		}
		System.out.println(counter);
	}
	
	private static boolean isPal(String st) {
		if (st.length()<2) {
			return true;
		}
		return st.charAt(0)==st.charAt(st.length()-1)&&isPal(st.substring(1, st.length()-1));
	}
	
	private static String getNext(String previous) {
		int hours=Integer.parseInt(previous.split(":")[0]);
		int minutes=Integer.parseInt(previous.split(":")[1]);
		if (++minutes>=60) {
			minutes=0;
			if (++hours>=24) {
				hours=0;
			}
		}
		String temp=(hours<10?"0":"")+hours+":"+(minutes<10?"0":"")+minutes;
		//System.out.println(temp);
		return temp;
	}

}