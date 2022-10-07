import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class C043 {
	public static void main(String[] args) throws Exception 
	{
		int[] ar = new int[3];
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		StringTokenizer st = new StringTokenizer(r.readLine());
		for(int x = 0;x<n;x++) {
			int next = Integer.parseInt(st.nextToken());
			ar[next%3]++;
		}
		int sum = (ar[1]<ar[2]?ar[1]:ar[2])+ar[0]/2;
		System.out.println(sum);
	}
}