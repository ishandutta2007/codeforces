import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {

	static boolean correct(ArrayList<Character> a) {
		int count=0;
		for (char c:a) {
			if (c=='(') count++;
			else {
				count--;
				if (count<0) return false;
			}
		}
		return count==0;
	}
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] a=fs.next().toCharArray();
		int firstClose=-1, lastOpen=-1;
		for (int i=0; i<n; i++)
			if (a[i]=='(') lastOpen=i;
		for (int i=n-1; i>=0; i--)
			if (a[i]==')') firstClose=i;
		ArrayList<Character> orig=new ArrayList<>(), op1=new ArrayList<>(), op2=new ArrayList<>();
		for (char c:a)
			orig.add(c);
		if (correct(orig)) {
			System.out.println("Yes");
			return;
		}
		if (firstClose!=-1) {
			for (int i=0; i<n; i++)
				if (i!=firstClose)
					op1.add(a[i]);
			op1.add(')');
			if (correct(op1)) {
				System.out.println("Yes");
				return;
			}
		}
		if (lastOpen!=-1) {
			op2.add('(');
			for (int i=0; i<n; i++)
				if (i!=lastOpen)
					op2.add(a[i]);
			if (correct(op2)) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
}