import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;

public class MinimalString {
	
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String input=s.nextLine();
		LinkedList<Integer> original=new LinkedList<Integer>();
		ArrayList<Integer> sorted=new ArrayList<>(input.length());
		int[] countingSort=new int[300];
		for (int i=0; i<input.length(); i++) {
			original.add((int) input.charAt(i));
			sorted.add((int)input.charAt(i));
			countingSort[input.charAt(i)]++;
		}
		
		Collections.sort(sorted);
		
		Stack<Integer> stack=new Stack<Integer>();
		LinkedList<Integer> toPrint=new LinkedList<>();

		int minInOriginal=0;
		while (!original.isEmpty()) {
			if (stack.isEmpty()) {
				stack.push(original.remove());
				countingSort[stack.peek()]--;
			}
			else {
				while (countingSort[minInOriginal]==0) {
					minInOriginal++;
				}
				if (stack.peek()<=minInOriginal) {
					toPrint.add(stack.pop());
				}
				else {
					stack.push(original.remove());
					countingSort[stack.peek()]--;
				}
			}
		}
		while (!stack.isEmpty()) {
			toPrint.add(stack.pop());
		}
		for (int i:toPrint) {
			System.out.print((char)i);
		}
	}

}