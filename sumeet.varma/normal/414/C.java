import java.io.*;
import java.util.*;

public class R240QeMashmokhAndReverseOperations {

	static int n;
	static int a[];
	static long inv[],other[];
	static long globalEq;
	
	public static void main(String args[] ) throws Exception {
		   
		InputReader4 in = new InputReader4(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = in.nextInt();
	    a = new int[(1<<n)];
	    for(int i=0;i<(1<<n);i++)
	    	a[i] = in.nextInt();
	    
	    inv = new long[n+1];
	    other = new long[n+1];
	    mergeSort(0,(1<<n) - 1);
	    
	   // System.out.println("Equal " + Arrays.toString(equal));
	   // System.out.println("Inv " + Arrays.toString(inv));
	    
	    int m = in.nextInt();
	    for(int i=0;i<m;i++){
	    	int q = in.nextInt();
	    	for(int j=1;j<=q;j++){
	    		long t = other[j];
	    		other[j] = inv[j];
	    		inv[j] = t;
	    	}
	    	//System.out.println(Arrays.toString(inv));
	    	long ans = 0;
	    	for(int j=1;j<=n;j++)
	    		ans += inv[j];
	    	w.println(ans);
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static void mergeSort(int start,int end){
		if(start == end)
			return;
		int mid = (start + end) / 2;
		mergeSort(start,mid);
		mergeSort(mid+1,end);
		int size = Integer.toBinaryString(end - start + 1).length() - 1;
		merge(start,mid,end,size);
	}
	
	public static void merge(int start,int mid,int end,int size){
		int temp[] = new int[end - start + 1];
		int i = start,j = mid + 1,k=0;
		long inve = 0,othr = 0;
		
		while(i <= mid && j <= end){
			if(a[i] <= a[j])
				temp[k++] = a[i++];
			else{
				inve += mid + 1 - i;
				temp[k++] = a[j++];
			}
		}
		
		while(i <= mid)
			temp[k++] = a[i++];
		
		while(j <= end)
			temp[k++] = a[j++];
		
		for(i=start,j=mid+1;i<=mid && j<=end;i++,j++){
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		
		i = start;
		j = mid + 1;
		while(i <= mid && j <= end){
			if(a[i] <= a[j])
				i++;
			else{
				othr += mid + 1 - i;
				j++;
			}
		}
		
		inv[size] += inve;
		other[size] += othr;
		
		for(int x=0;x<k;x++)
			a[start + x] = temp[x];
		
	}
}

class InputReader4 {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	public InputReader4(InputStream stream) {
		this.stream = stream;
	}
	
	public int snext() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int nextInt() {
		int c = snext();
		while (isSpaceChar(c))
			c = snext();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = snext();
		}

		int res = 0;

		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = snext();
		} while (!isSpaceChar(c));

		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}