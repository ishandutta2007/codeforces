import java.io.*;
import java.util.*;

public class LsryQA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    
		int dx[] = new int[]{0,0,1,1};
		int dy[] = new int[]{0,1,0,1};
		
		char s[][] = new char[n][m];
	        
		for(int i=0;i<n;i++)
			s[i] = br.readLine().toCharArray();
		
		int ans = 0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m-1;j++){
				boolean f = false;
				boolean a = false;
				boolean c = false;
				boolean e = false;
				for(int k=0;k<4;k++){
					char t = s[i + dx[k]][j + dy[k]];
					if(t == 'f')	f = true;
					if(t == 'a')   a = true;
					if(t == 'c') c = true;
					if(t == 'e') e = true;
 				}
				if(f & a & c & e)
					ans++;
			}
		}
	    
		w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}