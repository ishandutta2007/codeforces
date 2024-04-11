import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter; 
import java.util.Queue;
import java.util.LinkedList;

public class R8qbObsessionWithRoads {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    boolean vis[][] = new boolean[300][300];
	    
	    vis[150][150] = true;
	    
	    char s[] = br.readLine().toCharArray();
	    int x = 150,y = 150;
	    for(int i=0;i<s.length;i++){
	    	if(s[i] == 'U')
	    		x--;
	    	if(s[i] == 'D')
	    		x++;
	    	if(s[i] == 'L')
	    		y--;
	    	if(s[i] == 'R')
	    		y++;
	    	vis[x][y] = true;
	    }
	    
	    Queue<Integer> q = new LinkedList<Integer>();
	    q.add(150);
	    q.add(150);
	    
	    int ans[][] = new int[300][300];
	    ans[150][150] = 1;
	    
	    while(true){
	    	int a = q.remove();
	    	int b = q.remove();
	    	if(x == a && y == b)	break;
	    	if(a + 1 < 300 && ans[a+1][b] == 0 && vis[a+1][b]){
	    		q.add(a+1);
	    		q.add(b);
	    		ans[a+1][b] = ans[a][b] + 1;
	    	}
	    	if(a - 1 >= 0 && ans[a-1][b] == 0 && vis[a-1][b]){
	    		q.add(a-1);
	    		q.add(b);
	    		ans[a-1][b] = ans[a][b] + 1;
	    	}
	    	if(b + 1 < 300 && ans[a][b+1] == 0 && vis[a][b+1]){
	    		q.add(a);
	    		q.add(b+1);
	    		ans[a][b+1] = ans[a][b] + 1;
	    	}
	    	if(b - 1 >= 0 && ans[a][b-1] == 0 && vis[a][b-1]){
	    		q.add(a);
	    		q.add(b-1);
	    		ans[a][b-1] = ans[a][b] + 1;
	    	}
	    }
	    
	    ans[x][y]--;
	    if(ans[x][y] == s.length)
	    	w.println("OK");
	    else
	    	w.println("BUG");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}