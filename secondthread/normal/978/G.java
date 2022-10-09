import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class G {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nDays=fs.nextInt();
		int nExams=fs.nextInt();
		Exam[] exams=new Exam[nExams];
		for (int i=0; i<nExams; i++) exams[i]=new Exam(fs.nextInt(), fs.nextInt(), fs.nextInt());
//		Arrays.sort(exams);
		
		//src, days, exams, sink
		List<Edge>[] graph=createGraph(1+nDays+nExams+1);
		for (int i=0; i<nDays; i++)
			addEdge(graph, 0, 1+i, 1);
		int totalFlow=0;
		int examIndex=0;
		for (Exam e:exams) {
			totalFlow+=e.daysToStudy+1;
			for (int i=e.startDay; i<e.endDay; i++) {
				addEdge(graph, 1+i, 1+nDays+examIndex, 1);
			}
			addEdge(graph, 1+e.endDay, 1+nDays+nExams, 1);
			addEdge(graph, 1+nDays+examIndex, 1+nDays+nExams, e.daysToStudy);
			examIndex++;
		}
		int flow=maxFlow(graph, 0, 1+nDays+nExams);
//		System.out.println("flow: "+flow);
		if (flow!=totalFlow)
			System.out.println(-1);
		else {
			outer:for (int day=0; day<nDays; day++) {
				for (Edge e:graph[1+day]) {
					if (e.flow>0) {
						if (e.to==1+nDays+nExams) {
							System.out.print(nExams+1+" ");
						}
						else {
							System.out.print(e.to-nDays+" ");
						}
						continue outer;
					}
				}
				System.out.print(0+" ");
			}
		}
		
	}
	
	static class Exam implements Comparable<Exam> {
		int startDay, endDay, daysToStudy;
		public Exam(int startDay, int endDay, int daysToStudy) {
			this.startDay=startDay-1;
			this.endDay=endDay-1;
			this.daysToStudy=daysToStudy;
		}

		public int compareTo(Exam o) {
			return daysToStudy-o.daysToStudy;
		}
	}

	static class Edge {
        int to, oppisiteIndex, capacity, flow;

        public Edge(int to, int oppisiteIndex, int capacity) {
            this.to = to;
            this.oppisiteIndex = oppisiteIndex;
            this.capacity = capacity;
        }
    }

    public static List<Edge>[] createGraph(int nodes) {
        List<Edge>[] graph = new List[nodes];
        for (int i = 0; i < nodes; i++)
            graph[i] = new ArrayList<>();
        return graph;
    }

    public static Edge addEdge(List<Edge>[] graph, int from, int to, int capacity) {
        Edge toAdd=new Edge(to, graph[to].size(), capacity);
        graph[from].add(toAdd);
        graph[to].add(new Edge(from, graph[from].size() - 1, 0));
        return toAdd;
    }

    static boolean dinicBfs(List<Edge>[] graph, int src, int dest, int[] distanceToNode) {
        Arrays.fill(distanceToNode, -1);
        distanceToNode[src] = 0;
        int[] queue = new int[graph.length];//works because everything will get added at most once
        int queueIndex = 0;
        queue[queueIndex++] = src;
        for (int i = 0; i < queueIndex; i++) {
            int nextNode = queue[i];
            for (Edge e : graph[nextNode]) {
                if (distanceToNode[e.to] < 0 && e.flow < e.capacity) {
                    distanceToNode[e.to] = distanceToNode[nextNode] + 1;
                    queue[queueIndex++] = e.to;
                }
            }
        }
        return distanceToNode[dest] >= 0;
    }

    static int dinicDfs(List<Edge>[] graph, int[] ptr, int[] distanceTo, int sink, int nodeToCheck, int flow) {
        if (nodeToCheck == sink)
            return flow;
        for (; ptr[nodeToCheck] < graph[nodeToCheck].size(); ++ptr[nodeToCheck]) {
            Edge e = graph[nodeToCheck].get(ptr[nodeToCheck]);
            if (distanceTo[e.to] == distanceTo[nodeToCheck] + 1 && e.flow < e.capacity) {
                int flowChange = dinicDfs(graph, ptr, distanceTo, sink, e.to, Math.min(flow, e.capacity - e.flow));
                if (flowChange > 0) {
                    e.flow += flowChange;
                    graph[e.to].get(e.oppisiteIndex).flow -= flowChange;
                    return flowChange;
                }
            }
        }
        return 0;
    }

    public static int maxFlow(List<Edge>[] graph, int src, int dest) {
        int flow = 0;
        int[] dist = new int[graph.length];
        while (dinicBfs(graph, src, dest, dist)) {
            int[] ptr = new int[graph.length];
            while (true) {
                int flowChange = dinicDfs(graph, ptr, dist, dest, src, Integer.MAX_VALUE);
                if (flowChange == 0)
                    break;
                flow += flowChange;
            }
        }
        return flow;
    }

    static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}

	
}