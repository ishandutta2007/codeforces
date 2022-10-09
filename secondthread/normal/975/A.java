import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		HashSet<Integer> roots=new HashSet<>();
		for (int i=0; i<n; i++)
			roots.add(Arrays.hashCode(count(fs.next())));
		System.out.println(roots.size());
	}

	static boolean[] count(String s) {
		boolean[] res=new boolean[26];
		for (char c:s.toCharArray())
			res[c-'a']=true;
		return res;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}