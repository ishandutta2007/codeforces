import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskA {

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w = new PrintWriter(System.out);

		StringTokenizer st1 = new StringTokenizer(br.readLine());
		int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());

		StringTokenizer st2 = new StringTokenizer(br.readLine());
		I a[] = new I[n];
		for (int i = 0; i < n; i++)
			a[i] = new I(i,ip(st2.nextToken()));
		
		int sum = 0,last = n;
		Arrays.sort(a);
		for(int i=0;i<n;i++){
			sum += a[i].v;
			if(sum > k){
				last = i;
				break;
			}
			
		}
		
		w.println(last);
		for(int i=0;i<last;i++)
			w.print((a[i].i+1) + " ");
		w.close();
	}

	public static int ip(String s) {
		return Integer.parseInt(s);
	}
}

class I implements Comparable<I>{
	int v,i;
	public I(int i,int v){
		this.i = i;
		this.v = v;
	}
	public int compareTo(I arg0) {
		if( v < arg0.v)
			return -1;
		if(v > arg0.v)
			return 1;
		if(i < arg0.i)
			return -1;
		if(i > arg0.i)
			return 1;
		return 0;
	}
	
}