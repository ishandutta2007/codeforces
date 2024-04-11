import java.io.BufferedReader;
import java.io.InputStreamReader;


public class C135 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String l = r.readLine();
		int n = l.length();
		int z = 0,o = 0,q = 0;
		for(char c:l.toCharArray()) {
			if(c=='0') z++;
			else if (c=='1') o++;
			else q++;
		}
		if(n%2==1) o--;
		boolean[] poss = new boolean[4];
		if(o+q>z) {
			poss[3] = true;
		}
		if(z+q>o) {
			poss[0] = true;
		}
		if(o+q>=z&&q+z>=o) {
			char c = l.charAt(n-1);
			if(c=='?') {
				if(o+q!=z) {
					 poss[2] = true;
				}
				if(z+q!=o) {
					poss[1] = true;
				}
			}
			else if(c=='1')
				poss[1] = true;
			else if (c=='0')
				poss[2] = true;
		}
		for(int x = 0;x<4;x++) {
			if(poss[x]) {
				String s ="00"+Integer.toString(x,2);
				System.out.println(s.substring(s.length()-2));
			}
		}
	}
}