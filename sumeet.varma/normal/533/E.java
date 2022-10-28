import java.io.*;
import java.util.*;

public class VKR2RaskB {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    char a[] = br.readLine().toCharArray();
	    char b[] = br.readLine().toCharArray();    
	    
	    int hasha[] = new int[26];
	    int hashb[] = new int[26];
	    
	    for(int i=0;i<n;i++){
	    	hasha[a[i] - 'a']++;
	    	hashb[b[i] - 'a']++;
	    }
	    
	    int hashans[] = new int[26];
	    for(int i=0;i<26;i++)
	    	hashans[i] = Math.max(hasha[i],hashb[i]);
	    
	    int total = 0;
	    for(int i : hashans)
	    	total += i;
	    
	    if(total >(n+1)){
	    	System.out.println("0");
	    	return;
	    }
	    
	    else{
	    	int diff = 0;
	    	for(int i=0;i<n;i++)
	    		if(a[i] != b[i])
	    			diff++;
	    	if(diff == 1){
	    		System.out.println("2");
	    		return;
	    	}
	    	int i1 = -1,i2 = -1;
	    	for(int i=0;i<n;i++){
	    		if(a[i] != b[i]){
	    			if(i1 == -1)
	    				i1 = i;
	    			else
	    				i2 = i;
	    		}
	    	}
	    	
	    	if(i2 == i1 + 1){
	    		int ans = 0;
	    		if(a[i1] == b[i2])
	    			ans++;
	    		if(a[i2] == b[i1])
	    			ans++;
	    		System.out.println(ans);
	    		return;
	    	}
	    	
	    	StringBuilder a1 = new StringBuilder();
	    	StringBuilder a2 = new StringBuilder();
	    	StringBuilder b1 = new StringBuilder();
	    	StringBuilder b2 = new StringBuilder();
	    	
	    	for(int i=i1;i<i2;i++)
	    		a1.append(a[i]);
	    	for(int i=i1+1;i<=i2;i++)
	    		a2.append(a[i]);
	    	
	    	for(int i=i1;i<i2;i++)
	    		b1.append(b[i]);
	    	for(int i=i1+1;i<=i2;i++)
	    		b2.append(b[i]);
	    	
	    	
	    	int ans = 0;
	    	if(a1.toString().equals(b2.toString()))
	    		ans++;
	    	if(a2.toString().equals(b1.toString()))
	    		ans++;
	    	
	    	System.out.println(ans);
	    	return;
	    } 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}