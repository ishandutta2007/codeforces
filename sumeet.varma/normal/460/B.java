import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Collections;

public class R262D2TaskBLittleDimaAndEquation {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long a = ip(st1.nextToken());
		long b = ip(st1.nextToken());
	    long c = ip(st1.nextToken()); 
	   
	    ArrayList<Long> ans = new ArrayList<Long>();
	         
	    for(int i=1;i<=81;i++){
	    	long num = 1;
	    	for(int j=0;j<a;j++)
	    		num *= i;
	    	if(b*num + c > 0 && b*num + c < 1000000000 && total(b*num+c)==i)
	    		ans.add(b*num + c);
	    	//System.out.println((b*num + c) + " " + i);
	    }
	    
	    Collections.sort(ans);
	    w.println(ans.size());
	    for(int i=0;i<ans.size();i++)
	    	w.print(ans.get(i) + " ");
	    
	    w.close(); 
	}
	
	public static int total(long x){
		char a[] = Long.toString(x).toCharArray();
		int ans = 0;
		for(int i=0;i<a.length;i++)
			ans += Character.getNumericValue(a[i]);
		return ans;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}