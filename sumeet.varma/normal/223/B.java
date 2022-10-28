import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class R138qBTwoStrings {
	
	static ArrayList<Integer> occur[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    int n = s.length;
	    
		occur = new ArrayList[26];    
	    for(int i=0;i<26;i++)
	    	occur[i] = new ArrayList<Integer>();
	    
	    for(int i=0;i<n;i++)
	    	occur[s[i]-'a'].add(i);
	    
	    char t[] = br.readLine().toCharArray();
	    int m = t.length;
	    int first[] = new int[m];
	    
	    int j = 0;
	    for(int i=0;i<n && j<m;i++){
	    	if(t[j] == s[i]){
	    		first[j] = i;
	    		j++;
	    	}
	    }
	    
	    if(j != m){
	    	System.out.println("No");
	    	return;
	    }
	  
	    
	   // System.out.println(Arrays.toString(first));
	    int next = n;
	    
	    boolean nice[] = new boolean[n];
	    
	    for(int i=m-1;i>=0;i--){
	    	int last = binarySearchLast(t[i]-'a',next);
	    	int get = Collections.binarySearch(occur[t[i]-'a'], first[i]);
	    	for(int k=get;k<=last;k++){
	    		if(!nice[occur[t[i]-'a'].get(k)])
	    			nice[occur[t[i]-'a'].get(k)] = true;
	    		else
	    			break;
	    	}
	    	next = occur[t[i]-'a'].get(last);
	    }
	    
	    //System.out.println(Arrays.toString(nice));
	    
	    for(boolean x : nice)
	    	if(!x){
	    		System.out.println("No");
	    		return;
	    	}
	    
	    System.out.println("Yes");
	    
	    w.close(); 
	}
	
	public static int binarySearchLast(int id,int limit){
		int ret = -1;
		int start = 0,end = occur[id].size();
		while(start < end){
			int m = (start + end) >> 1;
			if(occur[id].get(m) < limit){
				ret = m;
				start = m + 1;
			}
			else
				end=  m;
		}
		return ret;
	}
	
}