import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int Q=fs.nextInt();
		Vector[] poly=new Vector[n+1];
		for (int i=0; i<n; i++)
			poly[i]=new Vector(fs.nextInt(), fs.nextInt());
		poly[n]=poly[0];
		
		Vector diff=poly[0];
		Vector[] shifted=new Vector[n+1];
		for (int i=0; i<n; i++) {
			shifted[i]=poly[i].sub(diff);
		}
		
		Vector com=getCentroid(shifted, n).add(diff);
		Vector initialCOM=com;
		
		double curAngle=0;
		
		PrintWriter out=new PrintWriter(System.out);
		int[] pins= {0, 1};
		for (int q=0; q<Q; q++) {
			int qType=fs.nextInt();
			if (qType==1) {
				int removeFrom=fs.nextInt()-1;
				int placeIn=fs.nextInt()-1;
				int pinIndex=pins[0]==removeFrom?0:1;
				
				int pivotIndex=pins[-pinIndex+1];
				double newAngle=getNewAngle(poly, initialCOM, pivotIndex);
				double dAngle=newAngle-curAngle;
				com=com.rotateAround(getPoint(poly, initialCOM, com, curAngle, pivotIndex), dAngle);
				curAngle=newAngle;
				
				pins[pinIndex]=placeIn;
			}
			else {
				int pointQuery=fs.nextInt()-1;
				Vector pos=getPoint(poly, initialCOM, com, curAngle, pointQuery);
				out.printf("%.12f %.12f\n", pos.x, pos.y);
			}
		}
		out.close();
		
	}

	static double getNewAngle(Vector[] poly, Vector initialCOM, int pivotPoint) {
		Vector pivot=poly[pivotPoint];
		Vector pivToCOM=initialCOM.sub(pivot);
		return (Math.PI*3/2)-pivToCOM.angle();
	}
	
	static Vector getPoint(Vector[] poly, Vector initialCOM, Vector currentCOM, double currentAngle, int pointIndex) {
		Vector initialD=poly[pointIndex].sub(initialCOM);
		Vector rotated=initialD.rotate(currentAngle);
		return currentCOM.add(rotated);
	}
	
	 public static Vector getCentroid(Vector[] vs, int n) {
	        double a = 0.0, cx = 0.0, cy = 0.0;
	        for(int i = 0; i < n; i++) {
	            Vector va = vs[i];
	            Vector vb = vs[(i + 1) % n];
	            double temp = va.x * vb.y - vb.x * va.y;
	            a += temp;
	            cx += (va.x + vb.x) * temp;
	            cy += (va.y + vb.y) * temp;
	        }
	        a *= 3.0;
	        return new Vector(cx / a, cy / a);
	}

	
	
	static class Vector {
		double x, y;
		public Vector(double x, double y) {
			this.x=x;
			this.y=y;
		}
		
		public Vector add(Vector o) {
			return new Vector(x+o.x, y+o.y);
		}
		
		public Vector scale(double s) {
			return new Vector(x*s, y*s);
		}
		
		public Vector sub(Vector o) {
			return add(o.scale(-1));
		}
		
		public Vector rotate(double rad) {
			double newX=x*Math.cos(rad)+y*Math.cos(Math.PI/2+rad);
			double newY=x*Math.sin(rad)+y*Math.sin(Math.PI/2+rad);
			return new Vector(newX, newY);
		}
		
		public double angle() {
			return Math.atan2(y, x);
		}
		
		public Vector rotateAround(Vector pivot, double theta) {
			Vector pivToMe=sub(pivot);
			pivToMe=pivToMe.rotate(theta);
			return pivot.add(pivToMe);
		}
		
		public double dot(Vector o) {
			return x*o.x+y*o.y;
		}
		
		public double xProd(Vector o) {
			return x*o.y-y*o.x;
		}
		
		public String toString() {
			DecimalFormat df=new DecimalFormat("0.00");
			return "("+df.format(x)+", "+df.format(y)+")";
		}

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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}
	
	static class Tri {
		Vector a, b, c;
		public Tri(Vector a, Vector b, Vector c) {
			this.a=a;
			this.b=b;
			this.c=c;
		}
		
		public double mass() {
			Vector ab=b.sub(a), ac=c.sub(a);
			return ab.xProd(ac)/2;
		}
		
		public Vector COM() {
			return a.add(b.add(c)).scale(1.0/3);
		}
	}
	
}