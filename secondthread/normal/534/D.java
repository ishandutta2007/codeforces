import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;

public class Handshakes {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		Person[] a=new Person[n];
		for (int i=0; i<n; i++) a[i]=new Person(fs.nextInt(), i+1);
		ArrayDeque<Person>[] atVal=new ArrayDeque[n+1];
		for (int i=0; i<atVal.length; i++) atVal[i]=new ArrayDeque<>();
		for (Person p:a) atVal[p.value].add(p);
		int count=0;
		ArrayList<Person> ans=new ArrayList<>();
		while (true) {
			if (count<0) break;
			if (atVal[count].isEmpty()) {
				count-=3;
				continue;
			}
			ans.add(atVal[count].remove());
			count++;
		}
		if (ans.size()!=n) {
			System.out.println("Impossible");
			return;
		}
		System.out.println("Possible");
		
		for (Person p:ans) {
			out.print(p.id+" ");
		}
		out.println();
		out.close();
	}
	
	static class Person implements Comparable<Person> {
		int value;
		int id;
		public Person(int value, int id) {
			this.value=value;
			this.id=id;
		}
		public int compareTo(Person o) {
			return Integer.compare(value, o.value);
		}
	}

}