import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProblemB {
	public static void main(String[] args) throws IOException {
		BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		String[] firstLine=reader.readLine().split(" ");
		int length=Integer.parseInt(firstLine[0]);
		int k=Integer.parseInt(firstLine[1]);
		String line=reader.readLine();
		int[] firstLocation=new int[26], lastLocation=new int[26];
		for (int i=0; i<26; i++) {
			firstLocation[i]=10000000;
		}
		for (int i=0; i<line.length(); i++) {
			firstLocation[line.charAt(i)-'A']=Math.min(firstLocation[line.charAt(i)-'A'], i);
			lastLocation[line.charAt(i)-'A']=i;
		}
		
		for (int i=0; i<line.length(); i++) {
			int count=0;
			for (int j=0; j<26; j++) {
				if (firstLocation[j]<=i&&lastLocation[j]>=i) {
					count++;
				}
			}
			if (count>k) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
}