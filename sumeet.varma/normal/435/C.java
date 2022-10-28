import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;

public class R249QCCardiogram {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    int miny = 0;
	    int maxy = 0;
	    
	    int y = 0,x=0;
	    for(int i=0;i<n;i++){
	    	if(i % 2 == 0)
	    		y += a[i];
	    	else
	    		y -= a[i];
	    	x += a[i];
	    	miny = Math.min(miny,y);
	    	maxy = Math.max(maxy,y);
	    }
	    int yrange = maxy - miny;
	    
	    char ans[][] = new char[2001][2001];
	    int g=0,h=1000;
	    for(int i=0;i<n;i++){
	    	if(i % 2 == 0){
	    		for(int j=0;j<a[i];j++)
	    			ans[h++][g++] = '/';
	    		h--;
	    	}
	    	else{
	    		for(int j=0;j<a[i];j++)
	    			ans[h--][g++] = '\\';
	    		h++;
	    	}
	    }
	    
	    for(int i=1000+maxy-1;i>=1000+miny;i--){
	    	for(int j=0;j<x;j++)
	    		w.print(ans[i][j] == 0 ? ' ' : ans[i][j]);
	    	w.println();
	    }
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}