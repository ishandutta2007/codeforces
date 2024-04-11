import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
4
0 0 1 0
4
0 0 0 0

4
1 0 0 3
 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		if (n==1) {
			System.out.println(0);
			return;
		}
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		boolean[] used=new boolean[n+1];
		for (int i:a)
			used[i]=true;
		int freeEvens=0, freeOdds=0;
		for (int i=1; i<=n; i++) 
			if (!used[i])
				if (i%2==0)
					freeEvens++;
				else
					freeOdds++;
		ArrayList<Section> sections=new ArrayList<>();
		int firstBulb=-1, lastBulb=-1;
		for (int i=n-1; i>=0; i--) if (a[i]!=0) firstBulb=i;
		for (int i=0; i<n; i++) if (a[i]!=0) lastBulb=i;
//		System.out.println("first/last: "+firstBulb+" "+lastBulb);
		if (firstBulb==-1) {
			System.out.println(1);
			return;
		}
		int curLen=0, diffSections=0;
		for (int i=firstBulb+1; i<=lastBulb; i++) {
			if (a[i]!=0) {
				if (a[i-curLen-1]%2 != a[i]%2) {
					diffSections++;
				}
				else {
					boolean even=a[i]%2==0;
					sections.add(new Section(curLen, even));
				}
				curLen=0;
			}
			else {
				curLen++;
			}
		}
		int ans=solve(sections, freeEvens, freeOdds, a[firstBulb]%2==0, firstBulb, a[lastBulb]%2==0, n-lastBulb-1)+diffSections;
		System.out.println(ans);
	}

	//returns the minimum number of wasted sections
	static int solve(ArrayList<Section> sections, int evens, int odds, boolean firstEven, int firstSize, boolean lastEven, int lastSize) {
		Collections.sort(sections);
		int missed=0;
		for (Section s:sections) {
//			System.out.println("Looking at section..."+s.even+" "+evens+" "+odds);
			if (s.even) {
				if (s.length<=evens) {
					evens-=s.length;
				}
				else {
					missed+=2;
				}
			}
			else {
				if (s.length<=odds) {
					odds-=s.length;
				}
				else {
					missed+=2;
				}
			}
		}
//		System.out.println(missed);
		if (firstEven) {
			if (firstSize<=evens) {
				evens-=firstSize;
			}
			else {
				missed++;
			}
		}
		else {
			if (firstSize<=odds) {
				odds-=firstSize;
			}
			else {
//				System.out.println("Missed first");
				missed++;
			}
		}
//		System.out.println(missed+" "+lastEven);
		if (lastEven) {
			if (lastSize<=evens) {
				evens-=lastSize;
			}
			else  {
				missed++;
			}
		}
		else {
			if (lastSize<=odds) {
				odds-=lastSize;
			}
			else  {
				missed++;
			}
		}
		return missed;
	}
	
	static class Section implements Comparable<Section> {
		int length;
		boolean even;
		public Section(int length, boolean even) {
			this.length=length;
			this.even=even;
		}
		public int compareTo(Section o) {
			return Integer.compare(length, o.length);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
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
	}

}