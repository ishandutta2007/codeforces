import java.util.Scanner;
public class project{
    public static void main(String[]args){
	Scanner s = new Scanner(System.in);
	int n =s.nextInt(), k=s.nextInt();
	long l = n;
	long r = k;
	int sum = 0;
	for (int i = 0; i <= 31; i++) {
	    for (int j = 0; j <= 19; j++) {
	        long kk = 1;
	        for (int q = 0; q < i; q++) kk *= 2;
	        for (int q = 0; q < j; q++) kk *= 3;
	        if (l <= kk && kk <= r) sum++;
	    }
	}
	System.out.println(sum);
    }
}