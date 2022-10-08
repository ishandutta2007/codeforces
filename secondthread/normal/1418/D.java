import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class D {

	static TreeMap<Integer, Integer> differencesCount=new TreeMap<>();
	static TreeSet<Integer> used=new TreeSet<>();
	static PrintWriter out;
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		out=new PrintWriter(System.out);
		int n=fs.nextInt(), q=fs.nextInt();
		for (int i=0; i<n; i++)
			add(fs.nextInt());
		print();
		for (int qq=0; qq<q; qq++) {
			int type=fs.nextInt();
			if (type==1) {
				int toAdd=fs.nextInt();
				add(toAdd);
			}
			else {
				int toDelete=fs.nextInt();
				remove(toDelete);
			}
			print();
		}
		out.close();
	}
	
	static void print() {
		if (used.size()<3) {
			out.println(0);
		}
		else {
			int full=used.last()-used.first()+1-2;
			int toSub=differencesCount.lastKey()-1;
			out.println(full-toSub);
		}
	}
	
	static void add(int i) {
		if (used.higher(i)!=null && used.lower(i)!=null) {
			int diff=used.higher(i)-used.lower(i);
			dec(differencesCount, diff);
		}
		used.add(i);
		if (used.higher(i)!=null)
			inc(differencesCount, used.higher(i)-i);
		if (used.lower(i)!=null)
			inc(differencesCount, i-used.lower(i));
	}
	
	static void remove(int i) {
		used.remove(i);
		if (used.higher(i)!=null) dec(differencesCount, used.higher(i)-i);
		if (used.lower(i)!=null) dec(differencesCount, i-used.lower(i));
		if (used.higher(i)!=null && used.lower(i)!=null) inc(differencesCount, used.higher(i)-used.lower(i));
	}
	
	static void inc(TreeMap<Integer, Integer> map, int pos) {
		map.put(pos, 1+map.getOrDefault(pos, 0));
	}
	
	static void dec(TreeMap<Integer, Integer> map, int pos) {
		if (map.get(pos)==1) map.remove(pos);
		else map.put(pos, map.get(pos)-1);
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
		
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}