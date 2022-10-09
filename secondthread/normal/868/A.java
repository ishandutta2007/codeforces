import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		String word=fs.next();
		int n=fs.nextInt();
		boolean startFlag=false, endFlag=false;
		for (int i=0; i<n; i++) {
			String line=fs.next();
			if (line.equals(word)) {
				System.out.println("YES");
				return;
			}
			if (line.startsWith(""+word.charAt(1))) {
				endFlag=true;
			}
			if (line.endsWith(""+word.charAt(0))) {
				startFlag=true;
			}
		}
		if (startFlag&&endFlag) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}

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