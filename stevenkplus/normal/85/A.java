import java.util.Scanner;


public class A085 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int i;
		for(i = 0;i+4<=n;i+=4) System.out.print("aabb");
		if(n%4>=2) System.out.print("aa");
		if(n%2==1) System.out.print("c");
		System.out.println();
		for(i = 0;i+4<=n;i+=4) System.out.print("bbaa");
		if(n%4>=2) System.out.print("bb");
		if(n%2==1) System.out.print("c");
		System.out.println();
		System.out.print("e");
		for(i = 1;i+4<=n;i+=4) System.out.print("ffgg");
		if((n-1)%4>=2) System.out.print("ff");
		if(n%2==0) System.out.print("d");
		System.out.println();
		System.out.print("e");
		for(i = 1;i+4<=n;i+=4) System.out.print("ggff");
		if((n-1)%4>=2) System.out.print("gg");
		if(n%2==0) System.out.print("d");
		System.out.println();
	}
}