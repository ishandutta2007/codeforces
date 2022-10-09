import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Conversion {

	private static long converted=-1;
	
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		long base=s.nextLong();
		String baseAsString=base+"";
		s.nextLine();
		StringBuilder unconverted=new StringBuilder(s.nextLine());
		Queue<Long> pieces=new LinkedList<Long>();
		while (unconverted.length()!=0) {
			for (int length=baseAsString.length(); length>0; length--) {
				if (canRemove(unconverted, base-1, unconverted.length()-length,length)) {
					pieces.add(converted);
					remove(unconverted, length);
					break;
				}
			}
		}
		for (Long l:pieces) {
			//System.out.println(l);
		}
		long total=0;
		long power=0;
		while (!pieces.isEmpty()) {
			long exponent=1;
			for (int i=0; i<power; i++) {
				exponent*=base;
			}
			total+=pieces.remove()*exponent;
			power++;
		}
		System.out.println(total);
	}
	
	private static boolean canRemove(StringBuilder unconverted, long maxValue, int index, int length) {
		String substring=unconverted.substring(Math.max(0, index), Math.min(index+length, unconverted.length()));
		if (substring.startsWith("0")&&length!=1) {
			return false;
		}
		converted=Long.parseLong(substring);
		return converted<=maxValue;
	}
	
	private static void remove(StringBuilder unconverted, int length) {
		for (int i=0; i<length&&unconverted.length()!=0; i++) {
			unconverted.deleteCharAt(unconverted.length()-1);
		}
	}

}