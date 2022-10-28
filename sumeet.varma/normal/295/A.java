//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R179qCGregAndArray {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    int n = ip(st.nextToken());
	    int m = ip(st.nextToken());
		int k = ip(st.nextToken());
	    
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = ip(st1.nextToken());
		
		int l[] = new int[m];
		int r[] = new int[m];
		int d[] = new int[m];
		int count[] = new int[m+1];
		
		for(int i=0;i<m;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			l[i] = ip(st2.nextToken()) - 1;
			r[i] = ip(st2.nextToken()) - 1;
			d[i] = ip(st2.nextToken());
		}
	    
		for(int i=0;i<k;i++){
			StringTokenizer st3 = new StringTokenizer(br.readLine());
			count[ip(st3.nextToken()) - 1]++;
			count[ip(st3.nextToken())]--;
		}
		
		for(int i=1;i<m;i++)
			count[i] += count[i-1];
		
		long update[] = new long[n+1];
		for(int i=0;i<m;i++){
			update[l[i]] += d[i] * 1L * count[i];
			update[r[i]+1] -= d[i] * 1L * count[i];
		}
		
		for(int i=1;i<n;i++)
			update[i] += update[i-1];
		
		for(int i=0;i<n;i++)
			w.print((a[i] + update[i]) + " ");
		w.println();
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}