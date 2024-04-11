import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class G1 {

	static int inv = 0;
	static int K,n;
	
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	    K = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    solve(a,0);
	   
	    double ans = inv;
	    long den =(long)Math.pow(n*(n+1)/2,K);
	    ans = ans/den;
	    w.println(ans);
	    w.close(); 
	}
	
	public static void solve(int[] a,int k){
		if(k==K){
			for(int i=0;i<a.length;i++)
				for(int j=i+1;j<a.length;j++)
					if(a[i]>a[j])
						inv++;
			return;
		}
		
		for(int i=0;i<a.length;i++){
			for(int j=i;j<a.length;j++){
				int temp[] = new int[n];
				for(int l=0;l<i;l++)
					temp[l] = a[l];
				for(int l=i;l<=j;l++)
					temp[j-l+i]= a[l];
				for(int l=j+1;l<n;l++)
					temp[l] = a[l];
				solve(temp,k+1);
			}
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}