import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class A052 {
	public static void main(String[] args) throws Exception {
		BufferedReader r= new BufferedReader(new InputStreamReader(System.in));
		int n= Integer.parseInt(r.readLine());
		int[] ar = new int[4];
		StringTokenizer st= new StringTokenizer(r.readLine());
		for(int x = 0;x<n;x++) {
			ar[Integer.parseInt(st.nextToken())]++;
		}
		int max = 0;
		for(int x = 1;x<=3;x++) {
			if(ar[x]>max) max = ar[x];
		}
		System.out.println(n-max);
	}
}