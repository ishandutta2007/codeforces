import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int maxSize=fs.nextInt();
		int[] original=fs.readArray(n);
		TreeSet<Integer> locks=new TreeSet<>();
		boolean[] dontPick=new boolean[256];
		for (int i:original) {
			if (dontPick[i]) {
				continue;
			}
			if (locks.floor(i)!=null&&locks.floor(i)+maxSize-1>=i) {
				for (int j=locks.floor(i); j<=i; j++) {
					dontPick[j]=true;
				}
				continue;
			}
			int newLock=i;
			while (newLock>0&&!dontPick[newLock-1]&&newLock-1+maxSize-1>=i) {
				dontPick[newLock]=true;
				dontPick[newLock-1]=true;
				newLock--;
			}
			locks.add(newLock);
		}
		for (int i:original)
			System.out.print(locks.floor(i)+" ");
		System.out.println();

	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}