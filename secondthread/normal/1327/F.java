import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;

/*

 */
public class F {

	static final int mod=998244353;
	static int[] ands, ls, rs;

	public static void main(String[] args) {
		FS fs=new FS();
		int n=fs.ni();
		int nBits=fs.ni();
		int nRanges=fs.ni();
		Range[] ranges=new Range[nRanges];
		ands=new int[nRanges];
		ls=new int[nRanges];
		rs=new int[nRanges];
		for (int i=0; i<nRanges; i++)
			ranges[i]=new Range(fs.ni()-1, fs.ni()-1, fs.ni());
		Arrays.sort(ranges);
		long ans=1;
		for (int i=0; i<nBits; i++) {
			long waysForBit=go(ranges, i, n);
			ans=(ans*waysForBit)%mod;
		}
		System.out.println(ans);
	}

	// returns the number of ways of doing this range
	static long go(Range[] rangesFull, int bit, int n) {
		int nRanges=rangesFull.length;
		Range[] ranges=new Range[nRanges];
		for (int i=0; i<nRanges; i++)
			ranges[i]=new Range(rangesFull[i].l, rangesFull[i].r, (rangesFull[i].and&(1<<bit))==0?0:1);
		int nOneRanges=0;
		for (Range r:ranges)
			if (r.and==1)
				nOneRanges++;
		Range[] oneRanges=new Range[nOneRanges], zeroRanges=new Range[ranges.length-nOneRanges];
		int nZeroRanges=nOneRanges=0;
		for (Range r:ranges)
			if (r.and==0)
				zeroRanges[nZeroRanges++]=r;
			else
				oneRanges[nOneRanges++]=r;

		int[] oneRangesDelta=new int[n+1];
		for (Range r:oneRanges) {
			oneRangesDelta[r.l]++;
			oneRangesDelta[r.r+1]--;
		}
		for (int i=1; i<=n; i++)
			oneRangesDelta[i]+=oneRangesDelta[i-1];
		for (int i=0; i<=n; i++)
			oneRangesDelta[i]=oneRangesDelta[i]==0?0:1;
		int[] oneRangeCS=new int[n+1];
		for (int i=1; i<=n; i++)
			oneRangeCS[i]=oneRangeCS[i-1]+oneRangesDelta[i-1];

		// check to see if any zero ranges are illegal (inside a one range)
		for (Range r:zeroRanges) {
			int length=r.r-r.l+1;
			int ones=oneRangeCS[r.r+1]-oneRangeCS[r.l];
			// we won't be able to put a 0 here...
			if (length==ones)
				return 0;
		}

		int[] compressed=new int[n];
		Arrays.fill(compressed, -1);
		int compressedInd=0;
		for (int i=0; i<n; i++) {
			if (oneRangesDelta[i]==0)
				compressed[i]=compressedInd++;
		}
		int[] nextCompressed=new int[n], prevCompressed=new int[n];
		int nextInd=n;
		for (int i=n-1; i>=0; i--) {
			if (oneRangesDelta[i]==0)
				nextInd=i;
			nextCompressed[i]=nextInd;
		}
		nextInd=-1;
		for (int i=0; i<n; i++) {
			if (oneRangesDelta[i]==0)
				nextInd=i;
			prevCompressed[i]=nextInd;
		}
		for (Range r:zeroRanges) {
			r.l=compressed[nextCompressed[r.l]];
			r.r=compressed[prevCompressed[r.r]];
		}

		return zeroSolve(zeroRanges, compressedInd);
	}

	static long zeroSolve(Range[] ranges, int n) {
		int[] firstEndIndAfter=new int[n];
		int rangesInd=ranges.length-1;
		int latestStart=n;
		for (int i=n-1; i>=0; i--) {
			firstEndIndAfter[i]=latestStart;
			while (rangesInd>=0&&ranges[rangesInd].l==i) {
				latestStart=Math.min(latestStart, ranges[rangesInd].r);
				rangesInd--;
			}
		}
		// dp[i] = number of ways if I have placed a zero at index i
		long[] dp=new long[n+1];
		long[] cs=new long[n+2];
		dp[n]=1;
		cs[n]=1;
		cs[n+1]=0;
		for (int i=n-1; i>=0; i--) {
			int lastPlace=firstEndIndAfter[i];
			long ways=0;
			ways=(cs[i+1]-cs[lastPlace+1]);
			if (ways<0)
				ways+=mod;
			dp[i]=ways;
			cs[i]=cs[i+1]+dp[i];
			if (cs[i]>=mod)
				cs[i]-=mod;
		}
		long ans=0;
		for (int i=0; i<=latestStart; i++) {
			ans=ans+dp[i];
			if (ans>=mod)
				ans-=mod;
		}
		return ans;
	}

	static class Range implements Comparable<Range> {
		int l, r, and;

		public Range(int l, int r, int and) {
			this.l=l;
			this.r=r;
			this.and=and;
		}

		public int compareTo(Range o) {
			return Integer.compare(l, o.l);
		}

		public String toString() {
			return "l: "+l+" r: "+r+" and: "+and;
		}
	}

	static class FS {
		private byte[] inbuf=new byte[1024];
		public int lenbuf=0, ptrbuf=0;
		InputStream is=System.in;

		private int readByte() {
			if (lenbuf==-1)
				throw new InputMismatchException();
			if (ptrbuf>=lenbuf) {
				ptrbuf=0;
				try {
					lenbuf=is.read(inbuf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf<=0)
					return -1;
			}
			return inbuf[ptrbuf++];
		}

		private boolean isSpaceChar(int c) {
			return !(c>=33&&c<=126);
		}

		private int skip() {
			int b;
			while ((b=readByte())!=-1&&isSpaceChar(b))
				;
			return b;
		}

		private double nd() {
			return Double.parseDouble(ns());
		}

		private char nc() {
			return (char) skip();
		}

		private String ns() {
			int b=skip();
			StringBuilder sb=new StringBuilder();
			while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
				sb.appendCodePoint(b);
				b=readByte();
			}
			return sb.toString();
		}

		private char[] ns(int n) {
			char[] buf=new char[n];
			int b=skip(), p=0;
			while (p<n&&!(isSpaceChar(b))) {
				buf[p++]=(char) b;
				b=readByte();
			}
			return n==p?buf:Arrays.copyOf(buf, p);
		}

		private char[][] nm(int n, int m) {
			char[][] map=new char[n][];
			for (int i=0; i<n; i++)
				map[i]=ns(m);
			return map;
		}

		private int[] na(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=ni();
			return a;
		}

		private int ni() {
			int num=0, b;
			boolean minus=false;
			while ((b=readByte())!=-1&&!((b>='0'&&b<='9')||b=='-'))
				;
			if (b=='-') {
				minus=true;
				b=readByte();
			}

			while (true) {
				if (b>='0'&&b<='9') {
					num=num*10+(b-'0');
				} else {
					return minus?-num:num;
				}
				b=readByte();
			}
		}

		private long nl() {
			long num=0;
			int b;
			boolean minus=false;
			while ((b=readByte())!=-1&&!((b>='0'&&b<='9')||b=='-'))
				;
			if (b=='-') {
				minus=true;
				b=readByte();
			}

			while (true) {
				if (b>='0'&&b<='9') {
					num=num*10+(b-'0');
				} else {
					return minus?-num:num;
				}
				b=readByte();
			}
		}
	}

}