import java.util.Scanner;


public class B134 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int min = Integer.MAX_VALUE;
		if(n==1)
			min = 0;
		b:for(int a = 1;a<=n/2;a++) {
			int x = a,y = n-a;
			int c = 1;
			while(!(x==1&& y==1)) {
				int m = y%x;
				if(m==0) {
					if(x==1) {
					c--;
					m++;
					} else continue b;
				}
				c+=y/x;
				y = x;
				x = m;
			}
			if(c<min) min = c;
		}
		
		System.out.println(min);
	}
}