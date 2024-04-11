import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class LongJumps {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int l = ip(st1.nextToken());
	    int x = ip(st1.nextToken());
	    int y = ip(st1.nextToken());
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    boolean xfound = false;
	    boolean yfound = false;
	    
	    for(int i=0;i<n-1;i++){
	    	if(!xfound){
	    		if(bS(a,a[i]+x,i+1,n)!=-1)
	    			xfound = true;
	    	}
	    	if(!yfound){
	    		if(bS(a,a[i]+y,i+1,n)!=-1)
	    			yfound = true;
	    	}
	    }
	    
	    if(xfound && yfound)
	    	w.println("0");
	    
	    else if(xfound != yfound){
	    	w.println("1");
	    	if(!xfound)
	    		w.println(x);
	    	else
	    		w.println(y);
	    }
	    
	    else{
	    	boolean nice = false;
	    	int ans1=x,ans2=y;
	    	
	    	for(int i=0;i<n;i++){
	    		//mark at a[i]+x
	    		if(bS(a,a[i]+x+y,0,n)!=-1){
	    			nice = true;
	    			ans1 = a[i]+x;
	    			break;
	    		}
	    		if(bS(a,a[i]+y-x,0,n)!=-1){
	    			if(a[i] + y <= l){
	    				nice = true;
	    				ans1 = a[i] + y;
	    				break;
	    			}
	    			if(a[i] - x  >= 0){
	    				nice = true;
	    				ans1 = a[i] - x;
	    				break;
	    			}
	    		}
	    		if(bS(a,a[i]+x-y,0,n)!=-1){
	    			if(a[i] + x <= l){
	    				nice = true;
	    				ans1 = a[i] + x;
	    				break;
	    			}
	    			if(a[i] - y >= 0){
	    				nice = true;
	    				ans1 = a[i] - y;
	    				break;
	    			}
	    		}
	    	}
	    	
	    	if(nice){
	    		w.println("1");
	    		w.println(ans1);
	    	}
	    	else{
	    		w.println("2");
	    		w.println(ans1 + " " + ans2);
	    	}
	    }
	    w.close(); 
	}
	
	public static int bS(int[] a,int key,int start,int end){
		while(true){
			if(start==end) return -1;
			int mid = (start+end)/2;
			if(key==a[mid]) return mid;
			if(end-start==1) return -1;
			if(key<a[mid])	end = mid;
			else start = mid+1;
		}
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}