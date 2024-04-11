import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;



public class R306qD {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	 
	    int k = Integer.parseInt(br.readLine());
	    
	    /*if(k == 1){
	    	System.out.println("YES");
	    	System.out.println("1 2");
	    	System.out.println("2 1");
	    	return;
	    }*/
	    
	    if(k % 2 == 0){
	    	System.out.println("NO");
	    	return;
	    }
	    
	    w.println("YES");
	    
	    int n = 4*(k - 1) + 2;
	    int count = 0;
	    
	    boolean edge[][] = new boolean[n + 1][n + 1];
	    
	    edge[2*k - 1][2*k] = edge[2*k][2*k - 1] = true;
	    count++;
	    
	    for(int i=1;i<=k-1;i+=2){
	    	edge[i][i+1] = edge[i+1][i] = true;
	    	count++;
	    }
	    
	    for(int i=k;i<2*k-1;i++){
	    	for(int j=1;j<=k-1;j++){
	    		edge[i][j] = edge[j][i] = true;
	    		count++;
	    	}
	    	edge[2*k-1][i] = edge[i][2*k-1] = true;
	    	count++;
	    }
	    
	    for(int i=3*k;i<=4*k-2;i+=2){
	    	edge[i][i+1] = edge[i+1][i] = true;
	    	count++;
	    }
	    	
	    for(int i=2*k+1;i<3*k;i++){
	    	edge[2*k][i] = edge[i][2*k] = true;
	    	count++;
	    	for(int j=3*k;j<=4*k-2;j++){
	    		edge[i][j] = edge[j][i] = true;
	    		count++;
	    	}
	    }
	    
	    w.println(n + " " + count);
	    
	    
	    for(int i=1;i<=n;i++)
	    	for(int j=i+1;j<=n;j++)
	    		if(edge[i][j])
	    			w.println(i + " " + j);
	    
	    
	    w.close();
	}
}