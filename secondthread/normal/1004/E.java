import java.util.*;

public class d {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(), k=s.nextInt();
		ArrayList<Edge>[] edges=new ArrayList[n];
		for (int i=0; i<n; i++) edges[i]=new ArrayList<>();
		for (int i=1; i<n; i++) {
			int a=s.nextInt()-1, b=s.nextInt()-1, c=s.nextInt();
			edges[a].add(new Edge(b, c));
			edges[b].add(new Edge(a, c));
		}
		int[] from0=bfs(edges, 0);
		int maxIndex=0;
		for (int i=0; i<n; i++) if (from0[i]>from0[maxIndex]) maxIndex=i;
		int[] from1=bfs(edges, maxIndex);
		for (int i=0; i<n; i++) if (from1[i]>from1[maxIndex]) maxIndex=i;
		int[] from2=bfs(edges, maxIndex);
		int diamLen=from1[maxIndex];
		boolean[] ignore=new boolean[n];
		for (int i=0; i<n; i++) ignore[i]=from1[i]+from2[i]==diamLen;

		int[] tempDist=new int[n];
		Arrays.fill(tempDist, -1);
		
		ArrayList<Integer> diam=new ArrayList<>();
		ArrayList<Integer> trickleLength=new ArrayList<>();
		diam.add(maxIndex);
		int lastSpot=maxIndex;
		int nextSpot=getNextDiam(edges, -1, lastSpot, ignore);
		trickleLength.add(0);
		while (nextSpot!=-1) {
			diam.add(nextSpot);
			trickleLength.add(getMaxDist(edges, nextSpot, ignore, tempDist));
			int temp=getNextDiam(edges, lastSpot, nextSpot, ignore);
			lastSpot=nextSpot;
			nextSpot=temp;
		}
		//System.out.println("Diam: "+diam);
		//System.out.println("Trickle: "+trickleLength);
		
		int frontLength=0, backLength=0;
		for (int i=k-1; i<diam.size()-1; i++) {
			backLength+=distTo(diam.get(i), diam.get(i+1), edges);
		}
		int min=backLength;
		for (int i=1; i+k<=diam.size(); i++) {
			frontLength+=distTo(diam.get(i-1), diam.get(i), edges);
			backLength-=distTo(diam.get(i+k-2), diam.get(i+k-1), edges);
			//System.out.println("Front: "+frontLength+", Back: "+backLength);
			min=Math.min(min, Math.max(frontLength, backLength));
		}
		for (int i:trickleLength)min=Math.max(i, min);
		System.out.println(min);
	}
	
	static int distTo(int from, int to, ArrayList<Edge>[] edges) {
		for (Edge e:edges[from]) if (e.to==to) return e.cost;
		return -999;
	}
	
	static int getNextDiam(ArrayList<Edge>[] edges, int last, int cur, boolean[] ignore) {
		if (last==-1) {
			for (Edge e:edges[cur]) if (ignore[e.to]) return e.to;
		}
		else {
			for (Edge e:edges[cur]) if (ignore[e.to]&&e.to!=last) return e.to;
		}
		return -1;
	}
	
	static int getMaxDist(ArrayList<Edge>[] edges, int from, boolean[] ignore, int[] dist) {
		int n=edges.length;
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		bfs.add(from);
		dist[from]=0;
		int maxDist=0;
		while (!bfs.isEmpty()) {
			int nextNode=bfs.remove();
			maxDist=Math.max(maxDist, dist[nextNode]);
			for (Edge e:edges[nextNode]) {
				if (ignore[e.to]||dist[e.to]!=-1)
					continue;
				dist[e.to]=dist[nextNode]+e.cost;
				bfs.add(e.to);
			}
		}
		return maxDist;
	}
	
	static int[] bfs(ArrayList<Edge>[] edges, int from) {
		int n=edges.length;
		int[] dist=new int[n];
		Arrays.fill(dist, -1);
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		bfs.add(from);
		dist[from]=0;
		while (!bfs.isEmpty()) {
			int nextNode=bfs.remove();
			int lastDist=dist[nextNode];
			for (Edge e:edges[nextNode]) {
				if (dist[e.to]==-1) {
					dist[e.to]=lastDist+e.cost;
					bfs.add(e.to);
				}
			}
		}
		return dist;
	}
	
	static class Edge {
		int to, cost;
		public Edge(int to, int cost) {
			this.to=to;
			this.cost=cost;
		}
	}
}