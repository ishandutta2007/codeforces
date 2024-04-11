import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R262D2TCPresent {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    int p = ip(st1.nextToken());
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    w.println(binarySearchLast(a,m,p));
	    w.close(); 
	}
	
	public static int binarySearchLast(int[] a,int m,int w){
		int start = 0,end = 1111111111;
		int ret = -1;
		while(true){
			if(start==end) return ret;
			int mid = (start+end)/2;
			long key;
			if((key = func(a,mid,m,w)) >= 0) ret = mid;
			if(end-start==1) return ret;
			if(key < 0)	end = mid;
			else start = mid+1;
		}
	}
	
	public static long func(int[] a,int minHeight,int m,int w){
		long total = 0;
		long st[] = new long[a.length];
		int b[] = new int[a.length];
		for(int i=0;i<a.length;i++)
			b[i] = a[i];
		Arrays.fill(st,0);
		
		for(int i=0;i<a.length;i++){
			if(i-w >= 0)
				total -= st[i-w];
			b[i] += total;
			st[i] = Math.max(0,minHeight-b[i]);
			total += st[i];
		}
		
		total = 0;
		for(int i=0;i<a.length;i++)
			total += st[i];
		
		return m - total; 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}