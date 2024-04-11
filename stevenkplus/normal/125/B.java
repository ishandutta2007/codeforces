import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B125 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int count = 0;
		String line = r.readLine();
		StringBuffer strb = new StringBuffer();
		int start = 0;
		boolean open = true;
		for (int x = 0; x < line.length(); x++) {
			if (line.charAt(x) == '/')
				open = false;
			if (line.charAt(x) == '>') {
				if (!open)
					count--;
				for (int i = 0; i < count; i++) {
					strb.append("  ");
				}
				if(open) count++;
				strb.append(line.substring(start,x+1));
				strb.append('\n');
				start = x+1;
				open = true;
			}
		}
		System.out.println(strb.toString());
	}
}