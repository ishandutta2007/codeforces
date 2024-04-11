import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.*;


/*

Not more than k -> at most k

 */
public class Solution {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
    		int n=fs.nextInt(), q=fs.nextInt();
    		int[] a=fs.readArray(n);
    		ruffleSort(a);
    		long sum=0;
    		TreeMap<Long, Integer> map=new TreeMap<>();
    		for (int i=0; i<n; i++) {
    		    map.put(sum, i);
    		    sum+=a[n-1-i];
    		}
    		map.put(sum, n);
    		for (int qq=0; qq<q; qq++) {
    		    int x=fs.nextInt();
    		    if (map.ceilingKey((long)x)==null) {
    		        out.println(-1);
    		    }
    		    else {
    		        out.println(map.get(map.ceilingKey((long)x)));
    		    }
    		}
		}
		out.close();
	}
	
	static long eval(int y, int x, int[][] board, int w, int h) {
	    int ans=board[y][x];
	    int[] dx={1, 1, -1, -1}, dy={1, -1, -1, 1};
	    for (int d=0; d<4; d++) {
	        for (int i=1; true; i++) {
	            int nx=x+dx[d]*i, ny=y+dy[d]*i;
	            if (nx<0 || ny<0 || nx>=w || ny>=h) break;
	            ans+=board[ny][nx];
	        }
	    }
	    return ans;
	}
	
	static int cost(int i, int j, char[][] words) {
	    int ans=0;
	    for (int k=0; k<words[i].length; k++) {
	        ans+=Math.abs((int)words[i][k]- (int)words[j][k]);
	    }
	    return ans;
	}
	
	static int sum(int x) {
	    if (x==0) return 0;
	    return x%10+sum(x/10);
	}
	
	static final Random random=new Random();
	static final int mod=998244353;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
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