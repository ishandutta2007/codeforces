import java.util.Scanner;

public class NewYearTransportation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int t = s.nextInt();
		int[] portals = new int[n+1];
		for (int i = 1; i<= n-1; i++) portals[i] = s.nextInt();
		boolean[] visited = new boolean[n+1];
		boolean found =false;
		int cur = 1;
		while (!visited[cur]) {
			visited[cur] = true;
			if (cur==t){ 
				found = true;
				break;
			
			}
			cur = portals[cur]+cur;
//			System.out.println(cur);
		}
		if (found) System.out.println("YES");
		else System.out.println("NO");

	}

}