import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int numberOfCubes=fs.nextInt();
		Cube[] cubes=new Cube[numberOfCubes];
		for (int i=0; i<cubes.length; i++) {
			cubes[i]=new Cube(fs);
		}
		
		for (int i=1; i<1001; i++) {
			if (!possible(""+i, cubes, 0)) {
				System.out.println(i-1);
				return;
			}
		}
	}
	
	private static boolean possible(String s, Cube[] cubes, int usedMask) {
		if (s.isEmpty()) {
			return true;
		}
		for (int cubeIndex=0; cubeIndex<cubes.length; cubeIndex++) {
			if ((usedMask&(1<<cubeIndex))!=0) {
				continue;
			}
			for (int i=0; i<6; i++) {
				if (Integer.parseInt(s.substring(0, 1))==cubes[cubeIndex].values[i]) {
					int tempMask=usedMask|(1<<cubeIndex);
					if (possible(s.substring(1), cubes, tempMask)) {
						return true;
					}
				}
			}
		}
		return false;
	}
	
	private static class Cube {
		int[] values=new int[6];
		public Cube(FastScanner fs) {
			for (int i=0; i<values.length; i++) {
				values[i]=fs.nextInt();
			}
		}
	}
	
	private static class FastScanner {
		private BufferedReader br;
		private StringTokenizer st;
		
		public FastScanner() {
			st=new StringTokenizer("");
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			if (st.hasMoreTokens()) {
				return st.nextToken();
			}
			while (!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}

/*boolean[][] dp=new boolean[1001][1<<cubes.length];
for (int i=0; i<cubes.length; i++) {
	int mask=1<<i;
	for (int j=0; j<6; j++) {
		dp[cubes[i].values[j]][mask]=true;
	}
}

for (int i=0; i<=1000; i++) {
	for (int possibleMask=0; possibleMask<1<<cubes.length; possibleMask++) {
		for (int cubeToUse=0; cubeToUse<cubes.length; cubeToUse++) {
			if ((possibleMask&(1<<cubeToUse))==0) {
				continue;
			}
			int oldMask=possibleMask^(1<<cubeToUse);
			String iAsString=i+"";
			for (int newPosition=0; newPosition<iAsString.length(); newPosition++) {
				String oldString=iAsString.substring(0, newPosition)+iAsString.substring(newPosition+1);
				if (!dp[Integer.parseInt(oldString)][oldMask]) {
					continue;
				}
				else {
					dp[i][possibleMask]=true;
				}
			}
		}
	}
	boolean possible=false;
	for (int possibleMask=0;possibleMask<1<<cubes.length; possibleMask++) {
		if (dp[i]) {
			
		}
	}
}*/