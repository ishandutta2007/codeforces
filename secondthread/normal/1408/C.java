import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*
1
2 10
1 9
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			double len=fs.nextInt();
			double[] positions=new double[n];
			for (int i=0; i<n; i++) positions[i]=fs.nextInt();
			double lPos=0, rPos=len, lSpeed=1, rSpeed=1;
			double totalTime=0;
			int lPointer=0, rPointer=n-1;
			while (lPointer<=rPointer) {
				double lDist=positions[lPointer]-lPos;
				double rDist=rPos-positions[rPointer];
				double lTime=lDist/lSpeed,rTime=rDist/rSpeed;
				if (lTime<rTime) {
					lPos=positions[lPointer];
					totalTime+=lTime;
					rPos-=rSpeed*lTime;
					lSpeed+=1;
					lPointer++;
				}
				else {
					rPos=positions[rPointer];
					totalTime+=rTime;
					lPos+=lSpeed*rTime;
					rSpeed+=1;
					rPointer--;
				}
			}
//			System.out.println(rPos+" "+lPos);
			//wait for them to cross each other at speed
			double crossTime=(rPos-lPos)/(lSpeed+rSpeed);
			totalTime+=crossTime;
			
			System.out.printf("%.10f\n", totalTime);
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
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
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}