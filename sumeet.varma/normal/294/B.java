import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;

public class R178qB {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	
	    ArrayList<Integer> a1 = new ArrayList<Integer>();
	    ArrayList<Integer> a2 = new ArrayList<Integer>();
	    for(int i=0;i<n;i++){
		    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int t = ip(st2.nextToken());
	    	if(t == 1)
	    		a1.add(ip(st2.nextToken()));
	    	else
	    		a2.add(ip(st2.nextToken()));
	    }
	    
	    Collections.sort(a1);
	    Collections.sort(a2);
	    int a1s = a1.size();
	    int a2s = a2.size();
	    
	    int ans = 2*n;
	    
	    for(int num=1;num<=n;num++){
	    	for(int i1=0;i1<=Math.min(num,a1s);i1++){
	    		int i2 = num - i1;
	    		if(i2 > a2s)
	    			continue;	
	    		int thick = i1 + 2*i2;
	    		int width = 0;
	    		for(int i=0;i<a1s - i1;i++)
	    			width += a1.get(i);
	    		for(int i=0;i<a2s - i2;i++)
	    			width += a2.get(i);
	    		if(width <= thick)
	    			ans = Math.min(ans, thick);
	    	}
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}