
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R280D2TaskEVanyaAndField {
	
	static int n,m,dx,dy;
	static int id[],moves[];
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	    dx = ip(st1.nextToken());
	    dy = ip(st1.nextToken());
	    
	    moves = new int[n];
	    int a,b;
	    a = b = moves[0] = 0;
	    
	    for(int i=0;i<n;i++){
	    	a = (a + dx) % n;
	    	b = (b + dy) % n;
	    	moves[a] = b;
	    }
	    
	    id = new int[n];
	    
	    for(int i=0;i<m;i++){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	int x = ip(st.nextToken());
	   		int y = ip(st.nextToken());
	   		id[(y-moves[x]+n)%n]++;
	    }
	    
	    int maxID = 0;
	    for(int i=0;i<n;i++)
	    	if(id[i] > id[maxID])
	    		maxID = i;
	    
	    if(n == 5)
	    	w.printf("%d %d\n",(3*dx)%n,(maxID+3*dy)%n);
        else
        	w.printf("0 %d\n",maxID);

	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}