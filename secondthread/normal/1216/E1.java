import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class e {

	public static void main(String[] args) {
		long MAX=(int)2e9;
//		System.out.println(max*(max+1)/2);
		FastScanner fs=new FastScanner();
		int Q=fs.nextInt();
		Query[] queries=new Query[Q];
		for (int qq=0; qq<Q; qq++) {
			queries[qq]=new Query(qq, fs.nextLong());
		}
		Arrays.sort(queries);
		int nextToAdd=1;
		char[] answers=new char[Q];
		long toSub=0;
		ArrayList<Character> digits=new ArrayList<>();
		int queryIndex=0;
		while (queryIndex<Q) {
			while (toSub+digits.size()<queries[queryIndex].k) {
				toSub+=digits.size();
				char[] toAdd=(nextToAdd+"").toCharArray();
				for (char c:toAdd) digits.add(c);
				nextToAdd++;
			}
			answers[queries[queryIndex].index]=digits.get((int) (queries[queryIndex].k-1-toSub));
			queryIndex++;
		}
		for (char c:answers) {
			System.out.println(c);
		}
	}
	
	static class Query implements Comparable<Query> {
		int index;
		long k;
		
		public Query(int index, long k) {
			this.index=index;
			this.k=k;
		}
		
		public int compareTo(Query o) {
			return Long.compare(k, o.k);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(""	);
		public String next() {
			while (!st.hasMoreElements())
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}

}