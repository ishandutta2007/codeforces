import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class R301qEInfiniteInversions {

	static int n,N;
	static int a[],b[],value[],index[];
	static TreeSet<Integer> set;
	static TreeMap<Integer,Integer> idx;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	    
	    set = new TreeSet<Integer>();
	    
	    a = new int[n];
	    b = new int[n];
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	a[i] = ip(st2.nextToken()) - 1;
	    	b[i] = ip(st2.nextToken()) - 1;
	    	set.add(a[i]);
	    	set.add(b[i]);
	    }
	    
	    N = set.size();
	    value = new int[N];
	    index = new int[N];
	    
	    int k = 0;
	    Iterator<Integer> it = set.iterator();
	    idx = new TreeMap<Integer,Integer>();
	    while(it.hasNext()){
	    	int ix = it.next();
	    	value[k] = ix;
	    	index[k] = ix;
	    	idx.put(ix, k);
	    	k++;
	    }
	
	    for(int i=0;i<n;i++){
	    	int place1 = idx.get(a[i]);
	    	int place2 = idx.get(b[i]);
	    	int t = value[place1];
	    	value[place1] = value[place2];
	    	value[place2] = t;
	    }
	    
	   // System.out.println(Arrays.toString(value));
	   // System.out.println(Arrays.toString(index));
	    
	    int index2[] = new int[N];
	    for(int i=0;i<N;i++)
	    	index2[i] = index[i];
	    Arrays.sort(index2);
	    
	    long ans = 0;
	  
	   
	    for(int i=0;i<N;i++){
	    	int v = value[i];
	    	if(index[i] < (v-1)){
	    		ans += v-index[i] - 1;
	    		ans -= count(index2,index[i],v);
	    	}
	    	if(index[i] > v+1){
	    		ans += index[i] - v - 1;
	    		ans -= count(index2,v,index[i]);
	    	}
	    }
	    
	    ans += mergeSort(0,N-1);
	    w.println(ans);
	    w.close(); 
	}
	
	public static int count(int a[],int left,int right){
		int i1 = bSLower(a,left);
		int i2 = bSHigher(a,right);
		if(i1 == -1)
			return 0;
		return i2 - i1 + 1;
	}
	
	public static int bSLower(int a[],int left){
		int ret = -1;
		int start = 0,end = a.length;
		while(true){
			if(end == start)
				return ret;
			int mid = (start + end) / 2;
			if(a[mid] > left)
				ret = mid;
			if(end - start == 1)
				return ret;
			if(a[mid] > left)
				end = mid;
			else
				start = mid + 1;
		}
	}
	
	public static int bSHigher(int a[],int left){
		int ret = -1;
		int start = 0,end = a.length;
		while(true){
			if(end == start)
				return ret;
			int mid = (start + end) / 2;
			if(a[mid] < left)
				ret = mid;
			if(end - start == 1)
				return ret;
			if(a[mid] < left)
				start = mid + 1;
			else
				end = mid;
		}
	}
	
	public static long mergeSort(int start,int end){
		if(start == end)  return 0;
		int mid = (start + end) / 2;
		return mergeSort(start,mid) + mergeSort(mid+1,end) + merge(start,mid,end);
	}

	public static long merge(int start,int mid,int end){
		int temp[] = new int[end - start + 1];
		int i = start,j = mid + 1,k=0;
		long inve = 0;
			
		while(i <= mid && j <= end){
			if(value[i] <= value[j])
				temp[k++] = value[i++];
			else{
				inve += mid + 1 - i;
				temp[k++] = value[j++];
			}
		}
			
		while(i <= mid)
			temp[k++] = value[i++];
			
		while(j <= end)
			temp[k++] = value[j++];
			
		for(int x=0;x<k;x++)
			value[start + x] = temp[x];
			
		return inve;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}