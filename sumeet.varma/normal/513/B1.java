import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class B1 {

	static int max;
	static int counter = 0;
	
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
	    
	    max = 0;
	    boolean vis[] = new boolean[n+1];
	    int curr[] = new int[n];
	    findMax(0,n,vis,curr);
	    
	    findmth(0,n,vis,curr,m);
	    
	    w.close(); 
	}
	
	public static void findMax(int i,int n,boolean vis[],int curr[]){
		if(i==n){
			int fp = 0;
			for(int k=0;k<n;k++){
				int cm = curr[k];
				for(int j=k;j<n;j++){
					cm = Math.min(cm,curr[j]);
					fp += cm;
				}
			}
			max =Math.max(max, fp);
			return;
		}
		
		for(int k=1;k<=n;k++){
			if(vis[k] == false){
				curr[i] = k;
				vis[k] = true;
				findMax(i+1,n,vis,curr);
				vis[k] = false;
			}
		}
	}
	
	public static void findmth(int i,int n,boolean vis[],int curr[],int m){
		if(i==n){
			int fp = 0;
			for(int k=0;k<n;k++){
				int cm = curr[k];
				for(int j=k;j<n;j++){
					cm = Math.min(cm,curr[j]);
					fp += cm;
				}
			}
			if(fp == max){
				counter++;
				if(counter == m){
					for(int k=0;k<n;k++)
						System.out.print(curr[k] + " ");
					System.out.println();
				}
			}
			return;
		}
		
		for(int k=1;k<=n;k++){
			if(vis[k] == false){
				curr[i] = k;
				vis[k] = true;
				findmth(i+1,n,vis,curr,m);
				vis[k] = false;
			}
		}
	}
	
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}