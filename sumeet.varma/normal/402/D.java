import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.HashMap;
import java.util.StringTokenizer;


public class R236qDUpgradingArray {

	static int n,m;
	static int a[];
	static HashSet<Integer> bad;
	static HashMap<Integer,Integer> beauty;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    bad = new HashSet<Integer>();
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    for(int i=0;i<m;i++)
	    	bad.add(ip(st3.nextToken()));
	    
	    beauty = new HashMap<Integer,Integer>();
	    
	    int gcd[] = new int[n];
	    for(int i=0;i<n;i++)
	    	gcd[i] = (i == 0) ? a[0] : gcd(gcd[i-1],a[i]);
	    
	    	
	    int ans = 0,g = 1;
	    
	    for(int i=n-1;i>=0;i--){
	    	int now = gcd[i]/g;
	    	int b = getBeauty(now);
	    	a[i] /= g;
	    	if(b < 0){
	    		a[i] /= now;
	    		g *= now;
	    	}
	    	ans += getBeauty(a[i]);
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int getBeauty(int x){
		if(beauty.containsKey(x))	return beauty.get(x);
	
		int ret = 0,c = 0,o,orig = x;
	
		while(x != 0 && (x & 1) == 0){
			x = x >> 1;
	    	c++;
		}
		if(bad.contains(2))	ret -= c;	else  ret += c;
		
		for(int d=3;d*d<=x;d+=2){
			c = 0;
			while(x != 0){
				o = x/d;
				if(o*d == x){
					c++;
					x = o;
				}
				else
					break;
			}
			if(bad.contains(d))	ret -= c;	else	ret += c;
		}
		
		if(x > 1)	
			ret += bad.contains(x) ? -1 : 1;
		
		beauty.put(orig, ret);
		
		return ret;
	}
	
	public static int gcd(int a,int b){
		int t;
		while(b != 0){
			t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}