import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R300qD {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    char inp[][] = new char[n][n];
	    for(int i=0;i<n;i++)
	    	inp[i] = br.readLine().toCharArray();
	        
	    char ans[][] = new char[2*n-1][2*n-1];
	    ans[n-1][n-1] = 'o';
	    
	    boolean used[][] = new boolean[n][n];
	    
	    for(int dx = 1-n;dx<n;dx++){
	    	for(int dy=1-n;dy<n;dy++){
	    		if(dx == 0 && dy == 0)
	    			continue;
	    		boolean yes = true;
	    		int count = 0;
	    		for(int x=0;x<n;x++){
	    			for(int y=0;y<n;y++){
	    				if(inp[x][y] == 'o'){
	    					if(x + dx < n && x + dx >= 0 && y + dy < n && y + dy >= 0){
	    						if(inp[x+dx][y+dy] == '.')
	    							yes = false;
	    						else
	    							count++;
	    					}
	    				}
	    			}
	    		}
	    		if(count == 0)
	    			yes = false;
	    		if(yes){
	    			for(int x=0;x<n;x++)
	    				for(int y=0;y<n;y++)
	    					if(inp[x][y] == 'o' && x + dx < n && y + dy < n && x + dx >= 0 && y + dy >= 0)
	    						used[x+dx][y+dy] = true;
	    			ans[dx+n-1][dy+n-1] = 'x';
	    		}
	    		else
	    			ans[dx+n-1][dy+n-1] = '.';
	    	}
	    }
	    
	    
	    boolean yes = true;
	    for(int i=0;i<n && yes;i++){
	    	for(int j=0;j<n && yes;j++){
	    		if(inp[i][j] == 'x' && !used[i][j])
	    			yes = false;
	    	}
	    }
	    
	    if(!yes)
	    	w.println("NO");
	    else{
	    	w.println("YES");
	    	for(int i=0;i<2*n-1;i++)
	    		w.println(new String(ans[i]));
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}