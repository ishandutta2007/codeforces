import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class R258D2TaskDCountGoodSubstrings {

	public static void main(String args[] ) throws Exception {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    char a[] = br.readLine().toCharArray();
	    int n = a.length;
	    
	    char merged[] = new char[n];
	    int counts[] = new int[n];
	    int j = -1;
	    char prev = 'C';
	    
	    for(int i=0;i<n;i++){
	    	if(a[i] != prev){
	    		j++;
	    		merged[j] = a[i];
	    		counts[j] = 1;
	    		prev = a[i];
	    	}
	    	else
	    		counts[j]++;
	    }
	    
	    long odd = 0,even = 0;
	    long addBEven = 0,addBOdd = 0;
	    long addAEven = 0,addAOdd = 0;
	    
	    for(int i=0;i<=j;i++){
	    	
	    	long thisEven = counts[i]/2;
	    	long thisOdd = counts[i] - thisEven;
	    	
		    long onlyThisEven = 0,onlyThisOdd = 0;
	    	for(int x=1;x<=counts[i];x++){
	    		if(x % 2 == 0)
	    			onlyThisEven += (counts[i] - x +1);
	    		else
	    			onlyThisOdd += (counts[i]- x + 1);
	    	}
	    	odd += onlyThisOdd;
	    	even += onlyThisEven;
	    	
	    	if(merged[i] == 'b'){
	    		odd += addBOdd*(thisEven);
	    		odd += addBEven*(thisOdd);
	    		even += addBOdd*(thisOdd);
	    		even += addBEven*(thisEven);
	    		if(counts[i] % 2 != 0){
	    			long t = addBOdd;
	    			addBOdd = addBEven;
	    			addBEven = t;
	    			t = addAOdd;
	    			addAOdd = addAEven;
	    			addAEven = t;
	    		}
	    		addBOdd += thisOdd;
	    		addBEven += thisEven;
	    	}
	    	else{
	    		odd += addAOdd*(thisEven);
	    		odd += addAEven*(thisOdd);
	    		even += addAOdd*(thisOdd);
	    		even += addAEven*(thisEven);
	    		if(counts[i] % 2 != 0){
	    			long t = addAOdd;
	    			addAOdd = addAEven;
	    			addAEven = t;
	    			t = addBOdd;
	    			addBOdd = addBEven;
	    			addBEven = t;
	    		}
	    		addAOdd += thisOdd;
	    		addAEven += thisEven;
	    	}
	    	
	    	//System.out.println(counts[i] + " " +thisOdd + " " + thisEven);
	    	//System.out.println(addBOdd + " " + addBEven + " " + addAOdd + " " + addAEven + " " + odd + " " + even);
	    }
    	
    	
    	
	    
	    w.println(even + " " + odd);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}