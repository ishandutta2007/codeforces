import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeSet;
/*
10
http://abacaba.ru/test
http://abacaba.ru/
http://abacaba.com
http://abacaba.com/test
http://abacaba.de/
http://abacaba.ru/test
http://abacaba.de/test
http://abacaba.com/
http://abacaba.com/t
http://abacaba.com/test

 */
public class HostnameAliases {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		String[] prefixes=new String[n], suffixes=new String[n];
		for (int i=0; i<n; i++) {
			String line=fs.next();
			int index=line.substring(7).indexOf('/');
			if (index==-1) {
				prefixes[i]=line;
				suffixes[i]="";
			}
			else {
				prefixes[i]=line.substring(0, index+7);
				suffixes[i]=line.substring(index+7);
			}
//			System.out.println(prefixes[i]+" "+suffixes[i]);
		}
		
		
		HashMap<String, TreeSet<String>> suffixesOf=new HashMap<>();
		for (int i=0; i<n; i++) {
			if (!suffixesOf.containsKey(prefixes[i])) suffixesOf.put(prefixes[i], new TreeSet<>());
			suffixesOf.get(prefixes[i]).add(suffixes[i]);
		}
		
		HashMap<HarmeyerHash, TreeSet<String>> thingsWithHash=new HashMap<>();
		for (Entry<String, TreeSet<String>> entries:suffixesOf.entrySet()) {
			String prefix=entries.getKey();
			HarmeyerHash hash=new HarmeyerHash();
			for (String s:entries.getValue()) {
				for (char c:s.toCharArray()) hash.add(c);
				hash.add('$');
			}
			if (!thingsWithHash.containsKey(hash)) thingsWithHash.put(hash, new TreeSet<>());
			thingsWithHash.get(hash).add(prefix);
		}
		ArrayList<TreeSet<String>> toPrint=new ArrayList<>();
		for (Entry<HarmeyerHash, TreeSet<String>> entry:thingsWithHash.entrySet()) {
			if (entry.getValue().size()>1)
				toPrint.add(entry.getValue());
		}
		out.println(toPrint.size());
		for (TreeSet<String> ts:toPrint) {
			for (String s:ts) {
				out.print(s+" ");
			}
			out.println();
		}
		out.close();
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
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
	static class HarmeyerHash implements Comparable<HarmeyerHash> {
		static final long m1=8675309, m2=1_000_000_007;
		private long v1=0, v2=0;
		static final long s1=257, s2=619;
		public void add(char o) {
			v1=(v1*s1+o)%m1;
			v2=(v2*s2+o)%m2;
		}
		
		public int compareTo(HarmeyerHash o) {
			if (v1!=o.v1)
				return Long.compare(v1, o.v1);
				return Long.compare(v2, o.v2);
		}
		
		public boolean equals(Object o) {
			return compareTo((HarmeyerHash)o)==0;
		}
		
		public int hashCode() {
			return (int)v1;
		}
		
		public HarmeyerHash clone() {
			HarmeyerHash toReturn=new HarmeyerHash();
			toReturn.v1=v1;
			toReturn.v2=v2;
			return toReturn;
		}
		
		
	}


}