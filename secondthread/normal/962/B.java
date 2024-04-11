import java.util.ArrayList;
import java.util.Scanner;

public class F {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt(), a=fs.nextInt(), b=fs.nextInt();
		int orig=a+b;
		
		char[] line=fs.next().toCharArray();
		ArrayList<Integer> sizes=new ArrayList<>();
		int size=0;
		for (char c:line) {
			if (c=='*') {
				sizes.add(size);
				size=0;
			}
			else {
				size++;
			}
		}
		sizes.add(size);
		for (int i:sizes) {
			int big=(i+1)/2, small=i-big;
			int bigger=Math.max(a, b), smaller=Math.min(a, b);
			
			b=Math.max(0, bigger-big);
			a=Math.max(0, smaller-small);
		}
		
		System.out.println(orig-a-b);
	}

}