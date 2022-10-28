import java.io.*;
import java.util.*;


public class R280D2TaskCVanyaAndexams {

	public static void main(String args[] ) throws Exception {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		    PrintWriter w = new PrintWriter(System.out);
		        
		    StringTokenizer st1 = new StringTokenizer(br.readLine());
		    int n = ip(st1.nextToken());
		    long r = ip(st1.nextToken());
		    long avg = ip(st1.nextToken());
		    long needed = avg*n;
		    
		    long tot = 0;
		    Sub s[] = new Sub[n];
		    for(int i=0;i<n;i++){
			    StringTokenizer st2 = new StringTokenizer(br.readLine());
			   	s[i] = new Sub(ip(st2.nextToken()),ip(st2.nextToken()));
			   	tot += s[i].g;
		    }     
		    
		    if(tot >= needed){
		    	System.out.println("0");
		    	return;
		    }
		    
		    Arrays.sort(s);
		    long essays = 0;
		    
		    for(int i=0;i<n;i++){
		    	long diff = needed-tot;
		    	if(diff >= (r-s[i].g)){
		    		essays += (r-s[i].g)*s[i].e;
		    		tot += r-s[i].g;
		    	}
		    	if(tot >= needed)
		    		break;
		    	if(diff < (r-s[i].g)){
		    		essays += (diff)*s[i].e;
		    		break;
		    	}
		    }
		    
		    w.println(essays);
		    w.close(); 
		}

		public static int ip(String s) {
			return Integer.parseInt(s);
		}
	}


	class Sub implements Comparable<Sub> {
		long g, e;

		Sub(int g, int e) {
			this.g = g;
			this.e = e;
		}

		public int compareTo(Sub arg0) {
			if (e < arg0.e)
				return -1;
			if (e > arg0.e)
				return 1;
			return 0;
		}

	}