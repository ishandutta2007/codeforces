import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
	
	static String[] on= {
			"1110111",
			"0010010",
			"1011101",
			"1011011",
			"0111010",
			"1101011",
			"1101111", 
			"1010010", 
			"1111111", 
			"1111011"
	};
	
	static int[] onBits=new int[10];
	static int[] lockedOn;
	static int[][] dp;
	
	public static void main(String[] args) {
		precomp();
		
		FastScanner fs=new FastScanner();
		int nNumbers=fs.nextInt(), toTurnOn=fs.nextInt();
		lockedOn=new int[nNumbers];
		for (int i=0; i<nNumbers; i++) {
			char[] line=fs.next().toCharArray();
			int val=0;
			for (int x=0; x<7; x++)
				if (line[x]=='1') val+=1<<x;
			lockedOn[i]=val;
		}
		dp=new int[nNumbers+1][2001];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
		
		PrintWriter out=new PrintWriter(System.out);
		ArrayList<Integer> ans=new ArrayList<>();
		outer:for (int index=0; index<nNumbers; index++) {
			for (int toPlace=9; toPlace>=0; toPlace--) {
				if ((lockedOn[index] & onBits[toPlace])!=lockedOn[index]) continue;
				int diff=Integer.bitCount(onBits[toPlace]-lockedOn[index]);
//				System.out.println(toPlace+" "+diff);
				boolean futureRes=go(index+1, toTurnOn-diff);
				if (futureRes) {
					ans.add(toPlace);
					toTurnOn-=diff;
					continue outer;
				}
			}
			out.println(-1);
			out.close();
			return;
		}
		for (int i:ans) out.print(i);
		out.println();
		out.close();
	}
	
	
	static boolean go(int index, int onBitsLeft) {
		if (onBitsLeft<0) return false;
		if (index==lockedOn.length) {
			return onBitsLeft==0;
		}
		if (dp[index][onBitsLeft]!=-1) return dp[index][onBitsLeft]==1;
		for (int toPlace=0; toPlace<10; toPlace++) {
			if ((lockedOn[index] & onBits[toPlace])!=lockedOn[index]) continue;
			int diff=Integer.bitCount(onBits[toPlace]-lockedOn[index]);
			boolean futureRes=go(index+1, onBitsLeft-diff);
			if (futureRes) {
				dp[index][onBitsLeft]=1;
				return true;
			}
		}
		dp[index][onBitsLeft]=0;
		return false;
	}
	
	static void precomp() {
		for (int n=0; n<10; n++) {
			int val=0;
			for (int x=0; x<7; x++) {
				if (on[n].charAt(x)=='1') val+=1<<x;
			}
			onBits[n]=val;
		}
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