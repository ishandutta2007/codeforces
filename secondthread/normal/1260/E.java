import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		ArrayList<Integer> others=new ArrayList<>();
		boolean seenNeg=false;
		for (int i=0; i<n; i++) {
			int temp=fs.nextInt();
			if (temp==-1) {
				seenNeg=true;
			}
			else {
				if (seenNeg) others.add(temp);
				else others.add(0);
			}
		}
		long total=others.get(n-2);
		others.set(n-2, 1_000_000_002);
		int offset=1;
		for (int pow=n/2; pow!=1; pow/=2) {
			int mindex=n-2;
			offset+=pow;
			for (int i=0; i<offset; i++) {
				int ind=Math.max(0, n-2-i);
				if (others.get(ind)<others.get(mindex)) {
					mindex=ind;
				}
			}
//			System.out.println("Mindex: "+mindex);
			total+=others.get(mindex);
			others.set(mindex, 1_000_000_002);
		}
		System.out.println(total);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}

}