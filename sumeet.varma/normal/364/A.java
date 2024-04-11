import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R213qCMatrix {
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	 
	    int a = ip(br.readLine());
	    char soSad[] = br.readLine().toCharArray();
	    int n = soSad.length;
	    int s[] = new int[n];
	    for(int i=0;i<n;i++)
	    	s[i] = soSad[i] - '0';
	    
	    int hash[] = new int[40001];
	    
	    for(int i=0;i<n;i++){
	    	int sum = 0;
	    	for(int j=i;j<n;j++){
	    		sum += s[j];
	    		hash[sum]++;
	    	}
	    }
	    
	    int temp;
	    long ans = 0;
	    
	    for(int i=0;i<n;i++){
	    	int sum = 0;
	    	for(int j=i;j<n;j++){
	    		sum += s[j];
	    		if(sum == 0){
	    			if(a == 0)	ans += n*(n+1)/2;
	    		}
	    		else{
	    			temp = a/sum;
	    			if(temp * sum == a && temp<= 40000)
	    				ans += hash[temp];
	    		}
	    	}
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}