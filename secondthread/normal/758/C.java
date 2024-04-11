import java.util.Scanner;

public class Questions {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int height=s.nextInt();
		int width=s.nextInt();
		long numberOfQuestions=s.nextLong();
		int yMainPerson=s.nextInt();
		int xMainPerson=s.nextInt();
		long[][] students=new long[width][height];
		
		int studentsFirstCount=width*height;
		int studentsSecondCount=Math.max(0, width*(height-2));
		long fullPasses=numberOfQuestions/(studentsFirstCount+studentsSecondCount);
		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				students[x][y]+=fullPasses;
			}
			for (int y=1; y<height-1; y++) {
				students[x][y]+=fullPasses;
			}
		}
		for (long[] array:students) {
			for (long l:array) {
				//System.err.println(l);
			}
		}
		
		numberOfQuestions%=(studentsFirstCount+studentsSecondCount);
		
		for (int y=0; y<height; y++) {
			for (int x=0; x<width; x++) {
				if (numberOfQuestions>0) {
					numberOfQuestions--;
					students[x][y]++;
				}
			}
		}
		for (int y=height-2; y>0; y--) {
			for (int x=0; x<width; x++) {
				if (numberOfQuestions>0) {
					numberOfQuestions--;
					students[x][y]++;
				}
			}
		}
		
		
		long max=-1, min=Long.MAX_VALUE;
		for (long[] array:students) {
			for (long l:array) {
				//System.err.print(l+" ");
				max=Math.max(max, l);
				min=Math.min(min, l);
			}
			//System.err.println();
		}
		
		System.out.println(max+" "+min+" "+students[xMainPerson-1][yMainPerson-1]);

	}

}