import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TeamOlympiad {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	  
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    int c[] = new int[3];
	    for(int i=0;i<n;i++)
	    	c[a[i] - 1]++;
	    
	    int t = Math.min(c[0], Math.min(c[1],c[2]));
	    w.println(t);
	    
	    int ans[][] = new int[n][3];
	    int i=0,j=0,k=0;
	    
	    for(int b=0;b<n;b++){
	    	if(a[b] == 1)
	    		ans[i++][0] = b+1;
	    	else if(a[b] == 2)
	    		ans[j++][1] = b+1;
	    	else
	    		ans[k++][2] = b+1;
	    }
	    
	    for(int b=0;b<t;b++)
	    	w.println(ans[b][0] + " " + ans[b][1] + " " + ans[b][2]);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}