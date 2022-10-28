import java.io.*;
import java.util.*;

public class R239qCTriangle {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int a = ip(st1.nextToken());
		int b = ip(st1.nextToken());
	          
		for(int i=-1000;i<=1000;i++){
			for(int j=-1000;j<=1000;j++){
				if(i*i + j*j == a*a && i!=0 && j!=0){
					double mb = -1.0 * i / j;
					int p3x = (int)( b * (1.0 / Math.sqrt(1 + mb*mb)));
					int p3y = (int) (b * (mb * 1.0 / Math.sqrt(1 + mb*mb)));
					if(p3x*p3x + p3y*p3y == b*b){
						if(p3x == i || p3y == j)
							;
						else{
							w.println("YES");
							w.println("0 0");
							w.println(i + " " + j);
							w.println(p3x + " " + p3y);
							w.close();
							return;
						}
					}
					p3x *= -1;
					p3y *= -1;
					if(p3x*p3x + p3x*p3y == b*b && (p3y - j)*(p3y - j) + (p3x - i)*(p3x - i) == a*a + b*b){
						if(p3x == i || p3y == j)
							;
						else{
							w.println("YES");
							w.println("0 0");
							w.println(i + " " + j);
							w.println(p3x + " " + p3y);
							w.close();
							return;
						}
					}
					
					p3x = (int)Math.ceil( b * (1.0 / Math.sqrt(1 + mb*mb)));
					p3y = (int)Math.ceil(b * (mb * 1.0 / Math.sqrt(1 + mb*mb)));
					if(p3x*p3x + p3x*p3y == b*b && (p3y - j)*(p3y - j) + (p3x - i)*(p3x - i) == a*a + b*b){
						if(p3x == i || p3y == j)
							;
						else{
							w.println("YES");
							w.println("0 0");
							w.println(i + " " + j);
							w.println(p3x + " " + p3y);
							w.close();
							return;
						}
					}

					
					p3x *= -1;
					p3y *= -1;
					if(p3x*p3x + p3x*p3y == b*b && (p3y - j)*(p3y - j) + (p3x - i)*(p3x - i) == a*a + b*b){
						if(p3x == i || p3y == j)
							;
						else{
							w.println("YES");
							w.println("0 0");
							w.println(i + " " + j);
							w.println(p3x + " " + p3y);
							w.close();
							return;
						}
					}

					
				}
			}
		}
		
	    w.println("NO");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}