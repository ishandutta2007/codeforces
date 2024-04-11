import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;


public class R279Queue {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    AB x1[] = new AB[n]; //sorted on a
	    AB x2[] = new AB[n]; //sorted on b
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int a = ip(st2.nextToken());
	    	int b = ip(st2.nextToken());
	    	x1[i] = new AB(a,b);
	    	x2[i] = new AB(a,b);
	    }
	    
	    Arrays.sort(x1);
	    AB.sortRev = true;
	    Arrays.sort(x2);
	    
	    int ans[] = new int[n];
	    

	    	int prev = 0;
		    for(int i=1;i<n;i+=2){
		    	int i1 = bSa(x1,prev);
		    	ans[i] = x1[i1].b;
		    	prev = ans[i];
		    }
		    
		    int inC[] = new int[1000001];
		    int outC[] = new int[1000001];
		    
		    for(int i=0;i<n;i++){
		    	outC[x1[i].a]++;
		    	inC[x1[i].b]++;
		    }
		    
		    int start = -1;
		    for(int i=1;i<=1000000;i++){
		    	if(inC[i] == 0 && outC[i] == 1)
		    		start = i;
		    }
		    
		    ans[0] = start;
		    
		    for(int i=2;i<n;i+=2){
		    	ans[i] = x1[bSa(x1,start)].b;
		    	start = ans[i];
		    }
	    
		    
	    for(int i=0;i<n;i++)
	    	w.print(ans[i] + " ");
	    w.close(); 
	}
	
	public static int bSa(AB[] a,int key){
		int start = 0,end = a.length;
		while(true){
			if(start==end) return -1;
			int mid = (start+end)/2;
			if(key==a[mid].a) return mid;
			if(end-start==1) return -1;
			if(key<a[mid].a)	end = mid;
			else start = mid+1;
		}
	}
	
	public static int bSb(AB[] a,int key){
		int start = 0,end = a.length;
		while(true){
			if(start==end) return -1;
			int mid = (start+end)/2;
			if(key==a[mid].b) return mid;
			if(end-start==1) return -1;
			if(key<a[mid].b)	end = mid;
			else start = mid+1;
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}

class AB implements Comparable<AB>{
	static boolean sortRev;
	int a,b;
	AB(int i,int j){
		a = i;
		b = j;
		sortRev = false;
	}
	public int compareTo(AB arg0) {
		if(!sortRev)
			return a - arg0.a;
		else
			return b - arg0.b;
	}
	
}