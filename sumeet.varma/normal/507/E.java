//package Practise.Round287Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BreakingGood {

	static int n, m;
	static ArrayList<Integer> g[];
	static int parent[], dist[], badCount[], parentRoadId[], x[], y[], z[];
	static boolean vis[], inPath[];

	@SuppressWarnings("unchecked")
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w = new PrintWriter(System.out);

		StringTokenizer st1 = new StringTokenizer(br.readLine());
		n = ip(st1.nextToken());
		m = ip(st1.nextToken());

		g = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++)
			g[i] = new ArrayList<Integer>();

		x = new int[m + 1];
		y = new int[m + 1];
		z = new int[m + 1];

		for (int i = 1; i <= m; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			x[i] = ip(st2.nextToken());
			y[i] = ip(st2.nextToken());
			z[i] = ip(st2.nextToken());

			g[x[i]].add(y[i]);
			g[x[i]].add(z[i]);
			g[x[i]].add(i);
			g[y[i]].add(x[i]);
			g[y[i]].add(z[i]);
			g[y[i]].add(i);
		}

		vis = new boolean[n + 1];
		vis[1] = true;
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(1);
		dist = new int[n + 1];
		dist[1] = 0;

		while (!q.isEmpty()) {
			int curr = q.remove();
			int len = g[curr].size();
			for (int i = 0; i < len; i = i + 3) {
				int next = g[curr].get(i);
				if (!vis[next]) {
					vis[next] = true;
					dist[next] = dist[curr] + 1;
					q.add(next);
				}
			}
		}

		badCount = new int[n + 1];
		Arrays.fill(badCount, -1);

		parent = new int[n + 1];
		parentRoadId = new int[n + 1];

		badCount[1] = 0;
		parent[1] = parentRoadId[1] = 0;

		solve(n);

		inPath = new boolean[m + 1];
		int curr = n;
		while (curr != 1) {
			inPath[parentRoadId[curr]] = true;
			curr = parent[curr];
		}

		int k = 0;
		for (int i = 1; i <= m; i++) {
			if (inPath[i] && z[i] == 0)
				k++;
			if (!inPath[i] && z[i] == 1)
				k++;
		}

		w.println(k);
		for (int i = 1; i <= m; i++) {
			if (inPath[i] && z[i] == 0)
				w.println(x[i] + " " + y[i] + " " + 1);
			if (!inPath[i] && z[i] == 1)
				w.println(x[i] + " " + y[i] + " " + 0);
		}

		w.close();
	}

	public static int solve(int curr) {
		if (badCount[curr] == -1) {
			int s = g[curr].size();
			int min = 100000000;
			for (int i = 0; i < s;) {
				int nxt = g[curr].get(i++);
				int type = g[curr].get(i++);
				int id = g[curr].get(i++);
				if (dist[nxt] + 1 == dist[curr]) {
					int now = solve(nxt) + 1 - type;
					if (now < min) {
						min = now;
						parent[curr] = nxt;
						parentRoadId[curr] = id;
					}
				}
			}
			badCount[curr] = min;
		}
		return badCount[curr];
	}

	public static int ip(String s) {
		return Integer.parseInt(s);
	}
}