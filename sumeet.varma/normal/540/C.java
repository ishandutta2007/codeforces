
//Pretest 15 ..Stop hacking pls. -__-
//When you write r1 == c1 && r2 == c2 instead of r1 == r2 && c1 == c2 :/

import java.io.*;
import java.util.*;

public class R301qD {
	static int n,m;
	static char grid[][];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	          
	    grid = new char[n][m];
	    for(int i=0;i<n;i++)
	    	grid[i] = br.readLine().toCharArray();
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int r1 = ip(st2.nextToken()) - 1;
	    int c1 = ip(st2.nextToken()) - 1;
	    
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    int r2 = ip(st3.nextToken()) - 1;
	    int c2 = ip(st3.nextToken()) - 1;
	    
	    boolean reached = false;
	 
	    int count = 0;
	   	if(r2 - 1 >= 0 && grid[r2-1][c2] == '.')
	   		count++;
	   	if(r2 + 1 < n && grid[r2+1][c2] == '.')
  			count++;
    	if(c2 - 1 >= 0 && grid[r2][c2-1] == '.')
    		count++;
	   	if(c2 + 1 < m && grid[r2][c2+1] == '.')
	   		count++;
	   	
	 	if(r1 == r2 && c1 == c2){
	   		if(count == 0)
	   			System.out.println("NO");
	   		else
	   			System.out.println("YES");
	   		return;
	    }
	 	
	 	if(Math.abs(r1 - r2) + Math.abs(c1 - c2) == 1){
	 		if(grid[r2][c2] == 'X')
	 			System.out.println("YES");
	 		else{
	 			if(count >= 1)
	 				System.out.println("YES");
	 			else
	 				System.out.println("NO");
	 		}
	 		return;
	 	}
	   	
	   	if(count == 0){
	   		System.out.println("NO");
	   		return;
	   	}
	   	
	   	if(count == 1){
	   		if(grid[r2][c2] == '.'){
	   			System.out.println("NO");
	   			return;
	   		}
	   	}
	   	
	    boolean vis[][] = new boolean[n][m];
	    vis[r1][c1] = true;
		
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(r1);
		q.add(c1);
		while(!q.isEmpty() && !reached){
			int x = q.remove();
			int y = q.remove();
			
			if(x-1>=0 && vis[x-1][y] == false){
				if(grid[x-1][y] == '.'){
					q.add(x-1);
					q.add(y);
				}
				if(x - 1 == r2 && y == c2)
					reached = true;
				vis[x-1][y] = true;
			}
			
			if(y-1>=0 && vis[x][y-1] == false){
					if(grid[x][y-1] == '.'){
						q.add(x);
						q.add(y-1);
					}
					if(x  == r2 && y - 1 == c2)
						reached = true;
				vis[x][y-1] = true;
			}
			
			if(x+1<n && vis[x+1][y] == false){
					if(grid[x+1][y] == '.'){
						q.add(x+1);
						q.add(y);
					}
				vis[x+1][y]= true;
				if(x + 1 == r2 && y == c2)
					reached = true;
			}
			
			if(y+1<m && vis[x][y+1] == false){
					if(grid[x][y+1] == '.'){
						q.add(x);
						q.add(y+1);
					}
				vis[x][y+1] = true;
				if(x == r2 && y + 1 == c2)
					reached = true;
			}
			
		}
		
		w.println(reached ? "YES" : "NO");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}