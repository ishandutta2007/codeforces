import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Round274Div1Exams {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	   
	    Ex e[] = new Ex[n];
	   
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	e[i] = new Ex(ip(st2.nextToken()),ip(st2.nextToken()));
	    }
	    
	    int prev = 0;
	    Arrays.sort(e);
	    
	    for(int i=0;i<n;i++){
	    	if(e[i].b >= prev)
	    		prev = e[i].b;
	   		else if(e[i].a >= prev)
	   			prev = e[i].a;
	    }
	    
	    w.println(prev);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Ex implements Comparable<Ex>{
	int a,b;
	Ex(int i,int j){
		a = i;
		b = j;
	}
	public int compareTo(Ex e2){
		if(a < e2.a)	return -1;
		if(a > e2.a)	return 1;
		if(b < e2.b)	return -1;
		if(b > e2.b)	return 1;
		return 0;
	}
}