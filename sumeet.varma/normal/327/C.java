import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R191qCMagicFive {

	static long mod = (long)(1e9 + 7);
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char a[] = br.readLine().toCharArray();
	    long k = ip(br.readLine());
	    int n = a.length;
	    
	    long ans = 0;
	    
	    for(int i=0;i<n;i++){
	    	if(a[i] == '5' || a[i] == '0'){
	    		ans += pow2(i);
	    		if(ans >= mod)	ans %= mod;
	    	}
	    }
	
	    ans *= (pow2(n*k) - 1) % mod;
	    ans %= mod;
	    long t = (pow2(n) - 1) % mod;
	    ans *= InverseEuler(t,mod) % mod;
	    ans %= mod;
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static long pow2(long b){
		if(b == 0)	return 1;
		if(b == 1)	return 2;
		long t = pow2(b/2);
		t = (t * t);
		if((b & 1) == 1)	t = (t * 2);
		if(t >= mod)	t %= mod;
		return t;
	}
	
	public static long pow(long a, long b, long MOD){
	    long x=1,y=a;
	    while(b > 0)
	    {
	        if(b%2 == 1)
	        {
	            x=(x*y);
	            if(x>MOD) x%=MOD;
	        }
	        y = (y*y);
	        if(y>MOD) y%=MOD;
	        b /= 2;
	    }
	    return x;
	}

	public static long InverseEuler(long n, long MOD){
	    return pow(n,MOD-2,MOD);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}