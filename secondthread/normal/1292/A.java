import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 */
public class A {
	static int nRightIllegal=0, n;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt(); int q=fs.nextInt();
		boolean[] leftHit=new boolean[n], rightHit=new boolean[n];
		boolean[] rightIllegal=new boolean[n];
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<q; qq++) {
			int x=fs.nextInt()-1, y=fs.nextInt()-1;
			if (x==0) {
				leftHit[y]^=true;
			}
			else {
				rightHit[y]^=true;
			}
			for (int yy=Math.max(0, y-1); yy<=Math.min(n-1, y+1); yy++)
				update(yy, rightHit, rightIllegal, leftHit);
			out.println(nRightIllegal>0?"No":"Yes");
		}
		out.close();
	}
	
	static void update(int y, boolean[] rightHit, boolean[] rightIllegal, boolean[] leftHit) {
		if (!rightHit[y]) {
			if (rightIllegal[y]) {
				rightIllegal[y]=false;
				nRightIllegal--;
			}
			return;
		}
		boolean shouldBeIllegal=false;
		shouldBeIllegal|=y>0 && leftHit[y-1];
		shouldBeIllegal|=leftHit[y];
		shouldBeIllegal|=y<n-1 && leftHit[y+1];
		if (shouldBeIllegal) {
			if (rightIllegal[y]) {
				return;
			}
			else {
				nRightIllegal++;
				rightIllegal[y]=true;
			}
		}
		else {
			if (rightIllegal[y]) {
				nRightIllegal--;
				rightIllegal[y]=false;
			}
		}
	}


	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
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
		long nextLong() {
			return Long.parseLong(next());
		}
	}

}