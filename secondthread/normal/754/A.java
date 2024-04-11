import java.util.Scanner;


public class ArraySplitting {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int length=s.nextInt();
		int[] array=new int[length];
		int zeros=0;
		for (int i=0; i<array.length; i++) {
			array[i]=s.nextInt();
			if (array[i]==0) {
				zeros++;
			}
		}
		
		if (zeros==length) {
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
		System.out.println(length-zeros);
		for (int i=0; i<length; i++) {
			int start=i;
			if (i==0&&array[0]==0) {
				while (array[i]==0) {
					i++;
				}
			}
			
			while (i+1<length&&array[i+1]==0) {
				i++;
			}
			System.out.println((start+1)+" "+(i+1));
		}
	}

}