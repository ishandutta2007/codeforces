import java.io.*;
import java.util.*;

public class OvernightDance {
	
	public static HashMap<Integer, ArrayList<Integer>> children;
	public static int n;
	public static int[][] circles;
	public static int[] parent;
	public static boolean[] seen;
	public static double ans;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(bf.readLine());
		StringTokenizer st;
		circles = new int[n][3]; //x y r
		
		parent = new int[n]; //next closest parent
		Arrays.fill(parent, -1);
		double[] parsize = new double[n];
		children = new HashMap<Integer, ArrayList<Integer>>(); //children of a circle

		for (int i = 0; i < n; i++) {
			children.put(i, new ArrayList<Integer>());
			parsize[i] = Double.MAX_VALUE;
		}
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(bf.readLine());
			circles[i][0] = Integer.parseInt(st.nextToken());
			circles[i][1] = Integer.parseInt(st.nextToken());
			circles[i][2] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (circles[j][2] > circles[i][2]) continue;
				if (i == j) continue;
				double cur = Math.pow(circles[i][0]-circles[j][0],2) + Math.pow(circles[i][1]-circles[j][1], 2);
				cur = Math.sqrt(cur);
				if (cur < circles[i][2]) {
					children.get(i).add(j);
					if (circles[i][2] < parsize[j]) {
						parent[j] = i;
						parsize[j] = circles[i][2];
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ArrayList<Integer> np = new ArrayList<Integer>();
			ArrayList<Integer> cur = children.get(i);
			for (int j = 0; j < cur.size(); j++) {
				if (parent[cur.get(j)] == i) {
					np.add(cur.get(j));
				}
			}
			children.put(i, np);
		}
		seen = new boolean[n];
		ans = 0;
		for (int i = 0; i < n; i++) {
			if (parent[i] == -1)
				recurse(i, 0);
		}
//		System.out.println(Arrays.toString(parent));
//		System.out.println(children);
		System.out.printf("%.10f\n", ans);
	}
	public static void recurse(int i, int num) {
//		System.out.println(i + " " + num);
		if (seen[i]) return;
		seen[i] = true;
		if (num == 0 || num %2 == 1) {
			ans += Math.pow(circles[i][2], 2)*Math.PI;
		}
		else {
			ans -= Math.pow(circles[i][2], 2)*Math.PI;
		}
		for (int n: children.get(i)) {
			recurse(n, num+1);
		}
		
	}

}