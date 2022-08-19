//package hel2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E1 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int R = ni(), B = ni();
		if(R != B){
			out.println("No");
			return;
		}
		int[][] cor = new int[R][];
		int[][] cob = new int[B][];
		for(int i = 0;i < R;i++){
			cor[i] = na(2);
		}
		for(int i = 0;i < B;i++){
			cob[i] = na(2);
		}
		int n = R;
		int[] ord = new int[n];
		for(int i = 0;i < n;i++)ord[i] = i;
		outer:
		do{
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(hasCommonPoint(cor[i], cob[ord[i]], cor[j], cob[ord[j]]))continue outer;
				}
			}
			out.println("Yes");
			return;
		}while(nextPermutation(ord));
		out.println("No");
	}
	
	public static boolean hasCommonPoint(long ax, long ay, long bx, long by, long cx, long cy, long dx, long dy)
	{
		long c1 = (cx-ax)*(by-ay)-(cy-ay)*(bx-ax);
		long c2 = (dx-ax)*(by-ay)-(dy-ay)*(bx-ax);
		if(c1 < 0 && c2 < 0 || c1 > 0 && c2 > 0)return false;
		long d1 = (ax-cx)*(dy-cy)-(ay-cy)*(dx-cx);
		long d2 = (bx-cx)*(dy-cy)-(by-cy)*(dx-cx);
		if(d1 < 0 && d2 < 0 || d1 > 0 && d2 > 0)return false;
		if(c1 == 0 && c2 == 0 && d1 == 0 && d2 == 0){
			if(ax == bx && ay == by){
				return (cx-ax)*(dx-ax)+(cy-ay)*(dy-ay) <= 0;
			}else{
				long posc = (cx-ax)*(bx-ax)+(cy-ay)*(by-ay);
				long posd = (dx-ax)*(bx-ax)+(dy-ay)*(by-ay);
				long den = (bx-ax)*(bx-ax)+(by-ay)*(by-ay);
	//			return Math.max(0, Math.min(posc, posd)) <= Math.min(den, Math.max(posc, posd));
	//			return Math.min(posc, posd) <= den && 0 <= Math.max(posc, posd);
				return (posc <= den || posd <= den) && (0 <= posc || 0 <= posd);
			}
		}
		return true;
	}
	
	public static boolean hasCommonPoint(int[] a, int[] b, int[] c, int[] d){ return hasCommonPoint(a[0], a[1], b[0], b[1], c[0], c[1], d[0], d[1]);}
	public static boolean hasCommonPoint(long[] a, long[] b, long[] c, long[] d){ return hasCommonPoint(a[0], a[1], b[0], b[1], c[0], c[1], d[0], d[1]);}

	
	public static boolean nextPermutation(int[] a) {
		int n = a.length;
		int i;
		for (i = n - 2; i >= 0 && a[i] >= a[i + 1]; i--)
			;
		if (i == -1)
			return false;
		int j;
		for (j = i + 1; j < n && a[i] < a[j]; j++)
			;
		int d = a[i];
		a[i] = a[j - 1];
		a[j - 1] = d;
		for (int p = i + 1, q = n - 1; p < q; p++, q--) {
			d = a[p];
			a[p] = a[q];
			a[q] = d;
		}
		return true;
	}

	
	void run() throws Exception
	{
//		int n = 10, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n*4; i++) {
//			sb.append(gen.nextInt(20)-10 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E1().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}