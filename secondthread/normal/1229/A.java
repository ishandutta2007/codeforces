import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		long[] masks=new long[n];
		long[] skills=new long[n];
		for (int i=0; i<n; i++) masks[i]=fs.nextLong();
		for (int i=0; i<n; i++) skills[i]=fs.nextLong();
		HashSet<Long> seenMasks=new HashSet<>();
		HashSet<Long> doubleSeenMasks=new HashSet<>();
		ArrayList<Long> includedMasks=new ArrayList<>();
		for (long l:masks) {
			if (seenMasks.contains(l)) {
				if (!doubleSeenMasks.contains(l)) {
					includedMasks.add(l);
					doubleSeenMasks.add(l);
				}
			}
			else {
				seenMasks.add(l);
			}
		}
		long total=0;
		for (int i=0; i<n; i++) {
			for (long j:includedMasks) {
				if ((masks[i]&j)==masks[i]) {
					total+=skills[i];
					break;
				}
			}
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
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}

}