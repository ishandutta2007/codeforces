import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
5
5
1 2 3 4 5
5
5 4 3 2 1
8
8 4 5 2 3 6 7 3
7
5 2 1 6 4 7 3
6
1 2 3 3 6 4


1
5
1 2 3 4 5


1
3
3 1 2
 */
public class F {

	static final boolean debug=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Element[] elements=new Element[n], sorted=new Element[n];
			for (int i=0; i<n; i++) elements[i]=sorted[i]=new Element(fs.nextInt());
			Arrays.sort(sorted);
			for (int i=0; i<n; i++) sorted[i].value=i;
			
			int invs=0;
			for (int i=0; i<n; i++)
				for (int j=i+1; j<n; j++)
					if (elements[i].value>elements[j].value) invs++;
			
			if (debug) System.out.println("Initial inversions: "+invs);
			if (invs%2==1) {
				outer: for (int first=0; first<n; first++) {
					for (int second=first+1; second<n; second++) {
						if (elements[first].orig != elements[second].orig) continue;
						int changed=0;
						for (int i=first; i<second; i++) {
							if (elements[i].value>=elements[first].value && elements[i].value<elements[second].value) {
								changed++;
							}
						}
						if (changed%2==1) {
							invs++;
							int temp=elements[first].value;
							elements[first].value=elements[second].value;
							elements[second].value=temp;
							break outer;
						}
					}
				}
			}
			Arrays.sort(sorted);
			if (debug) System.out.println("Perm:");
			for (Element e:elements)
				if (debug) System.out.print(e.value+" ");
			if (debug) System.out.println();
			
			if (invs%2!=0) {
				out.println("-1");
				continue;
			}
			
			ArrayList<Integer> indecies=new ArrayList<>();
			for (int toFixInd=n-1; toFixInd>=0; toFixInd--) {
				Element toFix=sorted[toFixInd];
				int index=0;
				for (int i=0; i<n; i++) if (elements[i]==toFix) index=i;
				if (debug) System.out.println("Trying to fix thing at index "+index);
				while (index<toFixInd-1) {
					swap(elements, index, indecies);
					index++;
				}
				if (index==toFixInd-1) {
					swap(elements, toFixInd-2, indecies);
					index++;
				}
			}
			
			out.println(indecies.size());
			for (int i:indecies) {
				out.print(i+1+" ");
			}
			out.println();
		}
		out.close();
	}
	
	static void swap(Element[] elements, int index, ArrayList<Integer> indecies) {
		if (debug) System.out.println("Swapping from index "+index);
		indecies.add(index);
		Element e1=elements[index], e2=elements[index+1], e3=elements[index+2];
		elements[index]=e3;
		elements[index+1]=e1;
		elements[index+2]=e2;
	}
	
	static class Element implements Comparable<Element> {
		int value, orig;
		
		public Element(int orig) {
			this.value=this.orig=orig;
		}
		
		public int compareTo(Element o) {
			return Integer.compare(value, o.value);
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