import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long onTime=fs.nextLong(), d=fs.nextLong(), totalTime=fs.nextLong();
		d=d*((onTime+d-1)/d);
		
		double percentOn=onTime/(double)d;
		double cookRate=1.0/totalTime;
		double cookedPerRound=percentOn*d*cookRate+(1-percentOn)*d*cookRate/2;
		
		double fullRoundsNeeded=Math.floor(1/cookedPerRound);
		double ans=fullRoundsNeeded*d;
		
		double left=1-(cookedPerRound*fullRoundsNeeded);
		double fullCookAmount=percentOn*d*cookRate;
		if (left<=fullCookAmount) {
			ans+=left/cookRate;
		}
		else {
			ans+=onTime;
			left-=fullCookAmount;
			ans+=left/(cookRate/2);
		}
		
		System.out.println(ans);
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