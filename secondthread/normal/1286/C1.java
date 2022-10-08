import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
/*

4
a
a
b
c
aa
ab
bc
aab
abc
aabc

a
a
b
aa
ab
aab
 */
public class C {

	static final boolean debug=false;
	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt();
		if (n<=3) {
			smallCase(fs, n);
			return;
		}
		System.out.println("? 1 "+n); System.out.flush();
		String[] strings1=new String[n*(n+1)/2];
		for (int i=0; i<strings1.length; i++)
			strings1[i]=fs.next();
		
		System.out.println("? 1 "+(n-1)); System.out.flush();
		String[] strings2=new String[n*(n-1)/2];
		for (int i=0; i<strings2.length; i++)
			strings2[i]=fs.next();
		char[] ans=getAnswer(strings1, strings2, n);
		
		System.out.println("! ");
		for (char c:ans) System.out.print(c);
		System.out.println();
	}
	
	static void smallCase(Scanner fs, int n) {
		char[] ans=new char[n];
		for (int i=0; i<n; i++) {
			System.out.println("? "+(i+1)+" "+(i+1)); System.out.flush();
			ans[i]=fs.next().charAt(0);
		}
		System.out.print("! ");
		for (char c:ans) System.out.print(c);
		System.out.println(); System.out.flush();
	}
	
	static char[] getAnswer(String[] strings1, String[] strings2, int n) {
		int[] cs=new int[26];
		for (String s:strings1) if (s.length()==1) cs[s.charAt(0)-'a']++;
		for (String s:strings2) if (s.length()==1) cs[s.charAt(0)-'a']--;
		char last=0;
		for (int i=0; i<26; i++) if (cs[i]!=0) last=(char)(i+'a');
		char[][] strings1Choices=getChoices(strings1, n);
		char[][] strings2Choices=getChoices(strings2, n-1);
		char[] ans=new char[n];
		ans[n-1]=last;
		for (int i=0; i<=(n-1)/2; i++) {
			char old=ans[n-1-i];
			char me=(char) (strings1Choices[i][0] ^ strings1Choices[i][1] ^ old);
			int farIndex=n-1-i-1;
			char farVal= (char) (strings2Choices[farIndex][0] ^ strings2Choices[farIndex][1] ^ me);
			ans[i]=me;
			ans[farIndex]=farVal;
		}
		return ans;
	}
	
	static char[][] getChoices(String[] strings, int n) {
		if (debug) System.out.println("Getting choices for n: "+n);
		char[][] toReturn=new char[n][2];
		ArrayList<String>[] ofLength=new ArrayList[n+1];
		for (int i=0; i<ofLength.length; i++) ofLength[i]=new ArrayList<>();
		for (String s:strings) ofLength[s.length()].add(s);
		int[][] csOfLength=new int[n+1][26];
		for (int i=1; i<=n; i++) {
			for (String s:ofLength[i]) {
				for (char c:s.toCharArray()) {
					csOfLength[i][c-'a']++;
				}
			}
		}

		int[] expectedDelta=new int[26];
		for (String s:ofLength[1]) {
			expectedDelta[s.charAt(0)-'a']++;
		}
		for (int index=0; index<=(n-1)/2; index++) {
			if (debug) System.out.println("Trying for index: "+index+" and "+(n-index-1)+" expectedDelta: " +Arrays.toString(expectedDelta));
			ArrayList<Integer> possible=new ArrayList<>();
			for (int i=0; i<26; i++) {
				//we want delta of zero and cs of index+1, looking at array n-index and n-index-1
				int delta=-csOfLength[n-index][i]+csOfLength[n-index-1][i];
				if (i<3) {
					if (debug) System.out.println("    For i: "+i+" delta: "+delta+" expected: "+expectedDelta[i]);
					if (debug) System.out.println("    "+csOfLength[n-index][i]+" "+csOfLength[n-index-1][i]);
				}
				if (delta==expectedDelta[i]) continue;
				possible.add(i);
			}
			if (debug) System.out.println("  Choices are "+possible);
			if (possible.size()==1) possible.add(possible.get(0));
			toReturn[index][0]=toReturn[n-1-index][0]=(char)(possible.get(0)+'a');
			toReturn[index][1]=toReturn[n-1-index][1]=(char)(possible.get(1)+'a');
			expectedDelta[possible.get(0)]--;
			expectedDelta[possible.get(1)]--;
		}
		return toReturn;
	}
	
	
}