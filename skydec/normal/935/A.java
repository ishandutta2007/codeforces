import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int n=input.nextInt();
		int ans=0;
		for(int i=1;i<n;i++)if(n%i==0)++ans;
		System.out.printf("%d\n", ans);
	}
}