import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class G {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt();
		Simplex s=new Simplex(n);
		Node[] nodes=new Node[n];
		DisjointSet dj=new DisjointSet(n);
		for (int i=0; i<n; i++) nodes[i]=new Node(i);
		for (int i=0; i<m; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1, w=fs.nextInt();
			dj.union(from, to);
			nodes[from].edges.add(new Edge(nodes[to], w));
			nodes[from].indegreeMinusOutdegree-=w;
			nodes[to].indegreeMinusOutdegree+=w;
		}
		double[] obj=new double[n];
		for (int i=0; i<n; i++) obj[i]=nodes[i].indegreeMinusOutdegree;
//		for (int i=0; i<n; i++) {
//			double[] arr=new double[n];
//			arr[i]=1;
//			s.addLowerBound(arr, 1);
//		}
		for (Node nn:nodes) {
			for (Edge e:nn.edges) {
				int to=e.to.id;
				int from=nn.id;
				double[] arr=new double[n];
				arr[from]=1;
				arr[to]=-1;
				s.addLowerBound(arr, 1);
			}
		}
		s.setObjective(obj);
		for (int i=0; i<n; i++) {
			if (dj.find(i)==i) {
				double[] arr=new double[n];
				arr[i]=1;
				s.addEquality(arr, 20);
			}
		}
		s.solve();
		
		//hope everything is an int...
		for (double d:s.solution) {
			System.out.print(Math.round(d)+" ");
		}
		System.out.println();
	}
	static class Node {
		ArrayList<Edge> edges=new ArrayList<>();
		long indegreeMinusOutdegree=0;
		int id;
		public Node(int id) {
			this.id=id;
		}
	}
	
	static class Edge {
		Node to;
		long w;
		
		public Edge(Node to, long w) {
			this.to=to;
			this.w=w;
		}
	}
	
	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; else s[a] = b;
			return true;
		}
	}

	
	static class Simplex {
		static double eps = 1e-9, oo = 1e16, max;
		int m, n;
		int[] B, N;
		double[][] mat;
		ArrayList<Double> vals;
		ArrayList<double[]> eqs;
		double[] obj, solution;

		public Simplex(int n) {
			this.n = n;
			obj = new double[n];
			Arrays.fill(obj, 1.0);
			eqs = new ArrayList<>();
			vals = new ArrayList<>();
		}

		public void setObjective(double[] obj) {
			this.obj = obj;  clearSolution();
		}

		public void addUpperBound(double[] equation, double value) {
			double[] eq = new double[equation.length];
			for (int i = 0; i < equation.length; i++)
				eq[i] = equation[i];
			eqs.add(eq);
			vals.add(value);
		}

		public void addLowerBound(double[] equation, double value) {
			double[] eq = new double[equation.length];
			for (int i = 0; i < equation.length; i++)
				eq[i] = -equation[i];
			eqs.add(eq);
			vals.add(-value);
		}

		//#
		public void addEquality(double[] equation, double value) {
			addLowerBound(equation, value);
			addUpperBound(equation, value);
		}

		public void addUpperBound(int idx, double value) {
			double[] eq = new double[n];
			eq[idx] = 1;
			addUpperBound(eq, value);
		}

		public void addLowerBound(int idx, double value) {
			double[] eq = new double[n];
			eq[idx] = 1;
			addLowerBound(eq, value);
		}

		public void addEquality(int idx, double value) {
			double[] eq = new double[n];
			eq[idx] = 1;
			addEquality(eq, value);
		}
		//$

		void clearSolution() { solution = null; }

		double[] getSolution() {
			if (solution == null)  solve();
			return solution;
		}

		double getMaximum() {
			if (solution == null)  solve();
			return max;
		}

		private void buildMatrix() {
			m = eqs.size();
			N = new int[n + 1];
			B = new int[m];
			mat = new double[m + 2][n + 2];
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					mat[i][j] = eqs.get(i)[j];
			for (int i = 0; i < m; i++) {
				B[i] = n + i;
				mat[i][n] = -1;
				mat[i][n + 1] = vals.get(i);
			}
			for (int j = 0; j < n; j++)
				mat[m][j] = -obj[N[j] = j];
			mat[m + 1][n] = -(N[n] = -1);
		}

		private void pivot(int r, int s) {
			for (int i = 0; i < m + 2; i++)
				if (i != r)
					for (int j = 0; j < n + 2; j++)
						if (j != s)
							mat[i][j] -= mat[r][j] * mat[i][s] / mat[r][s];
			for (int j = 0; j < n + 2; j++)
				if (j != s)
					mat[r][j] /= mat[r][s];
			for (int i = 0; i < m + 2; i++)
				if (i != r)
					mat[i][s] /= -mat[r][s];
			mat[r][s] = 1.0 / mat[r][s];
			B[r] = B[r] ^ N[s] ^ (N[s] = B[r]);
		}

		private boolean runSimplex(int phase) {
			int x = phase == 1 ? m + 1 : m;
			while (true) {
				int s = -1;
				for (int j = 0; j <= n; j++)
					if ((phase != 2 || N[j] != -1)
							&& (s == -1 || mat[x][j] < mat[x][s] || mat[x][j] == mat[x][s] && N[j] < N[s]))
						s = j;
				if (mat[x][s] >= -eps)
					return true;
				int r = -1;
				for (int i = 0; i < m; i++) {
					if (mat[i][s] < eps)
						continue;
					if (r == -1 || mat[i][n + 1] / mat[i][s] < mat[r][n + 1] / mat[r][s]
							|| mat[i][n + 1] / mat[i][s] == mat[r][n + 1] / mat[r][s] && B[i] < B[r])
						r = i;
				}
				if (r == -1)
					return false;
				pivot(r, s);
			}
		}

		private double solve() {
			buildMatrix();
			int r = 0;
			for (int i = 1; i < m; i++)
				if (mat[i][n + 1] < mat[r][n + 1])
					r = i;
			if (mat[r][n + 1] <= -eps) {
				pivot(r, n);
				if (!runSimplex(1) || mat[m + 1][n + 1] < -eps)
					return max = -oo;
				for (int i = 0; i < m; i++)
					if (B[i] == -1) {
						int s = -1;
						for (int j = 0; j <= n; j++)
							if (s == -1 || mat[i][j] < mat[i][s] || mat[i][j] == mat[i][s] && N[j] < N[s])
								s = j;
						pivot(i, s);
					}
			}
			solution = new double[n];
			if (!runSimplex(2))
				return max = oo;
			solution = new double[n];
			for (int i = 0; i < m; i++)
				if (B[i] < n)
					solution[B[i]] = mat[i][n + 1];
			return max = mat[m][n + 1];
		}
	}


	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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