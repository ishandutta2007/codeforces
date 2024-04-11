import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
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
public class E2 {

	static PriorityQueue<Book> pqA, pqB;
	static long total=0;
	static int aHave=0, bHave=0;
	static int booksUsed=0;
	
	static PriorityQueue<Book> cheapestA, cheapestB, cheapestBoth, cheapestNone, worstBoth, worstA, worstB, worstNone;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), readTotal=fs.nextInt(), readEach=fs.nextInt();
		Book[] books=new Book[n], unsorted=new Book[n];
		for (int i=0; i<n; i++) unsorted[i]=books[i]=new Book(fs.nextInt(), fs.nextInt(), fs.nextInt());
		Arrays.sort(books);
		pqA=new PriorityQueue<>((a, b)-> {
			return b.compareTo(a);
		});
		pqB=new PriorityQueue<>((a, b)-> {
			return b.compareTo(a);
		});
		
		cheapestA=new PriorityQueue<>();//untaken
		cheapestB=new PriorityQueue<>();
		cheapestBoth=new PriorityQueue<>();
		cheapestNone=new PriorityQueue<>();
		
		worstBoth=new PriorityQueue<>((a, b)-> {//taken
			return b.compareTo(a);
		});
		worstA=new PriorityQueue<>((a, b)-> {//taken
			return b.compareTo(a);
		});
		worstB=new PriorityQueue<>((a, b)-> {//taken
			return b.compareTo(a);
		});
		worstNone=new PriorityQueue<>((a, b)-> {//taken
			return b.compareTo(a);
		});
		
		
		for (Book b:books) {
			if (b.a && b.b) cheapestBoth.add(b);
			else if (b.a) cheapestA.add(b);
			else if (b.b) cheapestB.add(b);
			else cheapestNone.add(b);
			
			if (!b.a && !b.b) continue;
			if (b.a && b.b) {
				//both
				if (aHave<readEach || bHave<readEach) {
					add(b);
					if (aHave>readEach && !pqA.isEmpty()) {
						Book toRemove=pqA.remove();
						remove(toRemove);
					}
					if (bHave>readEach && !pqB.isEmpty()) {
						Book toRemove=pqB.remove();
						remove(toRemove);
					}
				}
				else {
					if (!pqA.isEmpty() && !pqB.isEmpty()) {
						int bonus=pqA.peek().time+pqB.peek().time;
						if (bonus>b.time) {
							Book removed1=pqA.remove(), removed2=pqB.remove();
							add(b);
							remove(removed1);
							remove(removed2);
						}
					}
				}
			}
			else if (b.a) {
				if (aHave<readEach) {
					add(b);
				}
			}
			else {
				if (bHave<readEach) {
					add(b);
				}
			}
		}
		
		//We might have used too many books
		while (booksUsed>readTotal) {
			//try add 11 back in
			Book toAdd=getCheapestBothUnused();
			Book worstA=getWorstAUsed();
			Book worstB=getWorstBUsed();
			if (toAdd==null || worstA==null || worstB==null) {
				out.println(-1);
				out.close();
				return;
			}
			remove(worstA);
			remove(worstB);
			add(toAdd);
		}
		
		//now we might not have enough books
		while (booksUsed<readTotal) {
			Book cheapestA=getCheapestAUnused();
			Book cheapestB=getCheapestBUnused();
			Book cheapestBoth=getCheapestBothUnused();
			Book cheapestNone=getCheapestNoneUnused();
			
			Book bestToAdd=minCost(cheapestA, cheapestB, cheapestBoth, cheapestNone);
			Book worstBoth=getWorstBothUsed();
			if (worstBoth==null || cheapestA==null || cheapestB==null) {
				//forced to do bestToAdd
				if (bestToAdd==null) {
					out.println(-1);
					out.close();
					return;
				}
				add(bestToAdd);
			}
			else {
				if (bestToAdd==null) {
					//shouldn't even happen
					throw null;
				}
				long costBestToAdd=bestToAdd.time;
				long costSwap=cheapestA.time+cheapestB.time-worstBoth.time;
				if (costBestToAdd<costSwap) {
					add(bestToAdd);
				}
				else {
					remove(worstBoth);
					add(cheapestA);
					add(cheapestB);
				}
			}
		}
		
		
		if (aHave<readEach || bHave<readEach) {
			out.println(-1);
			out.close();
			return;
		}
		else {
			out.println(total);
		}
		
		for (int i=0; i<n; i++) {
			if (unsorted[i].used)
				out.print(i+1+" ");
		}
		out.println();
		out.close();
	}
	
	//TODO: make sure all PQs get updated!!
	static void add(Book b) {
		b.used=true;
		total+=b.time;
		booksUsed++;
		if (b.a && b.b) {
			aHave++;
			bHave++;
			worstBoth.add(b);
		}
		else if(b.a) {
			pqA.add(b);
			worstA.add(b);
			aHave++;
		}
		else if (b.b) {
			pqB.add(b);
			worstB.add(b);
			bHave++;
		}
		else {
			worstNone.add(b);
		}
	}
	
	static void remove(Book b) {
		b.used=false;
		total-=b.time;
		booksUsed--;
		
		if (b.a && b.b) {
			aHave--;
			bHave--;
			cheapestBoth.add(b);
		}
		else if(b.a) {
			aHave--;
			cheapestA.add(b);
		}
		else if (b.b) {
			bHave--;
			cheapestB.add(b);
		}
		else {
			cheapestNone.add(b);
		}
	}
	
	static Book minCost(Book a, Book b, Book c, Book d) {
		Book res=better(a, b);
		res=better(res, c);
		res=better(res, d);
		return res;
	}
	
	static Book better(Book a, Book b) {
		if (a==null) return b;
		if (b==null) return a;
		return a.time<=b.time?a:b;
	}
	
	static Book getCheapestBothUnused() {
		return getCheapestUnused(cheapestBoth);
	}
	
	static Book getCheapestNoneUnused() {
		return getCheapestUnused(cheapestNone);
	}
	
	static Book getCheapestAUnused() {
		return getCheapestUnused(cheapestA);
	}
	
	static Book getCheapestBUnused() {
		return getCheapestUnused(cheapestB);
	}

	static Book getWorstAUsed() {
		return getWorstUsed(worstA);
	}
	
	
	static Book getWorstBUsed() {
		return getWorstUsed(worstB);
	}

	static Book getWorstBothUsed() {
		return getWorstUsed(worstBoth);
	}
	
	static Book getCheapestUnused(PriorityQueue<Book> pq) {
		while (!pq.isEmpty()) {
			Book next=pq.peek();
			if (next.used) pq.remove();
			else return next;
		}
		return null;
	}
	
	static Book getWorstUsed(PriorityQueue<Book> pq) {
		while (!pq.isEmpty()) {
			Book next=pq.peek();
			if (!next.used) pq.remove();
			else return next;
		}
		return null;
	}
	
	static class Book implements Comparable<Book> {
		int time;
		boolean a, b;
		boolean used;
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