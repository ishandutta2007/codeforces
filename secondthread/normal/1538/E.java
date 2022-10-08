import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;
/*
1
4
a := h
b := aha
c = a + b
c = c + c
 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nLines=fs.nextInt();
			HashMap<String, Res> map=new HashMap<>();
			Res last=null;
			for (int line=0; line<nLines; line++) {
				String var=fs.next();
				String queryType=fs.next();
				if (queryType.equals("=")) {
					//addition
					Res l=map.get(fs.next());
					fs.next();
					Res r=map.get(fs.next());
					map.put(var, last=new Res(l, r));
				}
				else {
					//assignment
					char[] target=fs.next().toCharArray();
					int inMiddleTimes=countHahaTimes(target);
					int len=target.length;
					char[] firstThree=new char[3];
					char[] lastThree=new char[3];
					if (len==1) {
						firstThree[0]=lastThree[2]=target[0];
					}
					else if (len==2) {
						firstThree[0]=lastThree[1]=target[0];
						firstThree[1]=lastThree[2]=target[1];
					}
					else {
						for (int i=0; i<3; i++) firstThree[i]=target[i];
						for (int i=0; i<3; i++) lastThree[i]=target[target.length-3+i];
					}
					Res r=new Res(inMiddleTimes, firstThree, lastThree, len);
					map.put(var, last=r);
				}
			}
			System.out.println(last.nTimesInMiddle);
		}
	}
	
	static int countHahaTimes(char[] a) {
		int count=0;
		for (int i=0; i<a.length-3; i++)
			if (a[i]=='h' && a[i+1]=='a' && a[i+2]=='h' && a[i+3]=='a')
				count++;
		return count;
	}
	

	static class Res {
		long nTimesInMiddle;
		char[] firstThree;
		char[] lastThree;
		long len;
		
		public Res(int nTimesInMiddle, char[] firstThree, char[] lastThree, long len) {
			this.nTimesInMiddle=nTimesInMiddle;
			this.firstThree=firstThree;
			this.lastThree=lastThree;
			this.len=len;
		}
		
		public Res(Res first, Res last) {
			long times=first.nTimesInMiddle+last.nTimesInMiddle;
			char[] a=first.lastThree, b=last.firstThree;
			if (a[0]=='h' && a[1]=='a' && a[2]=='h' && b[0]=='a') times++;
			if (a[1]=='h' && a[2]=='a' && b[0]=='h' && b[1]=='a') times++;
			if (a[2]=='h' && b[0]=='a' && b[1]=='h' && b[2]=='a') times++;
			this.len=first.len+last.len;
			this.nTimesInMiddle=times;
			
			ArrayList<Character> known=new ArrayList<>();
			if (first.len<3) {
				for (int i=0; i<first.len; i++) known.add(first.firstThree[i]);
			}
			else {
				for (char c:first.firstThree) known.add(c);
				for (char c:first.lastThree) known.add(c);
			}
			if (last.len<3) {
				for (int i=0; i<last.len; i++) known.add(last.firstThree[i]);
			}
			else {
				for (char c:last.firstThree) known.add(c);
				for (char c:last.lastThree) known.add(c);
			}
			
			this.firstThree=new char[3];
			this.lastThree=new char[3];
			if (len==2) {
				firstThree[0]=lastThree[1]=known.get(0);
				firstThree[1]=lastThree[2]=known.get(1);
			}
			else {
				for (int i=0; i<3; i++) firstThree[i]=known.get(i);
				for (int i=0; i<3; i++) lastThree[i]=known.get(known.size()-3+i);
			}
		}
		
		public String toString() {
			return "times: "+nTimesInMiddle+" "+Arrays.toString(firstThree)+" "+Arrays.toString(lastThree);
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