import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class ZValues {

	public static void main(String[] args) throws IOException {
		char[] line=new BufferedReader(new InputStreamReader(System.in)).readLine().toCharArray();
		int n=line.length;
		int[] zValues=zValues(line);
		zValues[0]=0;
//		System.out.println(Arrays.toString(zValues));
		boolean[] containsValue=new boolean[n];
		for (int i=0; i<n; i++) {
			if (zValues[i]+i<n)
				containsValue[zValues[i]]=true;
			else if (zValues[i]+i==n&&zValues[i]>0) {
				containsValue[zValues[i]-1]=true;
			}
		}
		for (int i=n-2; i>=0; i--)
			containsValue[i]|=containsValue[i+1];
//		System.out.println(Arrays.toString(containsValue));
		
		int max=0;
		for (int i=0; i<n; i++) {
			int zVal=zValues[i];
//			System.out.println(zVal+" "+i+" "+n+" "+containsValue[zVal]);
			if (containsValue[zVal]&&zVal+i==n)
				max=Math.max(max, zVal);
		}
		if (max==0) {
			System.out.println("Just a legend");
		}
		else {
			StringBuilder sb=new StringBuilder("");
			for (int i=0; i<max; i++) {
				sb.append(line[i]);
			}
			PrintWriter out=new PrintWriter(System.out);
			out.println(sb.toString());
			out.close();
		}
	}
	
	private static int[] zValues(char[] s) {
		int n=s.length;
		int[] z=new int[n];
		z[0]=s.length;
		int l=0, r=0;
		for (int i=1; i<n; i++) {
			if (i>r) {
				l=r=i;
				while (r<n&&s[r]==s[r-i])
					r++;
				
				z[i]=r-l;
				r--;
			}
			else {
				int k=i-l;
				if (z[k]<r-i+1) {
					z[i]=z[k];
				}
				else {
					l=i;
					while (r<n&&s[r-l]==s[r])
						r++;
					z[i]=r-l;
					r--;
				}
			}
		}
		return z;
	}

}