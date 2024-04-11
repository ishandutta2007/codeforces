import java.io.*;
import java.util.*;

public class LsryQB {
	
	static long a,b,c,d;

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    a = ip(st1.nextToken());
		b = ip(st1.nextToken());
	   
		 StringTokenizer st2 = new StringTokenizer(br.readLine());
	    c = ip(st2.nextToken());
	    d = ip(st2.nextToken());
		
		if(a*d == b*c){
			System.out.println("0");
			return;
		}
	    
		if(a*d > b*c){
			long t = a;
			a = b;
			b = t;
			t = c;
			c = d;
			d = t;
		}
		
		double ret = -1;
		double start = 0;
		double end = Integer.MAX_VALUE;
		double eps = 1e-15;
		
		for(int it=0;it<=60;it++){
			double mid = (start + end)/ 2;
			double lhs = inc(a,d,mid);
			double rhs = dec(b,c,mid);
			double now = lhs - rhs;
			if(now >= 0)
				ret = end = mid;
			else
				start = mid;
		}
	
		w.println(ret);
	    w.close(); 
	}
	
	public static double inc(double a,double b,double offset){
		double t[] = new double[9];
		t[0] = (a + offset)*(b+offset);
		t[1] = (a + offset)*(b-offset);
		t[2] = (a - offset)*(b+offset);
		t[3] = (a - offset)*(b-offset);
		t[4] = (a - offset)*b;
		t[5] = (a + offset)*b;
		t[6] = a*(b - offset);
		t[7] = a*(b + offset);
		t[8] = a*b;
		double max = Double.NEGATIVE_INFINITY;
		for(double x : t)
			max = Math.max(max, x);
		return max;
	}
	
	public static double dec(double a,double b,double offset){
		double t[] = new double[9];
		t[0] = (a + offset)*(b+offset);
		t[1] = (a + offset)*(b-offset);
		t[2] = (a - offset)*(b+offset);
		t[3] = (a - offset)*(b-offset);
		t[4] = (a - offset)*b;
		t[5] = (a + offset)*b;
		t[6] = a*(b - offset);
		t[7] = a*(b + offset);
		t[8] = a*b;
		double min = Double.POSITIVE_INFINITY;
		for(double x : t)
			min = Math.min(min, x);
		return min;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}