import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _526B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		if (k==1) {
			System.out.println(n);
			return;
		}
		char[] s1=fs.next().toCharArray(), s2=fs.next().toCharArray();
		int lcp=0;
		for (; lcp<n && s1[lcp]==s2[lcp]; lcp++);
		
		k-=2;
		long ans=n+n-lcp;
//		System.out.println(ans);
		long[] potentials=new long[n+1];

		//s1 side of trie
		for (int index=lcp+1; index<n; index++) {
			if (s1[index]=='a') {
				int len=n-index;
				potentials[len]++;
				for (int i=0; i<31; i++) {
					len--;
					if (len>=0)
						potentials[len]+=1l<<i;
				}
			}
		}
		
		//s2 side of trie
		for (int index=lcp+1; index<n; index++) {
			if (s2[index]=='b') {
				int len=n-index;
				potentials[len]++;
				for (int i=0; i<31; i++) {
					len--;
					if (len>=0)
						potentials[len]+=1l<<i;
				}
			}
		}
		
		for (int i=n; i>0; i--) {
			long toSub=Math.min(k, potentials[i]);
			k-=toSub;
			ans+=i*toSub;
		}
		System.out.println(ans);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
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