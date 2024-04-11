import java.util.ArrayList;
import java.util.Scanner;

public class B5 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		ArrayList<String> ar = new ArrayList<String>();
		int max = 0;
		while (in.hasNextLine()) {
			String lin = in.nextLine();
			if (lin.equals("quitt"))
				break;
			ar.add(lin);
			if (lin.length() > max)
				max = lin.length();
		}
		StringBuffer buff = new StringBuffer();
		for (int x = 0; x < max + 2; x++) {
			buff.append('*');
		}
		buff.append('\n');
		boolean left = true;
		for (String s : ar) {
			int l = s.length();
			int loff, rightoff;
			int diff = max - l;
			if (diff % 2 == 0) {
				loff = rightoff = diff / 2;
			} else {
				if (left) {
					rightoff = (loff = diff / 2) + 1;
				} else
					loff = (rightoff = diff / 2) + 1;
				left = !left;
			}
			buff.append('*');
			for (int x = 0; x < loff; x++) {
				buff.append(' ');
			}
			buff.append(s);
			for (int x = 0; x < rightoff; x++) {
				buff.append(' ');
			}
			buff.append("*\n");
		}

		for (int x = 0; x < max + 2; x++) {
			buff.append('*');
		}
		buff.append('\n');
		System.out.print(buff.toString());
	}
}