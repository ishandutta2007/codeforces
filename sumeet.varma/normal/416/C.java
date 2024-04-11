import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R241TCBookingSystem {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	  
	    Pair p[] = new Pair[n];
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	p[i] = new Pair(ip(st2.nextToken()),ip(st2.nextToken()),i+1);
	    }
	    Arrays.sort(p);

	    int k = ip(br.readLine());
	    int table[] = new int[k + 1];
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    for(int i=0;i<k;i++)
	    	table[i] = ip(st3.nextToken());
	    table[k] = 1000000;
	    
	    ArrayList<Integer> request = new ArrayList<Integer>();
	    ArrayList<Integer> tab = new ArrayList<Integer>();
	    boolean taken[] = new boolean[k + 1];
	    
	    int ans = 0,count = 0;
	    
	    for(int i=0;i<n;i++){
	    	int size = p[i].size;
	    	int minIndex = k;
	    	for(int j=0;j<k;j++){
	    		if(!taken[j] && table[j] >= size && table[j] < table[minIndex])
	    			minIndex = j;
	    	}
	    	if(minIndex != k){
	    		ans += p[i].money;
	    		taken[minIndex] = true;
	    		tab.add(minIndex + 1);
	    		request.add(p[i].index);
	    		count++;
	    	}
	    }
	    
	    w.println(count + " " + ans);
	    for(int i=0;i<count;i++)
	    	w.println(request.get(i) + " " + tab.get(i));
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}

class Pair implements Comparable<Pair>{
	int size,money,index;
	Pair(int siz,int my,int i){
		size = siz;
		money = my;
		index = i;
	}
	public int compareTo(Pair arg0) {
		if(money != arg0.money)
			return arg0.money - money;
		return size - arg0.size;
	}
	
}