import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int length=fs.nextInt();
		int q=fs.nextInt();
		char[] a=fs.next().toCharArray();
		for (int Q=0; Q<q; Q++) {
			int l=fs.nextInt()-1, r=fs.nextInt()-1;
			char from=fs.next().charAt(0), to=fs.next().charAt(0);
			for (int i=l; i<=r; i++) {
				if (a[i]==from)
					a[i]=to;
			}
		}
		for (char c:a)
			System.out.print(c);
		System.out.println();
	}

	public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        public FastScanner() {
            try    {
                br = new BufferedReader(new InputStreamReader(System.in));
//              br = new BufferedReader(new FileReader("testdata.out"));
                st = new StringTokenizer("");
            } catch (Exception e){e.printStackTrace();}
        }
        public String next() {
                if (st.hasMoreTokens())    return st.nextToken();
            try {st = new StringTokenizer(br.readLine());}
                catch (Exception e) {e.printStackTrace();}
            return st.nextToken();
        }
        public int nextInt() {return Integer.parseInt(next());}
        public long nextLong() {return Long.parseLong(next());}
        public double nextDouble() {return Double.parseDouble(next());}

        public String nextLine() {
                String line = "";
            try {line = br.readLine();}
            catch (Exception e) {e.printStackTrace();}
                return line;
        }
}

	
}