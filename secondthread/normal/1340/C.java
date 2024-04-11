import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
2 3
0 2 1
1 1
 */
public class C2 {
	
	static int oo=(int)1e8;
	
	static int[][] distanceTo;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		fs.nextInt();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		sort(a);
		int greenTime=fs.nextInt(), redTime=fs.nextInt();

		distanceTo=new int[n][greenTime];
		bfs(greenTime, a);
		long min=Long.MAX_VALUE;
		
		for (int endAt=0; endAt<n; endAt++) {
//			System.out.println(endAt+" "+distanceTo[endAt][0]);
			if (distanceTo[endAt][0]>=oo)
				continue;
			long finishDist=a[n-1]-a[endAt];
			if (finishDist>greenTime)
				continue;
			long fullCycles=distanceTo[endAt][0];
			min=Math.min(min, fullCycles*(greenTime+redTime) + finishDist);
		}
		if (min==Long.MAX_VALUE) {
			System.out.println(-1);
		}
		else {
			System.out.println(min);
		}
	}
	
	static void bfs(int greenTime, int[] positions) {
		int n=distanceTo.length;
		
		for (int[] a:distanceTo)
			Arrays.fill(a, oo);
		ArrayDeque<Integer> bfsIndecies=new ArrayDeque<>();
		ArrayDeque<Integer> bfsTimes=new ArrayDeque<>();
		distanceTo[0][0]=0;
		bfsIndecies.add(0);
		bfsTimes.add(0);
		while (!bfsIndecies.isEmpty()) {
			int atIndex=bfsIndecies.removeFirst();
			int atTime=bfsTimes.removeFirst();
			if (atIndex<n-1) {
				int distToNext=positions[atIndex+1]-positions[atIndex];
				int nextTimeFull=atTime+distToNext;
				if (nextTimeFull<=greenTime) {
					//otherwise we can't reach it
					if (nextTimeFull<greenTime) {
						int nextIndex=atIndex+1;
						int nextTime=nextTimeFull;
						if (distanceTo[nextIndex][nextTime]>distanceTo[atIndex][atTime]) {
							distanceTo[nextIndex][nextTime]=distanceTo[atIndex][atTime];
							bfsIndecies.addFirst(nextIndex);
							bfsTimes.addFirst(nextTime);
						}
					}
					else {
						int nextIndex=atIndex+1;
						int nextTime=0;
						if (distanceTo[nextIndex][nextTime]>distanceTo[atIndex][atTime]+1) {
							distanceTo[nextIndex][nextTime]=distanceTo[atIndex][atTime]+1;
							bfsIndecies.addLast(nextIndex);
							bfsTimes.addLast(nextTime);
						}
					}
				}
			}
			
			if (atIndex>0) {
				int distToNext=positions[atIndex]-positions[atIndex-1];
				int nextTimeFull=atTime+distToNext;
				if (nextTimeFull<=greenTime) {
					//otherwise we can't reach it
					if (nextTimeFull<greenTime) {
						int nextIndex=atIndex-1;
						int nextTime=nextTimeFull;
						if (distanceTo[nextIndex][nextTime]>distanceTo[atIndex][atTime]) {
							distanceTo[nextIndex][nextTime]=distanceTo[atIndex][atTime];
							bfsIndecies.addFirst(nextIndex);
							bfsTimes.addFirst(nextTime);
						}
					}
					else {
						int nextIndex=atIndex-1;
						int nextTime=0;
						if (distanceTo[nextIndex][nextTime]>distanceTo[atIndex][atTime]+1) {
							distanceTo[nextIndex][nextTime]=distanceTo[atIndex][atTime]+1;
							bfsIndecies.addLast(nextIndex);
							bfsTimes.addLast(nextTime);
						}
					}
				}
			}
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
		
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}