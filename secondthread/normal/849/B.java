import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] array=new int[n];
		for (int i=0; i<n; i++) {
			array[i]=s.nextInt();
		}
		int firstWrongIndex=2;
		while (firstWrongIndex<n&&areColinear(0, array[0], 1, array[1], firstWrongIndex, array[firstWrongIndex])) {
			firstWrongIndex++;
		}
		if (firstWrongIndex==n) {
			//System.err.println("1");
			System.out.println("No");
			return;
		}
		
		
		double s1=getSlope(0, array[0], 1, array[1]);
		double intercept2=array[firstWrongIndex]-firstWrongIndex*s1;
		boolean broken=false;
		for (int x=0; x<array.length; x++) {
			if (Math.min(distanceFromLine(x, array[x], s1, array[0]), distanceFromLine(x, array[x], s1, intercept2))>0.0000001) {
				broken=true;
			}
			//System.out.println(Math.min(distanceFromLine(x, array[x], s1, array[0]), distanceFromLine(x, array[x], s1, intercept2)));
		}
		//System.out.println();
		if (!broken) {
			System.out.println("Yes");
			return;
		}
		s1=getSlope(0, array[0], firstWrongIndex, array[firstWrongIndex]);
		intercept2=array[1]-1*s1;
		broken=false;
		for (int x=0; x<array.length; x++) {
			if (Math.min(distanceFromLine(x, array[x], s1, array[0]), distanceFromLine(x, array[x], s1, intercept2))>0.0000001) {
				broken=true;
			}
			//System.out.println(Math.min(distanceFromLine(x, array[x], s1, array[0]), distanceFromLine(x, array[x], s1, intercept2)));
		}
		//System.out.println();
		if (!broken) {
			System.out.println("Yes");
			return;
		}
		s1=getSlope(1, array[1], firstWrongIndex, array[firstWrongIndex]);
		intercept2=array[1]-1*s1;
		broken=false;
		for (int x=0; x<array.length; x++) {
			if (Math.min(distanceFromLine(x, array[x], s1, array[0]), distanceFromLine(x, array[x], s1, intercept2))>0.0000001) {
				broken=true;
			}
			//System.out.println(Math.min(distanceFromLine(x, array[x], s1, array[0]), distanceFromLine(x, array[x], s1, intercept2)));
		}
		if (!broken) {
			System.out.println("Yes");
			return;
		}
		else {
			//System.err.println("2");
			System.out.println("No");
		}
	}

	public static boolean areColinear(int x1, int y1, int x2, int y2, int x3, int y3) {
		double s1=getSlope(x1, y1, x2, y2);
		double s2=getSlope(x2, y2, x3, y3);
		return Math.abs(s1-s2)<0.0000001;
	}
	
	public static double getSlope(int x1, int y1, int x2, int y2) {
		return (y2-y1)/(double)(x2-x1);
	}
	
	public static double distanceFromLine(int x1, int y1, double m, double b) {
		return Math.abs(m*x1-y1+b)/Math.sqrt(1+m*m);
	}
}