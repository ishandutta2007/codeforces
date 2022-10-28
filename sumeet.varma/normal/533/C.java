import java.io.*;
import java.util.*;

public class VKR2TaskA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	  
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int xp = ip(st2.nextToken());
	    int yp = ip(st2.nextToken());
	    int xv = ip(st2.nextToken());
	    int yv = ip(st2.nextToken());
	    
	    int mp = xp + yp;
	    int mv = Math.max(xv,yv);
	    
	    if(mp <= mv){
	    	System.out.println("Polycarp");
	    	return;
	    }
	    
	    boolean canCollide = false;
	    
	    int y = yv;
	    int x = xv;
	    int count = 0;
	    //leftFirst
	    while(true){
	    	count++;
	    	if(x -1 >= 0 && y-1 >= 0){
	    		x--;
	    		y--;
	    	}
	    	else if(x - 1 >= 0)
	    		x--;
	    	else
	    		y--;
	    	if(x <= xp && y <= yp){
	    		int count2 = xp - x + yp - y;
	    		if(count2 <= count){
	    			canCollide = true;
	    			break;
	    		}
	    	}
	    	if(x == 0 && y == 0)
	    		break;
	    	//System.out.println(x + " " + y);
	    }
	    
	    w.println(canCollide ? "Polycarp" : "Vasiliy");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}