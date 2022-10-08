import java.util.Arrays;
import java.util.Scanner;

public class B {

	static class Pair implements Comparable<Pair> {
		int index, dur;
		public Pair(int index, int dur) {
			this.index=index+1;
			this.dur=dur;
		}
		
		public int compareTo(Pair o) {
			return Integer.compare(o.dur, dur);
		}
	}
	
	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt();
		long total=0;
		
		Pair[] pairs=new Pair[n];
		for (int i=0; i<n; i++) pairs[i]=new Pair(i, fs.nextInt());
		Arrays.sort(pairs);
		for (int i=0; i<n; i++)
			total+=pairs[i].dur*i+1;
		System.out.println(total);
		for (Pair p:pairs)
			System.out.print(p.index+" ");
		System.out.println();
	}

}