import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R22qCSystemAdmin {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
		int v = ip(st1.nextToken());
		
		ArrayList<Integer> ans = new ArrayList<Integer>();
		
		if(m < n-1){
			System.out.println(-1);
			return;
		}
		else{
			for(int i=1;i<=n && m > 0;i++){
				if(i != v){
					ans.add(i);
					ans.add(v);
					m--;
				}
			}
			
			int leave = 1;
			if(v == 1)	leave = n;
			
			for(int i=1;i<=n && m > 0;i++){
				if(leave == i || i == v)	continue;
				for(int j=i+1;j<=n && m > 0;j++){
					if(leave == j || j == v)	continue;
					ans.add(i);
					ans.add(j);
					m--;
				}
			}
			
			if(m != 0){
				System.out.println(-1);
				return;
			}
			
			int s = ans.size();
			for(int i=0;i<s;)
				w.println(ans.get(i++) + " " + ans.get(i++));
		}
		
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}