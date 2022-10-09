import java.util.Scanner;

public class OkabeLaboratory {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[][] grid=new int[n][n];
		for (int y=0; y<n; y++)
			for (int x=0; x<n; x++)
				grid[x][y]=s.nextInt();
		int[][] columnCountingSort=new int[n][100001];//col, number
		int[][] rowCountingSort=new int[n][100001];//row, number
		for (int y=0; y<n; y++) {
			for (int x=0; x<n; x++) {
				columnCountingSort[x][grid[x][y]]++;
				rowCountingSort[y][grid[x][y]]++;
			}
		}
		
		for (int y=0; y<n; y++) {
			mid:for (int x=0; x<n; x++) {
				int total=grid[x][y];
				if (total==1) {
					continue;
				}
				for (int i=1; i<total; i++) {
					if (columnCountingSort[x][i]>0&&rowCountingSort[y][total-i]>0) {
						continue mid;
					}
				}
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");
	}

}