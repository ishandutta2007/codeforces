import java.util.Scanner;

public class Chatroom {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String line = s.next();
		int index = 0;
		boolean good = true;
		if (line.indexOf('h', index) < 0) {
			good = false;
		}
		else {
			index = line.indexOf('h', index)+1;
			if (line.indexOf('e', index) < 0) {
				good = false;
			}
			else {
				index = line.indexOf('e', index)+1;
				if (line.indexOf('l', index) < 0) {
					good = false;
				}
				else {
					index = line.indexOf('l', index)+1;
					if (line.indexOf('l', index) < 0) {
						good = false;
					}
					else {
						index = line.indexOf('l', index)+1;
						if (line.indexOf('o', index) < 0) {
							good = false;
						}
						else {
							index = line.indexOf('o', index)+1;
								
						}
					}
				}
			}
		}
		if (good) {
			System.out.println("YES");
		}
		else System.out.println("NO");
		

	}

}