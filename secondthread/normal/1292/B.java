import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;
/*
 */
public class B {

	static long[] xCoords, yCoords;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long x0=fs.nextLong(), y0=fs.nextLong(), ax=fs.nextLong(), ay=fs.nextLong(), bx=fs.nextLong(), by=fs.nextLong();
		long xStart=fs.nextLong(), yStart=fs.nextLong(), time=fs.nextLong();
		
		getPoints(x0, y0, ax, ay, bx, by);
		
		
		//only like 100 points or something, can be naive
		int n=xCoords.length;
		int ans=0;
		for (int start=0; start<n; start++) {
//			System.out.println("Starting at "+xCoords[start]+" "+yCoords[start]);
			for (int after=0; after<n; after++) {
				for (int third=0; third<n; third++) {
					long totalDist=dist(xStart, yStart, xCoords[start], yCoords[start]);
					totalDist+=dist(xCoords[start], yCoords[start], xCoords[after], yCoords[after]);
					totalDist+=dist(xCoords[after], yCoords[after], xCoords[third], yCoords[third]);
//					System.out.println("For "+start+" "+after+" "+third+" total dist: "+totalDist);
					if (totalDist<=time) {
						ans=Math.max(ans, 1+Math.max(start, Math.max(after, third))-Math.min(start, Math.min(after, third)));
					}
				}
			}
		}
		System.out.println(ans);
	}
	
	static long dist(long x1, long y1, long x2, long y2) {
		return Math.abs(x1-x2)+Math.abs(y1-y2);
	}
	
	static void getPoints(long x0, long y0, long ax, long ay, long bx, long by) {
		BigInteger lastX=BigInteger.valueOf(x0), lastY=BigInteger.valueOf(y0);
		BigInteger max=BigInteger.valueOf((long)1e17);
		ArrayList<Long> xs=new ArrayList<>(), ys=new ArrayList<>();
		while (lastX.add(lastY).compareTo(max)<0) {
			xs.add(lastX.longValue());
			ys.add(lastY.longValue());
			lastX=lastX.multiply(BigInteger.valueOf(ax)).add(BigInteger.valueOf(bx));
			lastY=lastY.multiply(BigInteger.valueOf(ay)).add(BigInteger.valueOf(by));
		}
		xCoords=new long[xs.size()]; yCoords=new long[ys.size()];
		for (int i=0; i<xs.size(); i++) {
			xCoords[i]=xs.get(i);
			yCoords[i]=ys.get(i);
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
		
		long nextLong() {
			return Long.parseLong(next());
		}
	}

}