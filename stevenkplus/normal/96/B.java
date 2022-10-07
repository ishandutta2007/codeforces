import java.util.Scanner;


public class B096 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int l = in.nextInt();
		for(int x = 2;x<1<<11;x++) {
			String kk =Integer.toBinaryString(x).substring(1).replaceAll("0","4").replaceAll("1", "7");
			int pop = 0;
			for(int i = 0;i<kk.length();i++) {
				if(kk.charAt(i)=='4') pop++;
			}
			if(pop*2!=kk.length()) continue;
			long k = Long.parseLong(kk);
			if(k>=l){
				System.out.println(k);
				return;
			}
		}
//		int length = l.length();
//		if(length%2==1) {
//			length++;
//			String max = "";
//			for(int x = 0;x<length/2;x++) {
//				max = "4"+max+"7";
//				
//			}
//			System.out.println(max);
//			return;
//		}
//		String max = "";
//		for(int x = 0;x<length/2;x++) {
//			max = "7"+max+"4";
//			
//		}
//		if(Integer.parseInt(l)>Integer.parseInt(max)) {
//			String min = "";
//			for(int x = 0;x<length/2+1;x++) {
//				min = "4"+min+"7";
//				
//			}
//			System.out.println(min);
//			return;
//		}
//		String res = "";
//		int fours = length/2,sevens = length/2;
//		for(int x = 0;x<length;x++) {
//			if(fours==0) {
//				sevens--;
//				res+="7";
//			}
//			if(l.charAt(x)=='4') {
//				
//			}
//			else if(l.charAt(x)<'4') {
//				res+=4;
//				fours--;
//				break;
//			}
//		}
//		
	}
}