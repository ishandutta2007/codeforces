import java.util.Scanner;

public class Lightbulbs {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String line=s.nextLine();
		String[] colors=new String[4];
		for (int i=0; i<4; i++) {
			colors[i]="";
		}
		for (int i=0; i<line.length(); i++) {
			colors[i%4]+=line.charAt(i);
		}
		
		int redIndex=0, blueIndex=0, yellowIndex=0, greenIndex=0;
		int[] lightsOut=new int[4];
		for (int i=0; i<lightsOut.length; i++) {
			lightsOut[i]=0;
			for (int lightInRow=0; lightInRow<colors[i].length(); lightInRow++) {
				if (colors[i].charAt(lightInRow)=='!') {
					lightsOut[i]++;
				}
			}
		}
		
		for (int i=0; i<4; i++) {
			if (colors[i].contains("R")) {
				redIndex=i;
			}
			if (colors[i].contains("B")) {
				blueIndex=i;
			}
			if (colors[i].contains("Y")) {
				yellowIndex=i;
			}
			if (colors[i].contains("G")) {
				greenIndex=i;
			}
		}
		
		System.out.println(lightsOut[redIndex]+" "+lightsOut[blueIndex]+" "+lightsOut[yellowIndex]+" "+lightsOut[greenIndex]);
	}

}