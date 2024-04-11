import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class E131 {
	static class line {
		int max, min;
		int count;

		public line() {
			count = 0;
			max = 0;
			min = Integer.MAX_VALUE;
		}

		void put(int k) {
			count++;
			if (k < min)
				min = k;
			if (k > max)
				max = k;
		}

		int g(int a) {
			if (count == 1)
				return 0;
			if (a == max || a == min)
				return 1;
			return 2;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(r.readLine());
		int n = Integer.parseInt(st.nextToken()),m=Integer.parseInt(st.nextToken());
		line[][] l = new line[4][2*n];
		int[] qx = new int[m],qy=new int[m];
		for(int x=0;x<4;x++) {
			for(int y=0;y<2*n;y++) {
				l[x][y] = new line();
			}
		}
		for(int x=0;x<m;x++) {
			st = new StringTokenizer(r.readLine());
			int a = Integer.parseInt(st.nextToken())-1,b=Integer.parseInt(st.nextToken())-1;
			int[] ar = {a,b,a+b,a-b+n};
			int[] ar2 = {b,a,a,a};
			for(int i=0;i<4;i++) {
				l[i][ar[i]].put(ar2[i]);
			}
			qx[x] = a;
			qy[x]=b;
		}
		int[] count = new int[9];
		for(int x=0;x<m;x++) {
			int a = qx[x],b=qy[x];
			int[] ar = {a,b,a+b,a-b+n};
			int[] ar2 = {b,a,a,a};
			int s=0;
			for(int i=0;i<4;i++) {
				s+=l[i][ar[i]].g(ar2[i]);
			}
			count[s]++;
		}
		String sep = "";
		for(int x:count) {
			System.out.print(sep+x);
			sep = " ";
		}
		System.out.println();
	}
}