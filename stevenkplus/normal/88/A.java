import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A088 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		ArrayList<String> ar = new ArrayList<String>(
				Arrays.asList("C, C#, D, D#, E, F, F#, G, G#, A, B, H"
						.split(",\\s*")));
		int[] aar = new int[5];
		for (int x = 0; x   <3  ; x++) {
			aar[x] = ar.indexOf(in.next());
		}
		aar[3]=aar[4]=Integer.MAX_VALUE;
		Arrays.sort(aar);
		aar[3] = aar[0] + 12;
		aar[4]=aar[1]+12;
		for (int x = 0; x   <3  ; x++) {
			int d1 = aar[x+1]-aar[x],d2=aar[x+2]-aar[x+1];
			if(d1==4&&d2==3) {
				System.out.println("major");
				return;
			}
			if(d1==3&&d2==4) {
				System.out.println("minor");
				return;
			}
		}
		System.out.println("strange");
	}
}