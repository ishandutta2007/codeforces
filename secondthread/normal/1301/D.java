import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
3 2
1 2 1
2 3 2

4 4
1 2 0
2 3 1
2 4 3
3 4 8
 */
public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt(), dist=fs.nextInt();
		if (dist>w*h*4-2*w-2*h) {
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
		ArrayList<Move> moves=new ArrayList<>();
		moves.add(new Move("D", h-1));
		moves.add(new Move("U", h-1));
		for (int x=1; x<w; x++) {
			moves.add(new Move("RDL", h-1));
			moves.add(new Move("R", 1));
			moves.add(new Move("U", h-1));
		}
		moves.add(new Move("L", w-1));

		//print prefix()
		ArrayList<String> toPrint=new ArrayList<>();
		for (Move m:moves) {
			if (dist==0) break;
			if (m.times==0) continue;
			int len=m.dirs.length*m.times;
			if (len<=dist) {
				toPrint.add(m.s+" "+m.times);
				dist-=len;
			}
			else {
				int fullTimes=dist/m.dirs.length;
				if (fullTimes!=0) {
					toPrint.add(m.s+" "+fullTimes);
					dist-=m.dirs.length*fullTimes;
				}
				if (dist>0) {
					toPrint.add(m.s.substring(0, dist)+" 1");
					dist=0;
				}
			}
		}
		System.out.println(toPrint.size());
		for (String s:toPrint) {
			String[] parts=s.split(" ");
			System.out.println(parts[1]+" "+parts[0]);
		}
	}
	
	static class Move {
		char[] dirs;
		String s;
		int times;
		public Move(String dirs, int times) {
			this.s=dirs;
			this.dirs=dirs.toCharArray();
			this.times=times;
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
	}

}