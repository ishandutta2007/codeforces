import java.util.Scanner;

public class Subsequences {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt(), k=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt()-1;
		long[][] dp=new long[k+1][n];
		BIT[] bits=new BIT[k+1];
		for (int i=0; i<bits.length; i++) bits[i]=new BIT(n);
		for (int i=0; i<n; i++) {
			for (int kk=0; kk<=k; kk++) {
				if (kk==0) {
					dp[0][a[i]]=1;
				}
				else {
					dp[kk][a[i]] = bits[kk-1].read(a[i]-1);
				}
				bits[kk].update(a[i], dp[kk][a[i]]);
			}
		}
		long ans=0;
		for (int end=0; end<n; end++) ans+=dp[k][end];
		System.out.println(ans);
	}

	static class BIT {
		int n;
		long[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new long[n + 2];
		}
		
		long read(int i) {
			i++;
			long sum = 0;
			while (i > 0) {
				sum += tree[i];
				i -= i & -i;
			}
			return sum;
		}
		
		void update(int i, long val) {
			i++;
			while (i <= n) {
				tree[i] += val;
				i += i & -i;
			}
		}

	}

}



// 1 2 3 5 4
//       x