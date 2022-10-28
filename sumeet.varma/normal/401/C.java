import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R235qCTeam {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int zeroes = ip(st1.nextToken());
		int ones = ip(st1.nextToken());
	          
		if(ones >= (zeroes -1) && ones <= 2*(zeroes+1)){
			if(ones == zeroes - 1){
				for(int i=0;i<ones;i++)
					w.print("01");
				w.println("0");
			}
			else if(ones == zeroes){
				for(int i=0;i<ones;i++)
					w.print("10");
				w.println();
			}
			else{
				int more = ones - (zeroes + 1);
				int twos = 0;
				int done = 0;
				for(int i=0;i<zeroes;i++){
					if(twos < more){
						twos++;
						w.print("110");
						done += 2;
					}
					else{
						w.print("10");
						done++;
					}
				}
				if(done == ones - 1)
					w.println("1");
				if(done == ones - 2)
					w.println("11");
				
			}
		}
		else
			w.println(-1);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}