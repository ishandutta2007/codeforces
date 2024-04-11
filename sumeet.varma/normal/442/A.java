import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class BoryaAndHanbi {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	       
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	   	int n = ip(st1.nextToken());
	    	
	   	boolean der3[][] = new boolean[5][5];
	    	
	   	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++){
        	char s[] = st2.nextToken().toCharArray();
        	if(s[0] == 'G')
	       		der3[0][s[1] - '1'] = true;
	       	if(s[0] == 'R')
	       		der3[1][s[1] - '1'] = true;
	       	if(s[0] == 'Y')
	       		der3[2][s[1] - '1'] = true;
	       	if(s[0] == 'B')
	       		der3[3][s[1] - '1'] = true;
	       	if(s[0] == 'W')
        		der3[4][s[1] - '1'] = true;
	    }
	    
	    int ans = 10;
	    for(int i=0;i<1024;i++){
	    
	    	boolean der[][] = new boolean[5][5];
	    	for(int x=0;x<5;x++)
	    		for(int y=0;y<5;y++)
	    			der[x][y] = der3[x][y];
	    	
	    	boolean hint[] = new boolean[10];
	    	int thisCount = 0;
	    	for(int j=0;j<10;j++){
	    		if( (i & (1 << j)) != 0){
	    			hint[j] = true;
	    			thisCount++;
	    		}
	    	}
	    	
	    	boolean der2[][][] = new boolean[5][5][2];
	    	
	    	for(int x=0;x<5;x++){
	    		for(int y=0;y<5;y++){
	    			if(der[x][y]){
	    				if(hint[x] && hint[y+5])
	    					der[x][y] = false;
	    				if(hint[x])
	    					der2[x][y][0] = true;
	    				if(hint[y+5])
	    					der2[x][y][1] = true;
	    			}
	    		}
	    	}
	    	
	    	
	    	int count[] = new int[10];
	    	for(int x=0;x<5;x++){
	    		for(int y=0;y<5;y++){
	    			if(der[x][y]){
	    				count[x]++;
	    				count[5+y]++;
	    			}
	    		}
	    	}
	    	
	    	int left = 0;
	    	for(int x=0;x<5;x++){
	    		for(int y=0;y<5;y++){
	    			if(der[x][y]){
	    				if(!der2[x][y][0] && !der2[x][y][1])
	    					left++;
	    				if(der2[x][y][0] && !der2[x][y][1]){
	    					if(count[x] > 1)
	    						left++;
	    				}
	    				if(!der2[x][y][0] && der2[x][y][1]){
	    					if(count[5+y] > 1)
	    						left++;
	    				}
	    			}
	    		}
	    	}
	    	
	    	if(left<=1)
	    		ans = Math.min(ans, thisCount);
	    }
	    
	    w.println(ans);
	    w.close();
	        
	}
	
	public static int setBits(int x){
		int count = 0;
		for(int i=0;i<31;i++){
			int temp = x>>1;
			temp = temp << 1;
			if(temp!=x)	count++;
			x = x>>1;
		}
		return count;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}