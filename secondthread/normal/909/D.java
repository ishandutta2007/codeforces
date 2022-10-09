

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D {

	public static void solve(FastScanner fs) {	
		char[] line=fs.next().toCharArray();
		
		//build linkedList
		Node head=new Node();
		head.head=true;
		head.c='*';
		Node tail=new Node();
		tail.tail=true;
		tail.c='*';
		head.next=tail;
		tail.last=head;
		Node current=head;
		for (int i=0; i<line.length; i++) {
			Node next=new Node();
			next.c=line[i];
			current.next=next;
			next.last=current;
			next.next=tail;
			tail.last=next;
			current=next;
		}
//		print(head);
		
		ArrayList<Node> toCheck=new ArrayList<>();
		for (Node n=head.next; n!=tail; n=n.next)
			toCheck.add(n);
		
		int counter=0;
		while (!toCheck.isEmpty()) {
			boolean hit=false;
//			System.out.println("Counter: "+counter);
//			print(head);
			ArrayList<Node> next=new ArrayList<>();
			for (Node n:toCheck)
				if (n.tryToDie())
					hit=true;
			for (Node n:toCheck) {
				if (n.dead) {
//					System.out.println("removing "+n.c);
					ArrayList<Node> toCheckNextTime=n.remove();
					next.addAll(toCheckNextTime);
				}
			}
//			System.out.println("<things in toCheck>");
//			for (Node n:next)
//				System.out.println(n.c);
//			System.out.println("</things in toCheck>");
			toCheck=next;
			if (hit)
				counter++;
		}
		System.out.println(counter);
	}

	private static void print(Node n) {
		for (Node current=n; n!=null; n=n.next) {
			System.out.print(n.c+" ");
		}
		System.out.println();
	}
	
	private static class Node {
		Node next, last;
		boolean head, tail;
		boolean dead=false;
		char c;
		
		
		//cant remove head or tail
		public ArrayList<Node> remove() {
			if (last.dead) {//last will take care of it
				return new ArrayList<>();
			}
			while (next.dead) {
				next=next.next;
			}
			last.next=next;
			next.last=last;
			ArrayList<Node> toReturn=new ArrayList<>();
			toReturn.add(last);
			toReturn.add(next);
			return toReturn;
		}
		
		private boolean tryToDie() {
			if (head||tail)
				return false;
			if (!last.head&&last.c!=c)
				dead=true;
			if (!next.tail&&next.c!=c)
				dead=true;
			return dead;
		}
	}
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
}