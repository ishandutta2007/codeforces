import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Stars {

	public static int maxBrightness;
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));	
		String[] line=in.readLine().split(" ");
		int numberOfStars=Integer.parseInt(line[0]);
		int numberOfQueries=Integer.parseInt(line[1]);
		maxBrightness=Integer.parseInt(line[2])+1;
		ArrayList<Star>[][] stars=new ArrayList[100][100];
		for (int i=0; i<100; i++) {
			for (int j=0; j<100; j++) {
				stars[i][j]=new ArrayList<Star>();
			}
		}
		for (int i=0; i<numberOfStars; i++) {
			line=in.readLine().split(" ");
			int x=Integer.parseInt(line[0])-1;
			int y=Integer.parseInt(line[1])-1;
			int startingBrightness=Integer.parseInt(line[2]);
			stars[x][y].add(new Star(startingBrightness));
		}
		int[][][] pointBrightness=new int[100][100][maxBrightness];
		for (int x=0; x<100; x++) {
			for (int y=0; y<100; y++) {
				for (int t=0; t<maxBrightness; t++) {
					pointBrightness[x][y][t]=0;
					for (Star s:stars[x][y])
						pointBrightness[x][y][t]+=s.getBrightnessAtTime(t);
				}
			}
		}
		
		int[][][] rowSumBrightness=new int[100][100][maxBrightness];
		for (int y=0; y<100; y++) {
			for (int t=0; t<maxBrightness; t++) {
				rowSumBrightness[0][y][t]=pointBrightness[0][y][t];
			}
			
			for (int x=1; x<100; x++) {
				for (int t=0; t<maxBrightness; t++) {
					rowSumBrightness[x][y][t]=rowSumBrightness[x-1][y][t]+pointBrightness[x][y][t];
				}
			}
		}
		
		int[][][] squareSumBrightness=new int[100][100][maxBrightness];
		for (int x=0; x<100; x++) {
			for (int t=0; t<maxBrightness; t++) {
				squareSumBrightness[x][0][t]=rowSumBrightness[x][0][t];
			}
			for (int y=1; y<100; y++) {
				for (int t=0; t<maxBrightness; t++) {
					squareSumBrightness[x][y][t]=squareSumBrightness[x][y-1][t]+rowSumBrightness[x][y][t];
				}
			}
		}

		for (int queries=0; queries<numberOfQueries; queries++) {
			line=in.readLine().split(" ");
			int t=Integer.parseInt(line[0])%maxBrightness;
			int x1=Integer.parseInt(line[1])-1;
			int y1=Integer.parseInt(line[2])-1;
			int x2=Integer.parseInt(line[3])-1;
			int y2=Integer.parseInt(line[4])-1;
			long total=squareSumBrightness[x2][y2][t]-(x1>0?squareSumBrightness[x1-1][y2][t]:0)-(y1>0?squareSumBrightness[x2][y1-1][t]:0)+
					(x1>0&&y1>0?squareSumBrightness[x1-1][y1-1][t]:0);
			System.out.println(total);
		}
	}

}

class Star {
	private int startingBrightness;
	public Star(int startingBrightness) {
		this.startingBrightness=startingBrightness;
	}
	
	
	public int getBrightnessAtTime(int t) {
		return (t+startingBrightness)%Stars.maxBrightness;
		
	}
}