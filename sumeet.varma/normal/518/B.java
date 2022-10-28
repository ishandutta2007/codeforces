import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class Round293TaskB {

	public static void main(String args[] ) throws Exception {
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    char t[] = br.readLine().toCharArray();
	   
	    int ss[] = new int[26];
	    int sc[] = new int[26];
	    int ts[] = new int[26];
	    int tc[] = new int[26];
	    
	    for(int i=0;i<s.length;i++){
	    	if(s[i] >= 'a')
	    		ss[s[i]-'a']++;
	    	else
	    		sc[s[i]-'A']++;
	    }
	    
	    for(int i=0;i<t.length;i++){
	    	if(t[i] >= 'a')
	    		ts[t[i]-'a']++;
	    	else
	    		tc[t[i]-'A']++;
	    }
	    
	    int ans1 = 0,ans2 = 0;
	    for(int i=0;i<26;i++){
	    	int lc = Math.min(ss[i],ts[i]);
	    	int uc = Math.min(sc[i],tc[i]);
	    	ans1 +=  lc + uc;
	    	ans2 += Math.min((ss[i]-lc),tc[i]-uc);
	    	ans2 += Math.min(sc[i]-uc,ts[i]-lc);
	    }
	    
	    w.println(ans1 + " " + ans2 );
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}