import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Set;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;



public class Cubes {

	static Cube c[];
	static Set<Integer> child[];
	static Set<Integer> parent[];
	static int ans[];
	static int m;
	static long mod = (long)(1e9+7);
	static PriorityQueue<Integer> minq,maxq;
	static boolean rem[],added[];
	
	@SuppressWarnings({ "unchecked", "rawtypes" })
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    m = ip(st1.nextToken());
	    
	    c = new Cube[m];
	    ans = new int[m];
	    child = new Set[m];
	    parent = new Set[m];
	    
	    for(int i=0;i<m;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int x = ip(st2.nextToken());
	    	int y = ip(st2.nextToken());
	    	c[i] = new Cube(x,y,i);
	    	child[i] = new TreeSet();
	    	parent[i] = new TreeSet();
	    }
	         
	    Arrays.sort(c);
	    
	    for(int i=0;i<m;i++){
	    	if(c[i].y != 0){
	    		int i1 = bS(c[i].x-1, c[i].y-1);
	    		if(i1 != -1){
	    			child[c[i].v].add(c[i1].v);
	    			parent[c[i1].v].add(c[i].v);
	    		}
	    		i1 = bS(c[i].x, c[i].y-1);
	    		if(i1 != -1){
	    			child[c[i].v].add(c[i1].v);
	    			parent[c[i1].v].add(c[i].v);
	    		}
	    		i1 = bS(c[i].x+1, c[i].y-1);
	    		if(i1 != -1){
	    			child[c[i].v].add(c[i1].v);
	    			parent[c[i1].v].add(c[i].v);
	    		}
	    	}
	    }
	    
	    minq = new PriorityQueue(m);
	    maxq = new PriorityQueue(m,Collections.reverseOrder());
	    added = new boolean[m];
	    
	    for(int i=0;i<m;i++){
	    	if(parent[i].size() == 0){
	    		minq.add(i);
	    		added[i] = true;
	    	}
	    	else{
	    		int s = parent[i].size();
	    		boolean canAdd = true;
	    		Iterator<Integer> it = parent[i].iterator();
	    		for(int j=0;j<s;j++)
	    			if(child[it.next()].size() < 2)
	    				canAdd = false;
	    		if(canAdd){
	    			added[i] = true;
	    			minq.add(i);
	    		}
	    	}
	    }
	    
	    maxq.addAll(minq);
	    
	    rem = new boolean[m];
	    boolean turn = false;
	    
	    for(int i=0;i<m;i++){
	    	int curr = -1;
	    	if(turn){
	    		curr = minq.remove();
	    		while(rem[curr] || !check(curr)){
	    			if(!check(curr))
	    				added[curr] = false;
	    			curr = minq.remove();
	    		}
	    	}
	    	else{
	    		curr = maxq.remove();
	    		while(rem[curr] || !check(curr)){
	    			if(!check(curr))
	    				added[curr] = false;
	    			curr = maxq.remove();
	    		}
	    	}
	    	
	    	rem[curr] = true;
	    	turn = !turn;
	    	
	    	Iterator<Integer> it = parent[curr].iterator();
	    	while(it.hasNext())
	    		child[it.next()].remove(curr);
	    	
	    	it = child[curr].iterator();
	    	while(it.hasNext()){
	    		int nx = it.next();
	    		parent[nx].remove(curr);
	    		if(added[nx] == false && check(nx)){
	    			minq.add(nx);
	    			maxq.add(nx);
	    			added[nx] = true;
	    		}
	    	}
	    	
	    	ans[i] = curr;
	    	//System.out.println(ans[i]);
	    }
	    
	    w.println(getAns());
	   
	    /* BRUTE FORCE O(n^2)
	    int ans2[] = new int[m];
	    boolean rem2[] = new boolean[m];
	    boolean turn  = false;
	    for(int i = 0;i<m;i++){
	    	if(turn){
	    		for(int j = 0; j < m;j++){
	    			if(rem2[j] == false){
	    				if(check(j)){
	    					rem2[j] = true;
	    					ans2[i] = j;
	    					Iterator<Integer> it = parent[j].iterator();
	    			    	while(it.hasNext())	child[it.next()].remove(j);
	    			    	it = child[j].iterator();
	    			    	while(it.hasNext())	parent[it.next()].remove(j);
	    			    	break;
	    				}
	    			}
	    		}
	    	}
	    	else{
	    		for(int j = m-1; j >0;j--){
	    			if(rem2[j] == false){
	    				if(check(j)){
	    					rem2[j] = true;
	    					ans2[i] = j;
	    					Iterator<Integer> it = parent[j].iterator();
	    			    	while(it.hasNext())	child[it.next()].remove(j);
	    			    	it = child[j].iterator();
	    			    	while(it.hasNext())	parent[it.next()].remove(j);
	    			    	break;
	    				}
	    			}
	    		}
	    	}
	    	turn = !turn;
	    }
	    
	    for(int i=0;i<m;i++)
	    	System.out.println(ans2[i]);
	    ans = ans2.clone();
	    w.println(getAns());*/
	    
	    
	    w.close(); 
	}
	
	public static boolean check(int curr){
		Iterator<Integer> it = parent[curr].iterator();
		while(it.hasNext()){
			int nx = it.next();
			if(child[nx].size() < 2)
				return false;
		}
		return true;
	}
	
	public static long getAns(){
		long f = 1;
	    long answer = 0;
	    long mod = (long)(1e9 + 9);
	    
	    for(int i=m-1;i>=0;i--){
	    	answer = (answer + (f*ans[i])%mod ) % mod;
	    	f = (f*m) % mod;
	    }
	    
	    return answer;
	}
	
	public static int bS(int x,int y){
		int sy = bSyFirst(y);
		if(sy == -1)
			return -1;
		int ey = bSyLast(y);
		return bSx(x,sy,ey+1);
	}
	
	//Returns first occurrence of key when it is present else -1
	public static int bSyFirst(int key){
		int start = 0,end = c.length;
		int ret = -1;
		while(true){
			if(start==end) return ret;
			int mid = (start+end)/2;
			if(key==c[mid].y) ret = mid;
			if(end-start==1) return ret;
			if(key<=c[mid].y)	end = mid;
			else start = mid+1;
		}
	}
		
	//Returns last occurrence of key when it is present else -1
	public static int bSyLast(int key){
		int start = 0,end = c.length;
		int ret = -1;
		while(true){
			if(start==end) return ret;
			int mid = (start+end)/2;
			if(key==c[mid].y) ret = mid;
			if(end-start==1) return ret;
			if(key<c[mid].y)	end = mid;
			else start = mid+1;
		}
	}
	
	//Returns if key is present in the range
	public static int bSx(int key,int start,int end){
		while(true){
			if(start==end) return -1;
			int mid = (start+end)/2;
			if(key==c[mid].x) return mid;
			if(end-start==1) return -1;
			if(key<c[mid].x)	end = mid;
			else start = mid+1;
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}

class Cube implements Comparable<Cube>{
	int x,y,v;
	Cube(int x,int y,int v){
		this.x = x;
		this.y = y;
		this.v = v;
	}
	@Override
	public int compareTo(Cube arg0) {
		if(y < arg0.y)
			return -1;
		if(y > arg0.y)
			return 1;
		if(x < arg0.x)
			return -1;
		if(x >  arg0.x)
			return 1;
		return 0;
	}
}