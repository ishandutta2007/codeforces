import java.io.BufferedReader;
import java.io.InputStreamReader;


public class B092 {
	public static void main(String[] args) throws Exception {
		BufferedReader r= new BufferedReader(new InputStreamReader(System.in));
		StringBuffer line = new StringBuffer(r.readLine());
		int count = line.length()-1;
		for(int x = line.length()-1;x>0;x--) {
			if(line.charAt(x)=='1') {
				count++;
				line.setCharAt(x, '0');
				int y;
				for(y = x-1;line.charAt(y)=='1';y--) {
					line.setCharAt(y,'0');
					if(y==0) {
						line.insert(0, '0');
						y++;
						count++;
					}
				}
				line.setCharAt(y,'1');
			}
		}
		System.out.println(count);
	}
}