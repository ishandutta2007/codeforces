import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class VasyaAndFootball {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    String home = br.readLine().trim();
	    String away = br.readLine().trim();
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    Cards card[] = new Cards[n];
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int min = ip(st2.nextToken());
	    	char team = st2.nextToken().charAt(0);
	    	int m = ip(st2.nextToken());
	    	char type = st2.nextToken().charAt(0);
	    	card[i] = new Cards(min,team,m,type);
	    }
	    
	    Arrays.sort(card);
	    int hom[] = new int[100];
	    int awa[] = new int[100];
	    boolean gh[] = new boolean[100];
	    boolean ga[] = new boolean[100];
	    
	    for(int i=0;i<n;i++){
	    	if(card[i].team == 'h'){
	    		if(card[i].type == 'y'){
	    			hom[card[i].num]++;
	    			if(hom[card[i].num] == 2 && gh[card[i].num] ==false){
	    				w.println(home + " " + card[i].num + " " +card[i].min);
	    				gh[card[i].num] = true;
	    			}
	    		}
	    		else{
	    			if(gh[card[i].num] == false){
	    			w.println(home + " " + card[i].num + " " +card[i].min);
	    				gh[card[i].num] = true;
	    			}
	    		}
	    	}
	    	else{
	    		if(card[i].type == 'y'){
	    			awa[card[i].num]++;
	    			if(awa[card[i].num] == 2 && ga[card[i].num] == false){
	    				w.println(away + " " + card[i].num + " " +card[i].min);
	    				ga[card[i].num] = true;
	    			}
	    		}
	    		else{
	    			if(ga[card[i].num] == false){
	    				w.println(away + " " + card[i].num + " " +card[i].min);
	    				ga[card[i].num] = true;
	    			}
	    		}
	    	}
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Cards implements Comparable <Cards>{
	char team,type ;
	int min;
	int num;
	public Cards(int min,char team,int num,char type){
		this.min = min;
		this.team = team;
		this.num = num;
		this.type = type;
	}
	public int compareTo(Cards arg0) {
		if(min < arg0.min)	return -1;
		if(min > arg0.min)	return 1;
		return 0;
	}
	
}