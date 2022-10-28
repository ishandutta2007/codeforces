import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class ArthurAndQuestions {

	static int n,k;
	static String a[];
	static long ans[];
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		k = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new String[n];
	    for(int i=0;i<n;i++)
	    	a[i] = st2.nextToken();
	         
	    ans = new long[n];
	    
	    for(int i=0;i<k;i++)
	    	solve(i);
	    
	    boolean correct = true;
	    
	    long sum = 0;
	    for(int i=0;i<k;i++)
	    	sum += ans[i];
	    
	    for(int i=k;i<n;i++){
	    	long newSum = sum + ans[i] - ans[i-k];
	    	if(newSum <= sum)
	    		correct = false;
	    	sum = newSum;
	    }
	    		
	    if(correct){
	    	for(int i=0;i<n;i++)
	    		w.print(ans[i] + " ");
	    	w.println();
	    }
	    else
	    	w.println("Incorrect sequence");
	    
	    w.close(); 
	}
	
	public static void solve(int start){
		ArrayList<String> temp = new ArrayList<String>();
		
		for(int i=start;i<n;i+=k)
			temp.add(a[i]);
		
		//System.out.println("start : " + start + " " + temp );
		
		long lB = -111111111;
		int s = temp.size(), count = 0;
		long thisAns[] = new long[s+1];
		
		for(int i=0;i<=s;i++){
			if(i == s || !temp.get(i).equals("?")){
				long rB;
				if(i == s)
					rB = 111111111;
				else
					rB = ip(temp.get(i));
				thisAns[i] = rB;
				
				if(lB < 0 && rB < 0)
					for(int j=i-1,c=0;c<count;c++,j--)
						thisAns[j] = thisAns[j+1] - 1;
				
				if(lB >= 0 && rB >= 0)
					for(int j=i-count;j<i;j++)
						thisAns[j] = ++lB;
				
				if(lB <0 && rB >= 0){
					int found = 0;
    				long pc = 0,nc = -1;
    				while(found < count){
    					if(Math.abs(pc) < Math.abs(nc)){
    						if(pc < rB)
    							pc++;
    						else
    							nc--;
    					}
    					else{
    						if(nc > lB)
    							nc--;
    						else
    							pc++;
    					}
    					found++;
    				}
    				
    				for(int f=i-count;f<i;f++)
    					thisAns[f] = ++nc;
				}
				
				count = 0;
				lB = rB;
			}
			else
				count++;
		}
		
		//System.out.println(Arrays.toString(thisAns));
		
		for(int i=start,j=0;j<s;j++,i+=k)
			ans[i] = thisAns[j];
	}
	
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}