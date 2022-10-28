import java.awt.geom.AffineTransform;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class CaptionMarmot {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    for(int t=0;t<n;t++){
	    	
	    	int x[] = new int[4];
	    	int y[] = new int[4];
	    	int a[] = new int[4];
	    	int b[] = new int[4];
	    	
	    	for(int i=0;i<4;i++){
	    		StringTokenizer st2 = new StringTokenizer(br.readLine());
	    		x[i] = ip(st2.nextToken());
	    		y[i] = ip(st2.nextToken());
	    		a[i] = ip(st2.nextToken());
	    		b[i] = ip(st2.nextToken());
	    	}
	    	
	    	int ans = 1000;
	    	
	    	
	    	
	    	for(int i=0;i<4;i++){
	    		for(int j=0;j<4;j++){
	    			for(int k=0;k<4;k++){
	    				for(int l=0;l<4;l++){
	    					
	    					int xx[] = new int[4];
	    					int yy[] = new int[4];
	    					for(int f=0;f<4;f++){
	    						xx[f] = x[f];
	    						yy[f] = y[f];
	    					}
	    					
	    			    	make(xx,yy,a[0],b[0],i,0);
	    			    	make(xx,yy,a[1],b[1],j,1);
	    			    	make(xx,yy,a[2],b[2],k,2);
	    			    	make(xx,yy,a[3],b[3],l,3);
	    			    	
	    			    	if(check(xx,yy) && isSquare(xx,yy))
	    			    		ans = Math.min(ans, i+j+k+l);
	  
	    				}
	    			}
	    		}
	    	}
	    	w.println(ans == 1000 ? -1 : ans);
	    }
	    
	    w.close(); 
	}
	
	
	private static boolean check(int[] xx, int[] yy) {
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				if(xx[i] == xx[j] && yy[i] == yy[j])
					return false;
			}
		}
		return true;
	}


	private static void make(int[] x, int[] y, int a, int b, int rots,int pos) {
		
		int newx = x[pos] - a;
		int newy = y[pos] - b;
		
		if(rots == 1){
			int t = newx;
			newx = newy;
			newy = t;
			newx *= -1;
		}
		
		if(rots == 2){
			newx *= -1;
			newy *= -1;
		}
		
		if(rots == 3){
			int t = newx;
			newx = newy;
			newy = t;
			newy *= -1;
		}
		
		x[pos] = newx + a;
		y[pos] = newy + b;
		
	}
	
	private static boolean isSquare(int x[],int y[])
	{
	    int d2 = distSq(x[0],y[0],x[1],y[1]);  // from p1 to p2
	    int d3 = distSq(x[0],y[0],x[2],y[2]);  // from p1 to p3
	    int d4 = distSq(x[0],y[0],x[3],y[3]);  // from p1 to p4
	 
	    // If lengths if (p1, p2) and (p1, p3) are same, then
	    // following conditions must met to form a square.
	    // 1) Square of length of (p1, p4) is same as twice
	    //    the square of (p1, p2)
	    // 2) p4 is at same distance from p2 and p3
	    if (d2 == d3 && 2*d2 == d4)
	    {
	        int d = distSq(x[1],y[1],x[3],y[3]);
	        return (d == distSq(x[2],y[2],x[3],y[3]) && d == d2);
	    }
	 
	    // The below two cases are similar to above case
	    if (d3 == d4 && 2*d3 == d2)
	    {
	        int d = distSq(x[1],y[1],x[2],y[2]);
	        return (d == distSq(x[1],y[1],x[3],y[3]) && d == d3);
	    }
	    if (d2 == d4 && 2*d2 == d3)
	    {
	        int d = distSq(x[1],y[1],x[2],y[2]);
	        return (d == distSq(x[2],y[2],x[3],y[3]) && d == d2);
	    }
	 
	    return false;
	}
	
	private static int distSq(int x,int y,int a,int b){
		return (x-a)*(x-a) + (y-b)*(y-b);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}