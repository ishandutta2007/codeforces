import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
2 4 3
2 3
4 7

2 4
3 4
3 2
5 11

1 2 4
2 1 6
3 4 6

1 1 2
2 1

2 1

1 1 5
1 1 2

2 1 2
2 1
2 2

2 1

1 1 5
1 1 2

1 2 4
2 1

2 10
10 1

1 1 5
1 1 2
9 1 2
10 10 1000000000
//5
 * 
1 1 3
881532 2
611293 2
480874 199245 4
85488 553469 1
815430 432256 4
 */
public class C {
	
	static final long oo=1_000_000_000_000_000_00l;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int nWeapons=fs.nextInt(), nArmors=fs.nextInt(), nMonsters=fs.nextInt();
			Item[] weapons=new Item[nWeapons], armor=new Item[nArmors];
			for (int i=0; i<nWeapons; i++) weapons[i]=new Item(fs.nextInt(), fs.nextInt());
			for (int i=0; i<nArmors; i++) armor[i]=new Item(fs.nextInt(), fs.nextInt());
			Monster[] monsters=new Monster[nMonsters];
			for (int i=0; i<nMonsters; i++) {
				int x=fs.nextInt()+1, y=fs.nextInt()+1, profit=fs.nextInt();
				monsters[i]=new Monster(x, y, profit);
			}
			Arrays.sort(weapons);
			Arrays.sort(armor);
			Arrays.sort(monsters);
			
			int minCost=Integer.MAX_VALUE;
			for (int i=nArmors-1; i>=0; i--) {
				minCost=Math.min(minCost, armor[i].cost);
				armor[i].cost=minCost;
			}
			
			final int maxCoord=1_000_002;
			SegTree st=new SegTree(0, maxCoord);
			int lastY=-1;
			for (Item a:armor) {
				st.rangeAdd(lastY+1, a.stat, -a.cost);
				lastY=a.stat;
			}
			st.rangeAdd(lastY+1, maxCoord, -oo);
			
			int monsterIndex=0;
			long bestAns=Long.MIN_VALUE;
			for (int weapon=0; weapon<nWeapons; weapon++) {
				while (monsterIndex<nMonsters && monsters[monsterIndex].x<=weapons[weapon].stat) {
					st.rangeAdd(monsters[monsterIndex].y, maxCoord, monsters[monsterIndex].profit);
//					System.out.println("Got monster "+monsterIndex+" "+monsters[monsterIndex].x+" "+weapons[weapon].stat);
					monsterIndex++;
				}
//				System.out.println("Trying weapon "+weapon+" "+st.max()+" "+weapons[weapon].cost);
				bestAns=Math.max(bestAns, st.max()-weapons[weapon].cost);
			}
			System.out.println(bestAns);
		}
			
	}
	
	static class Item implements Comparable<Item> {
		int stat, cost;
		public Item(int stat, int cost) {
			this.stat=stat;
			this.cost=cost;
		}
		
		public int compareTo(Item o) {
			if (stat!=o.stat) return Integer.compare(stat, o.stat);
			return -Integer.compare(cost, o.cost);
		}
	}
	
	static class Monster implements Comparable<Monster>{
		int x, y, profit;
		public Monster(int x, int y, int profit) {
			this.x=x;
			this.y=y;
			this.profit=profit;
		}
		
		public int compareTo(Monster o) {
			return Integer.compare(x, o.x);
		}
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		long toProp;
		long max;
		
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
			}
		}
		
		public void rangeAdd(int l, int r, long toAdd) {
			if (l<=leftmost && r>=rightmost) {
				toProp+=toAdd;
				return;
			}
			else if (l>rightmost || r<leftmost) {
				return;
			}
			prop();
			lChild.rangeAdd(l, r, toAdd);
			rChild.rangeAdd(l, r, toAdd);
			recalc();
		}
		
		public void prop() {
			if (leftmost==rightmost) {
				return;
			}
			lChild.toProp+=toProp;
			rChild.toProp+=toProp;
			toProp=0;
			recalc();
		}
		
		public void recalc() {
			if (leftmost==rightmost) return;
			max=Math.max(lChild.max(), rChild.max());
		}
		
		long max() {
			return max+toProp;
		}
	}
	
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
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