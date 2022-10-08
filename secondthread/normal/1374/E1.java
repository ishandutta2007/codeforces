import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
/*
8 4
7 1 1
2 1 1
4 0 1
8 1 1
1 0 1
1 1 1
1 0 1
3 0 0

 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		Book[] books=new Book[n];
		for (int i=0; i<n; i++) books[i]=new Book(fs.nextInt(), fs.nextInt(), fs.nextInt());
		Arrays.sort(books);
		int aHave=0, bHave=0;
		PriorityQueue<Book> pqA=new PriorityQueue<>((a, b)-> {
			return b.compareTo(a);
		});
		PriorityQueue<Book> pqB=new PriorityQueue<>((a, b)-> {
			return b.compareTo(a);
		});
		long total=0;
		for (Book b:books) {
			if (!b.a && !b.b) continue;
//			System.out.println("Looking at book with cost "+(b.time));
			if (b.a && b.b) {
				//both
				if (aHave<k || bHave<k) {
					total+=b.time;
					aHave++;
					bHave++;
					if (aHave>k && !pqA.isEmpty()) {
						Book toRemove=pqA.remove();
						total-=toRemove.time;
						aHave--;
					}
					if (bHave>k && !pqB.isEmpty()) {
						Book toRemove=pqB.remove();
						total-=toRemove.time;
						bHave--;
					}
				}
				else {
					if (!pqA.isEmpty() && !pqB.isEmpty()) {
						int bonus=pqA.peek().time+pqB.peek().time;
						if (bonus>b.time) {
							pqA.remove();
							pqB.remove();
							total-=bonus;
							total+=b.time;
						}
					}
					else if (!pqA.isEmpty()) {
						int bonus=pqA.peek().time;
						if (bonus>b.time) {
							bHave++;
							pqA.remove();
							total-=bonus;
							total+=b.time;
						}
					}
					else if (!pqB.isEmpty()) {
						int bonus=pqB.peek().time;
						if (bonus>b.time) {
							aHave++;
							pqB.remove();
							total-=bonus;
							total+=b.time;
						}
					}
				}
			}
			else if (b.a) {
				if (aHave<k) {
					pqA.add(b);
					total+=b.time;
					aHave++;
				}
			}
			else {
				if (bHave<k) {
					pqB.add(b);
					total+=b.time;
					bHave++;
				}
			}
//			System.out.println("aHave: "+aHave+" bHave: "+bHave+" total: "+total);
		}
		if (aHave<k || bHave<k) {
			System.out.println("-1");
		}
		else {
			System.out.println(total);
		}
	}

	static class Book implements Comparable<Book> {
		int time;
		boolean a, b;
		public Book(int time, int a, int b) {
			this.time=time;
			this.a=a==1;
			this.b=b==1;
		}
		
		public int compareTo(Book o) {
			return Integer.compare(time, o.time);
		}
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}