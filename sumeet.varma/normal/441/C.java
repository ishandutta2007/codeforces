import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R252QCValeraAndTubes {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	    
		boolean straight = true;
		
		int x1=0,y1=0,x2=0,y2=0,count=0;
		int x = 0;
		if(k > 1){
			for(int i=1;i<=n;i++){
				if(straight){
					for(int j=1;j<=m;j++){
						if(count == 0){
							x1 = i;
							y1 = j;
							count++;
						}
						else if(count == 1){
							x2 = i;
							y2 = j;
							x++;
							if(x == k)
								break;
							w.println(2 + " " + x1 + " " + y1 + " " + x2 + " " + y2 + " ");
							
							count = 0;
						}
					}
				}
				else{
					for(int j=m;j>=1;j--){
						if(count == 0){
							x1 = i;
							y1 = j;
							count++;
						}
						else if(count == 1){
							x2 = i;
							y2 = j;
							x++;
							if(x == k)
								break;
							w.println(2 + " " + x1 + " " + y1 + " " + x2 + " " + y2 + " ");
							
							count = 0;
						}
					}
				}
				straight = !straight;
				if(x == k)
					break;
			}
		
		}
		straight = true;
		int c = 0;
		w.print((n*m - 2*(k-1)) + " ");
		int u = 2*(k-1);
		for(int i=1;i<=n;i++){
			if(straight){
				for(int j=1;j<=m;j++){
					c++;
					if(c > u)
						w.print(i + " " + j + " ");
				}
			}
			else{
				for(int j=m;j>=1;j--){
					c++;
					if(c > u)
						w.print(i + " " + j + " ");
				}
			}
			straight = !straight;
		}
		
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}