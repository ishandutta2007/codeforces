import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R246QCPrimeSwaps {
	
	static int prime[];
	static int a[],p[];
	static int n;
	static ArrayList<Integer> swaps;
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    boolean primes[] = sieve(100010);
	    prime = new int[9592];
	    for(int i=0,j=0;i<=100000;i++)
	    	if(primes[i])
	    		prime[j++] = i;
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    p = new int[n];
	    for(int i=0;i<n;i++){
	    	int v = ip(st2.nextToken()) - 1;
	    	p[v] = i;
	    	a[i] = v;
	    }
	    
	    swaps = new ArrayList<Integer>();
	    
	    for(int i=0;i<n;i++){
	    	while(p[i] != i){
	    		int index = p[i] + 1 - bSLast(p[i] - i + 1);
	    		swap(p[i],index);
	    	}
	    }
	    
	    w.println(swaps.size()/2);
	    int s = swaps.size();
	    for(int i=0;i<s;){
	    	w.print(swaps.get(i++) + " ");
	    	w.println(swaps.get(i++));
	    }
	    
	    w.close(); 
	}
	
	public static int bSLast(int key){
		int start = 0,end = prime.length;
		int ret = -1;
		while(true){
			if(end == start)	return ret;
			int mid = (end + start)/2;
			if(prime[mid] <= key)	ret = prime[mid];
			if(end - start == 1)	return ret;
			if(prime[mid] <= key)	start = mid + 1;
			else	end = mid;
		}
	}
	
	public static void swap(int i,int j){
		int vi = a[i];
		int vj = a[j];
		p[vi] = j;
		p[vj] = i;
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
		if(i < j){
			swaps.add(i+1);
			swaps.add(j+1);
		}
		else{
			swaps.add(j+1);
			swaps.add(i+1);
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static boolean[] sieve(int n){//O(n)
		boolean prime[] = new boolean[n+1];
		Arrays.fill(prime,true);//assume all are prime except 0 and 0
		prime[0] = prime[1] = false;
		
		int m = (int) Math.sqrt(n);
		
		//going only till square root because for n if it had to have a factor it should have been before sqrt(n)//it cant have independent factors later
		
		for(int i=2;i<=m;i++)
			if(prime[i]) //if i is prime then make its multiples unprime
				for(int k=i*i;k<=n;k+=i) //multiples of i till i*i would already be unprime...so starting from i*i because such numbers would be i*j where j=2 to i-1 and they would already have been marked by those numbers
					prime[k] = false;
		
		return prime;
	}
}