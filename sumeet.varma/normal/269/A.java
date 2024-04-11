import java.io.*;
import java.util.*;
public class R165qC {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    Pair p[] = new Pair[n];
	    for(int i=0;i<n;i++){
		    StringTokenizer st2 = new StringTokenizer(br.readLine());
		    p[i] = new Pair(ip(st2.nextToken()),ip(st2.nextToken()));
	    }
	    
	    Arrays.sort(p);
	    
	    int leftK = p[0].k,leftC = p[0].a;
	    
	    for(int i=1;i<n;i++){
	    	int diff = p[i].k - leftK;
	    	long t = 1;
	    	for(int j = 0;j < diff;j++){
	    		t = t * 4;
	    		if(t >= leftC)
	    			break;
	    	}
	    	if(t >= leftC || t*p[i].a >= leftC){
	    		leftK = p[i].k;
	    		leftC = p[i].a;
	    	}
	    	else{
	    		long left = leftC - t * p[i].a;
	    		leftK = p[i].k;
	    		leftC = p[i].a + (int)Math.ceil(left*1.0/t);
	    	}
	    }
	    
	    long ans = p[n-1].k + 1;
	    long can = 4;
	    while(can < leftC){
	    	ans++;
	    	can *= 4;
	    }

	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Pair implements Comparable<Pair>{
	int k,a;
	Pair(int k,int a){
		this.k = k;
		this.a = a;
	}
	@Override
	public int compareTo(Pair arg0) {
		return k - arg0.k;
	}
	
}