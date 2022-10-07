import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class C071 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(r.readLine());
		StringTokenizer st = new StringTokenizer(r.readLine());
		int[] facs = facs(n);
		int[] ar = new int[n];
		for(int x =0;x<n;x++)
			ar[x]=Integer.parseInt(st.nextToken());
		for (int p:facs) {
			boolean[] ad = new boolean[p];
			for(int x=0;x<n;x++)
				if(ar[x]==0) {
					ad[x%p] = true;
				}
			for(int x =0;x<p;x++) {
				if(!ad[x]) {
					System.out.println("YES");
					return;
				}
			}
			
		}
		System.out.println("NO");
		
	}
	static int[] facs(int a) {
		ArrayList<Integer> ar = new ArrayList<Integer>();
		for(int x = 1;x*2<a;x++) {
			if(a%x==0) {
				ar.add(x);
			}
		}

		int[] i = new int[ar.size()];
		for(int x = 0;x<ar.size();x++) 
			i[x]=ar.get(x);
		return i;
	}
}