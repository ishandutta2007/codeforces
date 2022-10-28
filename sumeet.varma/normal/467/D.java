//package Practise.Round267Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class FedorAndEssay {

	static HashMap<String,Integer> map;
	static ArrayList<Integer> g[];
	static ArrayList<Node> how;
	static Node dp[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w = new PrintWriter(System.out);

		int m = Integer.parseInt(br.readLine()),count = -1;
		map = new HashMap<String,Integer>();  
		
		how = new ArrayList<Node>();
		int id[] = new int[m];
		
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++){
			String nxt = st1.nextToken().toLowerCase();
			if(map.containsKey(nxt))
				id[i] = map.get(nxt);
			else{
				map.put(nxt, ++count);
				id[i] = count;
				int r = 0;
				int s = nxt.length();
				for(int j=0;j<s;j++)
					if(nxt.charAt(j) == 'r')
						r++;
				how.add(new Node(r,s,count));
			}
			
		}
		
		g = new ArrayList[300001];
		for(int i=0;i<g.length;i++)
			g[i] = new ArrayList<Integer>();
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			String u = st2.nextToken().toLowerCase();
			String v = st2.nextToken().toLowerCase();
			int l,r;
		
			if(map.containsKey(u))
				l = map.get(u);
			else{
				map.put(u, ++count);
				l = count;
				int s = u.length();
				int cc = 0;
				for(int j=0;j<s;j++)
					if(u.charAt(j) == 'r')
						cc++;
				how.add(new Node(cc,s,count));
			}
			
			if(map.containsKey(v))
				r = map.get(v);
			else{
				map.put(v, ++count);
				r = count;
				int s = v.length();
				int cc = 0;
				for(int j=0;j<s;j++)
					if(v.charAt(j) == 'r')
						cc++;
				how.add(new Node(cc,s,count));
			}
			
			g[r].add(l);
		}
	
		long rans = 0, lans = 0;
		dp = new Node[count+1];
		
		Collections.sort(how);
		
		for(int i=0;i<=count;i++){
			if(dp[how.get(i).id] == null){
				dp[how.get(i).id] = how.get(i).copy();
				dfs(how.get(i),how.get(i).id);
			}
		}

		for(int i=0;i<m;i++){
			rans += dp[id[i]].rCount;
			lans += dp[id[i]].length;
		}
		
		w.println(rans + " " + lans);
		w.close();
	}
	
	static void dfs(Node root,int curr){
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			if(dp[g[curr].get(i)] == null){
				dp[g[curr].get(i)] = root.copy();
				dp[g[curr].get(i)].id = g[curr].get(i);
				dfs(root,g[curr].get(i));
			}
		}
	}
	
	
	static public class Node implements Comparable<Node>{
		int rCount,length,id;
		Node(int r,int l,int i){
			rCount = r;
			length = l;
			id = i;
		}
		public int compareTo(Node o){
			if(rCount != o.rCount)
				return Integer.compare(rCount, o.rCount);
			return Integer.compare(length, o.length);
		}
		public Node copy(){
			return new Node(rCount,length,id);
		}
		public String toString(){
			return id + " " + rCount + " " + length;
		}
	}
}