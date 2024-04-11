import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {
	
	static final boolean debug=false;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		
		//sweep from left
		int[] lTail=new int[n];
		ArrayDeque<Integer> stk=new ArrayDeque<>();
		int[] beatenOnL=new int[n];
		for (int i=0; i<n; i++) {
			if (line[i]=='1') {
				lTail[i]=(i==0)?1:(lTail[i-1]+1);
				while (!stk.isEmpty() && lTail[stk.peekLast()]<lTail[i]) 
					stk.removeLast();
				beatenOnL[i]=stk.isEmpty()?-1:stk.peekLast();
			}
			else {
				lTail[i]=0;
				if (i!=0 && line[i-1]=='1') stk.addLast(i-1);
			}
		}
		
		
		//sweep from right
		int[] rTail=new int[n];
		stk.clear();
		int[] beatenOnR=new int[n];
		for (int i=n-1; i>=0; i--) {
			if (line[i]=='1') {
				rTail[i]=(i==n-1)?1:(rTail[i+1]+1);
				while (!stk.isEmpty() && rTail[stk.peekLast()]<=rTail[i]) 
					stk.removeLast();
				beatenOnR[i]=stk.isEmpty()?-1:stk.peekLast();
			}
			else {
				rTail[i]=0;
				if (i!=n-1 && line[i+1]=='1') stk.addLast(i+1);
			}
		}
		stk.clear();
		
		if (debug) System.out.println(Arrays.toString(beatenOnL));
		if (debug) System.out.println(Arrays.toString(beatenOnR));
		
		long ans=0;
		for (int startAt=0; startAt<n; startAt++) {
			if (line[startAt]=='0') continue;
			if (debug) System.out.println("Processing range starting at "+startAt);
			int rangeSize=0;
			int rangeStart=startAt;
			while (startAt<n && line[startAt]=='1') {
				rangeSize++;
				startAt++;
			}
			int rangeEnd=startAt-1;
			if (debug) System.out.println("  Ans initially "+ans);
			for (int i=1; i<rangeSize; i++) {
				ans+=i*(long)(rangeSize-i+1);
			}
			if (debug) System.out.println("  After adding included substrings "+ans);
			//cover entire range
			{
				int lEnd=beatenOnL[rangeEnd];
				int rEnd=beatenOnR[rangeStart];
				int firstLegalStart;
				if (lEnd==-1) {
					firstLegalStart=0;
				}
				else {
					firstLegalStart=lEnd-rangeSize+1 +1;
				}
				int lastLegalEnd;
				if (rEnd==-1) {
					lastLegalEnd=n-1;
				}
				else {
					lastLegalEnd=rEnd+rangeSize-1;
				}
				long toAdd=(rangeStart-firstLegalStart+1)*(long)(lastLegalEnd-rangeEnd+1)*
						(long)rangeSize;
				ans+=toAdd;
				if (debug) System.out.println("  Full range, added "+toAdd);
				if (debug) System.out.println("  "+rangeStart+" "+firstLegalStart+" "+lastLegalEnd+" "+rangeEnd);
			}
			
			//TODO: all prefixes and suffixes
			for (int preLen=1; preLen<rangeSize; preLen++) {
				int lEnd=beatenOnL[rangeStart+preLen-1];
				int firstLegalStart;
				if (lEnd==-1) {
					firstLegalStart=0;
				}
				else {
					firstLegalStart=lEnd-preLen+1 +1;
				}
				long toAdd=(rangeStart-firstLegalStart+1)*1*
						(long)preLen - preLen;
				ans+=toAdd;
				if (debug) System.out.println("  Prefix len "+preLen+" added "+toAdd);
			}
			
			for (int suffLen=1; suffLen<rangeSize; suffLen++) {
				int rEnd=beatenOnR[rangeEnd-suffLen+1];
				int lastLegalEnd;
				if (rEnd==-1) {
					lastLegalEnd=n-1;
				}
				else {
					lastLegalEnd=rEnd+suffLen-1;
				}
				long toAdd=(1)*(long)(lastLegalEnd-rangeEnd+1)*
						(long)suffLen - suffLen;
				ans+=toAdd;
				if (debug) System.out.println("  Suffix len "+suffLen+" added "+toAdd);
			}
		}
		System.out.println(ans);
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