import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class BayanBus {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int k = ip(st1.nextToken());
	    
	    String a[] = new String[6];
	    a[0] = "+------------------------+";
	    a[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	    a[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
	    a[4] = "|#.......................|";
	    a[3] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	    a[5] = "+------------------------+";
	    
	    StringBuilder b[] = new StringBuilder[6];
	    for(int i=0;i<6;i++)
	    	b[i] = new StringBuilder(a[i]);
	    
	    if(k >= 1)
	    	b[1].setCharAt(1, 'O');
	    if(k >= 2)
	    	b[2].setCharAt(1, 'O');
	    if(k >= 3)
	    	b[4].setCharAt(1, 'O');
	    if(k >= 4)
	    	b[3].setCharAt(1, 'O');
	    
	    int pt = 0;
	    int tpt[] = new int[3];
	    tpt[0] = tpt[1] = tpt[2] = 3;
	    
	    for(int i=5;i<=k;i++){
	    	int p = (pt + 1);
	    	b[p].setCharAt(tpt[pt], 'O');
	    	tpt[pt] += 2;
	    	pt = (pt + 1) % 3;
	    }
	    
	    for(int i=0;i<=2;i++)
	    	w.println(b[i]);
	    w.println(b[4]);
	    w.println(b[3]);
	    w.println(b[5]);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}