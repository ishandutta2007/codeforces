import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class R71qCBeaver {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    
	    int n = ip(br.readLine());
	    
	    String inp[] = new String[n];
	    for(int i=0;i<n;i++)
	    	inp[i] = br.readLine();
	    
	    Arrays.sort(inp, new Comparator<String>(){
	    	public int compare(String a,String b){
	    		return a.length() - b.length();
	    	}
	    });
	    
	    char t[][] = new char[n][];
	    for(int i=0;i<n;i++)
	    	t[i] = inp[i].toCharArray();
	    
	    int match[] = new int[s.length];
	    
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<(s.length-t[i].length+1);j++){
	    		boolean yes = true;
	    		for(int k=j,x=0,max=t[i].length;x<t[i].length;k++,x++,max--){
	    			if(t[i][x] != s[k])
	    				yes = false;
	    			if(match[k] != 0 && match[k] < max)
	    				yes = false;
	    		}
	    		if(yes)
	    			match[j] = t[i].length;
	    	}
	    }
	    
	    ArrayList<Block> block = new ArrayList<Block>();
	    for(int i=0;i<s.length;i++)
	    	if(match[i] != 0)
	    		block.add(new Block(i,match[i]));
	    
	    if(block.isEmpty()){
	    	System.out.println(s.length + " " + 0);
	    	return;
	    }
	    
	    Collections.sort(block);
	    //System.out.println(block);
	    
	    int ans = block.get(0).r;
	    int l = 0;
	    
	    int siz = block.size();
	    for(int i=0;i<siz - 1;i++){
	    	int currl = block.get(i).l + 1;
	    	int currr = block.get(i+1).r - 1;
	    	if(currr - currl + 1 > ans){
	    		ans = currr - currl + 1;
	    		l = currl;
	    	}
	    }
	    
	    
	    if((s.length - (block.get(siz - 1).l + 1)) > ans){
	    	l = block.get(siz - 1).l + 1;
	    	ans = s.length - l;
	    }
	    
	    w.println(ans + " " + l);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}

class Block implements Comparable<Block>{
	int l,r;
	Block(int l,int len){
		this.l = l;
		r = l + len - 1;
	}
	public int compareTo(Block b){
		return Integer.compare(l, b.l);
	}
	public String toString(){
		return l + " " + r;
	}
}