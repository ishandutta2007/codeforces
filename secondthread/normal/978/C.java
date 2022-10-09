import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nBuildings=fs.nextInt();
		int nQueries=fs.nextInt();
		long[] buildingSizes=fs.readArray(nBuildings);
		TreeMap<Long, Long> buildingStarts=new TreeMap<>();
		long total=0;
		for (int i=0; i<nBuildings; i++) {
			buildingStarts.put(total, i+0l);
			total+=buildingSizes[i];
		}
		for (int q=0; q<nQueries; q++) {
			long query=fs.nextLong()-1;
			long building=buildingStarts.get(buildingStarts.floorKey(query))+1;
			long room=query-buildingStarts.floorKey(query)+1;
			System.out.println(building+" "+room);
		}
		
	}
	
	static int bs(long[] presums, long targetSum) {
		int min=0, max=presums.length-1;
		while (min<max) {
			int mid=(min+max)/2;
			if (presums[mid]<=targetSum) {
				min=mid+1;
			}
			else {
				max=mid;
			}
		}
		return min;
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
		
		public long[] readArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
}