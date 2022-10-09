import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
ABC
AAC
Z
 */
public class B {
	
	static int[][] failAt=new int[101][26];
	
	static int[][][] dp;
	
	static int oo=100000000;
	static char[] s1, s2, virus;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		s1=fs.next().toCharArray(); s2=fs.next().toCharArray();
		String virusString=fs.next();
		virus=virusString.toCharArray();
		for (int oldAt=0; oldAt<virus.length; oldAt++) {
			String candidate=virusString.substring(0, oldAt);
			for (int place=0; place<26; place++) {
				String lookingFor=candidate+(char)('A'+place);
				for (int start=0; start<=lookingFor.length(); start++) {
					String startsWith=lookingFor.substring(start);
//					System.out.println(virusString+" "+startsWith);
					if (virusString.startsWith(startsWith)) {
						failAt[oldAt][place]=startsWith.length();
//						System.out.println("Fail at: "+oldAt+" "+place+" is "+failAt[oldAt][place]);
						break;
					}
				}
			}
		}
		dp=new int[s1.length][s2.length][virus.length];
		for (int i=0; i<dp.length; i++)
			for (int j=0; j<dp[i].length; j++) 
				Arrays.fill(dp[i][j], -1);
		int ans=go(0, 0, 0);
		if (ans==0) {
			System.out.println(0);
		}
		else {
			print(0, 0, 0);
			System.out.println();
//			System.out.println(ans);
		}
	}
	
	static int go(int s1Ind, int s2Ind, int indInVirus) {
		if (indInVirus==virus.length) return -oo;
		if (s1Ind==s1.length||s2Ind==s2.length) return 0;
		//pick from both
		if (dp[s1Ind][s2Ind][indInVirus]!=-1)
			return dp[s1Ind][s2Ind][indInVirus];
		int best=0;
		best=Math.max(go(s1Ind+1, s2Ind, indInVirus), best);
		best=Math.max(go(s1Ind, s2Ind+1, indInVirus), best);
		if (s1[s1Ind]==s2[s2Ind]) {
			best=Math.max(best, 1+go(s1Ind+1, s2Ind+1, failAt[indInVirus][s1[s1Ind]-'A']));
		}
//		System.out.println("Go "+s1Ind+" "+s2Ind+" "+indInVirus+" is "+best);
		
		return dp[s1Ind][s2Ind][indInVirus]=best;
	}
	static void print(int s1Ind, int s2Ind, int indInVirus) {
		if (indInVirus==virus.length) {
//			System.out.println("asdf");
			return;
		}
		if (s1Ind==s1.length||s2Ind==s2.length) {
//			System.out.println("asdfsf "+s1Ind+" "+s2Ind);
			return;
		}
		//pick from both
		int ans=go(s1Ind, s2Ind, indInVirus);
		int best=0;
		best=Math.max(go(s1Ind+1, s2Ind, indInVirus), best);
		if (ans==best) {
			print(s1Ind+1, s2Ind, indInVirus);
			return;
		}
		best=Math.max(go(s1Ind, s2Ind+1, indInVirus), best);
		if (ans==best) {
			print(s1Ind, s2Ind+1, indInVirus);
			return;
		}
		if (s1[s1Ind]==s2[s2Ind]) {
//			best=Math.max(best, 1+go(s1Ind+1, s2Ind+1, failAt[indInVirus][s1[s1Ind]-'A']));
			System.out.print(s1[s1Ind]);
			print(s1Ind+1, s2Ind+1, failAt[indInVirus][s1[s1Ind]-'A']);
			return;
		}
//		System.out.println("Go "+s1Ind+" "+s2Ind+" "+indInVirus+" is "+best);
		throw null;
//		return dp[s1Ind][s2Ind][indInVirus]=best;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}