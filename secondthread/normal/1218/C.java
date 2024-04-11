import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
/*
3 3 5
0 1 1 0 7
1 1 1 0 10
1 1 1 1 2
1 1 1 2 2
0 1 1 2 3

500 500 2
0 1 1 0 4
0 1 1 1 2


500 500 8
100 100 5 5 1
100 101 5 5 2
101 100 5 5 3
101 101 5 5 4
100 100 6 5 5
100 101 6 5 6
101 100 6 5 7
101 101 6 5 8

6 7 6
0 2 2 2 100
0 3 3 3 100
0 2 2 1 201
0 3 3 2 5
1 2 1 3 1000
1 2 1 2 1000
200

6 7 6
0 2 2 2 100
0 3 3 3 100
0 2 2 1 194
0 3 3 2 5
1 2 1 3 1000
1 2 1 2 1000
199

6 7 6
1 2 2 3 100
1 3 3 4 100
1 2 2 2 194
1 3 3 3 5
2 2 1 4 1000
2 2 1 3 1000
0
 */
public class C {
	
	static long[][] costOf;
	static BonusAtSquare[][] hBonuses, vBonuses;
	static int maxX, maxY;
	static long[][][][] dp;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		maxX=fs.nextInt(); 
		maxY=fs.nextInt();
		int nRobots=fs.nextInt();
		costOf=new long[maxX][maxY];
		hBonuses=new BonusAtSquare[maxX][maxY];
		vBonuses=new BonusAtSquare[maxX][maxY];
		for (int x=0; x<maxX; x++)
			for (int y=0; y<maxY; y++) {
				hBonuses[x][y]=new BonusAtSquare();
				vBonuses[x][y]=new BonusAtSquare();
			}
		
		for (int i=0; i<nRobots; i++) {
			int x=fs.nextInt(), y=fs.nextInt(), d=fs.nextInt(), t=fs.nextInt();
			long killCost=fs.nextInt();
			processTransformer(x, y, d, t, killCost);
		}
		long startTime=System.currentTimeMillis();
		dp=new long[2][2][maxY+1][511];
		for (int i=0; i<dp.length; i++) 
			for (int j=0; j<dp[i].length; j++)
				for (int k=0; k<dp[i][j].length; k++)
					Arrays.fill(dp[i][j][k], -1);
		for (int xAt=maxX-1; xAt>=0; xAt--) {
			for (int j=0; j<dp[0].length; j++)
				for (int k=0; k<dp[0][j].length; k++)
					Arrays.fill(dp[(xAt&1)][j][k], -1);
			
			for (int yAt=maxY-1; yAt>=0; yAt--) {
				for (int goingH=0; goingH<2; goingH++) {
					for (int timesGoingStraight=0; timesGoingStraight<=(goingH==0?xAt:yAt); timesGoingStraight++) {
						go(xAt, yAt, timesGoingStraight, goingH);
					}
				}
			}
		}
		long ans=go(0, 0, 0, 0);
		System.out.println(ans);
		System.err.println(System.currentTimeMillis()-startTime);
	}
	
	static long go(int x, int y, int timesGoingStraight, int goingH) {
		if (x==maxX-1&&y==maxY-1) {
			return 0;
		}
		if (dp[(x&1)][goingH][y][timesGoingStraight]!=-1) return dp[(x&1)][goingH][y][timesGoingStraight];
		long curCost=costOf[x][y];
		if (goingH==1)
			curCost-=hBonuses[x][y].getBonus(timesGoingStraight);
		else
			curCost-=vBonuses[x][y].getBonus(timesGoingStraight);
//		System.out.println("Cur cost "+x+" "+y+" is "+curCost);
		long best; 
		if (goingH==1) {
			long goH=y+1<maxY?go(x, y+1, timesGoingStraight+1, 1):Long.MAX_VALUE;
			long goV=x+1<maxX?go(x+1, y, 1, 0):Long.MAX_VALUE;
			best=min(goH, goV)+curCost;
		}
		else {
			long goH=y+1<maxY?go(x, y+1, 1, 1):Long.MAX_VALUE;
			long goV=x+1<maxX?go(x+1, y, timesGoingStraight+1, 0):Long.MAX_VALUE;
			best=min(goH, goV)+curCost;
		}
//		System.out.println(x+" "+y+" "+timesGoingStraight+" "+goingH);
		return dp[(x&1)][goingH][y][timesGoingStraight]=best;
	}
	static long min(long a, long b) { return a < b ? a : b;}
	
	//have to process these in increasing straight distance
	static class BonusAtSquare {
		PriorityQueue<Bonus> pq=new PriorityQueue<>();
		public long bonusAdded=0;
		
		public void addBonus(int goingStraightFor, long bonus) {
			pq.add(new Bonus(goingStraightFor, bonus));
		}
		
		public long getBonus(int goingStraightFor) {
			while (!pq.isEmpty()&&goingStraightFor>=pq.peek().goingStraightFor) {
				Bonus next=pq.remove();
				bonusAdded+=next.points;
			}
			return bonusAdded;
		}
	}
	
	static class Bonus implements Comparable<Bonus> {
		int goingStraightFor;
		long points;
		public Bonus(int goingStraightFor, long points) {
			this.goingStraightFor=goingStraightFor;
			this.points=points;
		}
		
		public int compareTo(Bonus o) {
			return Integer.compare(goingStraightFor, o.goingStraightFor);
		}
	}
	
	static void processTransformer(int x, int y, int d, int t, long fightCost) {
//		System.out.println("Processing transformer ("+x+", "+y+") d: "+d+" startTime: "+t+" fightCost: "+fightCost);
		int[] xs=new int[4];
		int[] ys=new int[4];
		int[] firstTime=new int[4];
		xs[0]=x;
		ys[0]=y;
		firstTime[0]=t;
		xs[1]=x+d;
		ys[1]=y-d;
		firstTime[1]=t+1;
		xs[2]=x+d;
		ys[2]=y;
		firstTime[2]=t+2;
		xs[3]=x;
		ys[3]=y+d;
		firstTime[3]=t+3;
		
		ArrayList<Integer> xMatters=new ArrayList<>();
		ArrayList<Integer> yMatters=new ArrayList<>();
		for (int i=0; i<4; i++) {
			if (matters(xs[i], ys[i], firstTime[i])) {
				xMatters.add(xs[i]);
				yMatters.add(ys[i]);
			}
		}
//		System.out.println("\t"+xMatters+" "+yMatters);
		if (xMatters.size()>2) throw null;
		if (xMatters.size()==0) return;
		if (xMatters.size()==1) {
			costOf[xMatters.get(0)][yMatters.get(0)]+=fightCost;
		}
		else {
			costOf[xMatters.get(0)][yMatters.get(0)]+=fightCost;
			costOf[xMatters.get(1)][yMatters.get(1)]+=fightCost;
			if (xMatters.get(0)==(int)xMatters.get(1)) {
				hBonuses[xMatters.get(1)][yMatters.get(1)].addBonus(d, fightCost);
			}
			else {
				if (yMatters.get(0)==(int)yMatters.get(1)) {
					vBonuses[xMatters.get(1)][yMatters.get(1)].addBonus(d, fightCost);
				}
			}
		}
	}
		
	static boolean matters(int x, int y, int t) {
		if (x+y<t) return false;
		if ((t-x-y)%4!=0) return false;
		return true;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}