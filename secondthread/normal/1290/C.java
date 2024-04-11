import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
/*

 */
public class C {
	
	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int nLamps=fs.nextInt();
		int nSubsets=fs.nextInt();
		boolean[] xorOne=new boolean[nLamps];
		char[] line=fs.next().toCharArray();
		
		for (int i=0; i<nLamps; i++) xorOne[i]=line[i]=='0';
		DisjointSet dj=new DisjointSet(nSubsets*2);
		for (int i=0; i<nSubsets; i++)
			dj.sizeOf[nSubsets+i]=0;//we don't actually have to flip any switches
		
		ArrayList<Integer>[] subsetsOf=new ArrayList[nLamps];
		for (int i=0; i<nLamps; i++) {
			subsetsOf[i]=new ArrayList<>();
		}
		for (int s=0; s<nSubsets; s++) {
			int k=fs.nextInt();
			for (int i=0; i<k; i++) {
				int lamp=fs.nextInt()-1;
				subsetsOf[lamp].add(s);
				if (subsetsOf[lamp].size()>2) throw null;
			}
		}
		PrintWriter out=new PrintWriter(System.out);
		
		for (int lamp=0; lamp<nLamps; lamp++) {
			if (subsetsOf[lamp].size()==0) {
				//hope we are okay because they say we will be
			}
			else if (subsetsOf[lamp].size()==1) {
				int subset=subsetsOf[lamp].get(0);
				if (xorOne[lamp]) {
					dj.markImpossible(subset+nSubsets);
				}
				else {
					dj.markImpossible(subset);
				}
			}
			else {
				//otherwise we have two choices
				int s1=subsetsOf[lamp].get(0), s2=subsetsOf[lamp].get(1);
				if (xorOne[lamp]) {
					//then they have to be different
					dj.dualUnion(s1, s2+nSubsets, s1+nSubsets, s2);
//					dj.union(s1, s2+nSubsets);
//					dj.union(s1+nSubsets, s2);
				}
				else {
					//they have to be the same
					dj.dualUnion(s1, s2, s1+nSubsets, s2+nSubsets);
//					dj.union(s1, s2);
//					dj.union(s1+nSubsets, s2+nSubsets);
				}
			}
			
			
			//TODO: print answer, left as an exercise to reader
			out.println(/* "Cur ans: "+ */dj.minSize);
		}
		out.close();
	}
	
	static class DisjointSet {
		int half;
		int[] s;
		int[] sizeOf;
		boolean[] impossible;

		int minSize=0;
		
		public DisjointSet(int n) {
			half=n/2;
			Arrays.fill(s = new int[n], -1);
			sizeOf=new int[n];
			Arrays.fill(sizeOf, 1);
			impossible=new boolean[n];
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public void markImpossible(int i) {
			i=find(i);
//			System.out.println("Marking "+i+" as impossible");
			minSize-=costChoice(i);
			impossible[i]=true;
			minSize+=costChoice(i);
		}
		
		public void dualUnion(int a, int b, int c, int d) {
			a=find(a); b=find(b); c=find(c); d=find(d);
//			System.out.println("Unioning "+a+" and "+b+" subtracted "+costChoice(a)+" and "+costChoice(b));
			if (a!=b) {
				minSize-=costChoice(a);
				minSize-=costChoice(b);
				union(a, b);				
				union(c, d);
				minSize+=costChoice(a);
//				System.out.println("Added in "+costChoice(a));
			}
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			
			
			if(s[a] <= s[b]) {
				s[b] = a;
				sizeOf[a]+=sizeOf[b];
				impossible[a]|=impossible[b];
			}
			else {
				s[a] = b;
				sizeOf[b]+=sizeOf[a];
				impossible[b]|=impossible[a];
			}
			a=find(a);
			
			return true;
		}
		
		int costChoice(int i) {
			int other=i<half?i+half:i-half;
			i=find(i);
			other=find(other);
			
			if (impossible[i]) return sizeOf[other];
			if (impossible[other]) return sizeOf[i];
			
			return Math.min(sizeOf[i], sizeOf[other]);
		}
	}
	
	
}