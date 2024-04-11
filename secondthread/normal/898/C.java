import java.util.ArrayList;
import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int numberOfFriends=s.nextInt();
		
		for (int i=0; i<numberOfFriends; i++) {
			String name=s.next();
			Friend f=Friend.getFriend(name);
			int n=s.nextInt();
			for (int j=0; j<n; j++) {
				f.addNumber(s.next());
			}
		}
		
		System.out.println(Friend.friends.size());
		for (Friend f:Friend.friends) {
			System.out.print(f.name+" ");
			int n=f.numbers.size();
			System.out.print(n+" ");
			for (String st:f.numbers)
				System.out.print(st+" ");
			System.out.println();
		}
	}

	private static class Friend {
		private static ArrayList<Friend> friends=new ArrayList<>();
		private String name;
		private ArrayList<String> numbers=new ArrayList<>();
		
		private Friend(String name) {
			this.name=name;
		}
		
		private void addNumber(String number) {
			for (int i=0; i<numbers.size(); i++) {
				if (numbers.get(i).endsWith(number)) {
					return;
				}
				if (number.endsWith(numbers.get(i))) {
					numbers.remove(i);
					numbers.add(number);
					return;
				}
			}
			numbers.add(number);
		}
		
		private boolean equals(Friend o) {
			return name.equals(o.name);
		}
		
		private static Friend getFriend(String name) {
			Friend f=new Friend(name);
			for (Friend o:friends)
				if (f.equals(o))
					return o;
			friends.add(f);
			return f;
		}
	}
	
}