import java.io.*;
import java.util.*;

public class R301qC {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int R = ip(st1.nextToken());
		int S = ip(st1.nextToken());
		int P = ip(st1.nextToken());
	        
		double dp[][][][] = new double[3][101][101][101];
	    
		for(int r=0;r<=R;r++){
			for(int s=0;s<=S;s++){
				for(int p=0;p<=P;p++){	
					if(r == 0 && s == 0 && p != 0)
						dp[2][r][s][p] = 1;
					else if(r != 0 && s == 0 && p == 0)
						dp[0][r][s][p] = 1;
					else if(r == 0 && s != 0 && p == 0)
						dp[1][r][s][p] = 1;
					else if(r == 0 && s == 0 && p == 0)
						continue;
					else{
						double t = r*s + s*p + p*r;
						for(int i=0;i<3;i++){
							if(r > 0 && s > 0)
								dp[i][r][s][p] += r*s*dp[i][r][s-1][p];
							if(s > 0 && p > 0)
								dp[i][r][s][p] += s*p*dp[i][r][s][p-1];
							if(p > 0 && r > 0)
								dp[i][r][s][p] += p*r*dp[i][r-1][s][p];
							dp[i][r][s][p] /= t;
						}
					}
				}
			}
		}
		
		w.println(dp[0][R][S][P] + " " + dp[1][R][S][P] + " " + dp[2][R][S][P]);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}