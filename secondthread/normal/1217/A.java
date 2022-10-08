import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		while (T-->0) {
			int str=fs.nextInt(), intel=fs.nextInt(), points=fs.nextInt();
			if (str>intel+points) {
				System.out.println(points+1);
			}
			else if (str<=intel&&str+points>intel) {
				int toSub=Math.max(0, intel+1-str);
				points-=toSub;
				int ans=points/2+1;
				System.out.println(ans);
			}
			else if (str+points<intel){
				System.out.println(0);
			}
			else {
				//str greater than intel, but not enough to invest all points
				int illegal=((intel+points)-str)/2+1;
				System.out.println(points+1-illegal);
			}
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}