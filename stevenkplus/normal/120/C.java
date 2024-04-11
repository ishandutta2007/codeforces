import java.io.File;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;


public class C120 {
	static class jar implements Comparable<jar> {
		int count;
		int eatentimes;
		public jar(int x ) {
			count = x;
			eatentimes = 0;
		}
		public int compareTo(jar o) {
			return o.count-count;
		}
	}
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		PriorityQueue<jar> pq = new PriorityQueue<jar>();
		int piglet = 0;
		int n = in.nextInt();
		int k = in.nextInt();
		for(int x = 0;x<n;x++) {
			pq.add(new jar(in.nextInt()));
		}
		while(!pq.isEmpty()) {
			jar first = pq.poll();
			if(first.eatentimes==3) {
				piglet+=first.count;
				continue;
			}
			if(first.count<k) {
				piglet+=first.count;
				continue;
			}
			first.count-=k;
			first.eatentimes++;
			pq.offer(first);
		}
		out.println(piglet);
		out.close();
	}
}