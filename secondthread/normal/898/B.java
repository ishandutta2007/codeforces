import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Set;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int aCost=fs.nextInt();
		int bCost=fs.nextInt();
		if (n%aCost==0) {
			System.out.println("YES\n"+(n/aCost)+" 0");
			return;
		}
		if (n%bCost==0) {
			System.out.println("YES\n"+"0 "+(n/bCost));
			return;
		}
		for (long i=1; i*aCost<=n; i++) {
			if ((n-(i*aCost))%bCost==0) {
				System.out.println("YES\n"+(i)+" "+(n-i*aCost)/bCost);
				return;
			}
		}
		System.out.println("NO");
	}

	
	public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        public FastScanner() {
            try    {
                br = new BufferedReader(new InputStreamReader(System.in));
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