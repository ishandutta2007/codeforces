import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class GargariAndBishops {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    
	    int a[][] = new int[n][n];
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	for(int j=0;j<n;j++)
	    		a[i][j] = ip(st2.nextToken());
	    }
	    
	    long leftDiag[] = new long[2*n-1];
	    long leftHelper[][] = new long[n][n];
	    
	    for(int i=0;i<n;i++){
	    	leftHelper[0][i] = a[0][i];
	    	leftHelper[i][0] = a[i][0];
	    }
	    
	    for(int i=1;i<n;i++){
	    	for(int j=1;j<n;j++)
	    		leftHelper[i][j] = leftHelper[i-1][j-1] + a[i][j];
	    }
	    
	    for(int i=0;i<2*n-1;i++){
	    	if(i < n)
	    		leftDiag[i] = leftHelper[n-1][i];
	    	else
	    		leftDiag[i] = leftHelper[n-1-i+n-1][n-1];
	    }
	  
	    long rightDiag[] = new long[2*n-1];
	    long rightHelper[][] = new long[n][n];
	    int rightIndexx[][] = new int[n][n];
	    int rightIndexy[][] = new int[n][n];
	    for(int i=0;i<n;i++){
	    	rightHelper[0][i] = a[0][i];
	    	rightHelper[i][n-1] = a[i][n-1];
	    }
	    
	    for(int i=1;i<n;i++)
	    	for(int j=n-2;j>=0;j--)
	    		rightHelper[i][j] = a[i][j] + rightHelper[i-1][j+1];
	   
	    /*
	    System.out.println("LEFTHELPER");
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<n;j++)
	    		System.out.print(leftHelper[i][j] + " ");
	    	System.out.println();
	    }*/
	    
	    for(int i=0;i<n;i++){
	    	rightIndexx[i][0] = i;
	    	rightIndexy[i][0] = 0;
	    	rightIndexx[n-1][i] = n-1;
	    	rightIndexy[n-1][i] = i;
	    }
	    
	    for(int i=n-2;i>=0;i--){
	    	for(int j=1;j<n;j++){
	    		rightIndexx[i][j] = rightIndexx[i+1][j-1];
	    		rightIndexy[i][j] = rightIndexy[i+1][j-1];
	    	}
	    }
	    
	    /*
	    System.out.println("RIGHTHELPER");
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<n;j++)
	    		System.out.print(rightHelper[i][j] + " ");
	    	System.out.println();
	    }*/
	    
	    long evenSum = 0,oddSum = 0;
	    int evenx = -1,eveny = -1, oddx = -1, oddy = -1;
	    
	    //System.out.println("Diagonals");
	    
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<n;j++){
	    		//System.out.println(" leftSum = " + leftDiag[i+j] + " rightSum = " + rightDiag[i-j+n-1]);
	    		long lS = 0;
	    		if(j >= i)
	    			lS = leftHelper[i + n- 1 -j][n-1];
	    		else
	    			lS = leftHelper[n-1][n-1-i + j];
	    		
	    		long rS = rightHelper[rightIndexx[i][j]][rightIndexy[i][j]];
	   
	    		long sum = lS + rS - a[i][j];
	    		//System.out.print(sum + " ");
	    		
	    		if((i + j) % 2 == 0){
	    			if(sum >= evenSum){
	    				evenSum = sum;
	    				evenx = i;
	    				eveny = j;
	    			}
	    		}
	    		else{
	    			if(sum >= oddSum){
	    				oddSum = sum;
	    				oddx = i;
	    				oddy = j;
	    			}
	    		}
	    	}
	    	
	    	//System.out.println();
	    }
	    
	    w.println(oddSum + evenSum);
	    w.println((evenx+1) + " " + (eveny+1) + " " + (oddx+1) + " " + (oddy+1));
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}