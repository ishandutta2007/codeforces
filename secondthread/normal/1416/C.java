import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		long nInversions=0;
		int x=0;
		int trie=create(30);
		for (int i:a) {
			add(trie, i);
		}
		for (int i=30; i>=0; i--) {
			if (penaltyIfStay[i]>penaltyIfSwitch[i]) {
				x+=1<<i;
				nInversions+=penaltyIfSwitch[i];
			}
			else {
				nInversions+=penaltyIfStay[i];
			}
		}
		
		System.out.println(nInversions+" "+x);
	}
	
	static long[] penaltyIfStay=new long[31];
	static long[] penaltyIfSwitch=new long[31];
	
	static int trieNodes=3*100000*31;
	static int[] pow=new int[trieNodes], lChild=new int[trieNodes], rChild=new int[trieNodes], nZeros=new int[trieNodes], nOnes=new int[trieNodes];
	static int trieNode=0;
	
	static int create(int poww) {
		pow[trieNode]=poww;
		return trieNode++;
	}
	
	static void add(int node, int i) {
		boolean has=(i&(1<<pow[node]))!=0;
		if (has) {
			penaltyIfSwitch[pow[node]]+=nZeros[node];
			nOnes[node]++;
			
			if (pow[node]!=0) {
				if (rChild[node]==0) rChild[node]=create(pow[node]-1);
				add(rChild[node], i);
			}
		}
		else {
			
			penaltyIfStay[pow[node]]+=nOnes[node];
			nZeros[node]++;
			
			if (pow[node]!=0) {
				if (lChild[node]==0) lChild[node]=create(pow[node]-1);
				add(lChild[node], i);
			}
		}
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