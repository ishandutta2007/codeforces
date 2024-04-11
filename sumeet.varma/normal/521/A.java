import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Round295Div1TaskA {
	
	static int n;
	static char a[];
	static int max;
	static boolean pr;
	static int ans2;
	
	public static void main(String args[] ) throws Exception {
		
		long m = (long) 1e9 + 7;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	  
	    a = br.readLine().toCharArray();
	    
	    int h[] = new int[26];
	    for(int i=0;i<n;i++)
	    	h[a[i]-'A']++;
	         
	    int mc = 0;
	    
	    for(int i=0;i<26;i++)
	    	mc = Math.max(mc,h[i]);
	    
	    for(int i=0;i<26;i++){
	    	if(h[i]< mc)
	    		h[i] = 0;
	    }
	   
	    int count=0;
	    for(int i=0;i<26;i++)
	    	if(h[i]>0)	count++;
		    
		long ans = 1;
	    for(int i=1;i<=n;i++){
	    	ans = (ans * count) % m;
	    }
		    
	    w.println(ans);
	    
	    /*
	    ans2 = 0;
	    max = 0;
	    pr = false;
	    solve(a);
	    
	    System.out.println("MAX :" + max);
	    
	    pr = true;
	    solve(a);
	        
	    System.out.println(ans2);*/
	    w.close(); 
	}
	
	public static void solve(char[] a){
		char b[] = new char[n];
		solve2(b,0);
	}
	
	public static void solve2(char[] b,int i){
		if(i == n){
			countp(a,b);
			return;
		}
		for(int j=0;j<26;j++){
			b[i] = (char)('A'+j);
			solve2(b,i+1);
		}
	}
	
	public static void countp(char a[],char b[]){
		int c = 0;
		
		char ta[] = a.clone();
		char tb[] = b.clone();
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				c += counth(ta,tb);
				shift(tb);
			}
			shift(ta);
		}
	
		if(!pr){
			max = Math.max(max,c);
			//print(b);
			//System.out.println(c);
		}
		else{
			if(c == max){
				//print(b);
				ans2++;
			}
		}
	
	}
	
	public static void shift(char c[]){
		char d[] = c.clone();
		for(int i=0;i<n-1;i++)
			c[i] = d[i+1];
		c[n-1] = d[0];
	}
	
	public static int counth(char[] a,char[] b){
		int c = 0;
		for(int i=0;i<a.length;i++)
			if(a[i] == b[i])	c++;
		return c;
	}
	
	public static void print(char b[]){
		for(int i=0;i<n;i++)
			System.out.print(b[i]);
		System.out.println();
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}