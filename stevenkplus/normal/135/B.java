import java.util.Scanner;

public class B135 {
	static class point {
		int x;
		int y;
		int n;
		public point(int a, int b,int c) {
			x = a;
			y = b;
			n = c+1;
		}
		public point min(point o) {
			return new point(x-o.x,y-o.y,0);
		}
		public boolean equals(point o ) {
			return x == o.x&&y==o.y;
		}
		public int mag() {
			return x*x+y*y;
		}
		public boolean perp(point o) {
			return x*o.x+y*o.y==0;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		point[] p = new point[8];
		for (int x = 0; x < 8; x++) {
			p[x] = new point(in.nextInt(), in.nextInt(),x);
		}
		for(int a = 0;a<8;a++) {
			for(int b = 0;b<a;b++) {
				for(int c = 0;c<b;c++) {
					for(int d = 0;d<c;d++) {
						point[] sq= new point[4],rect=new point[4];
						int i=0,j=0;
						for(int x = 0;x<8;x++) {
							if(x==a||x==b||x==c||x==d) sq[i++] = p[x]; else rect[j++] = p[x];
						}
						if(isSquare(sq)&&isRect(rect)) {
							System.out.println("YES");
							for(point o:sq) {
								System.out.print(o.n+" ");
							}
							System.out.println();
							for(point o:rect) {
								System.out.print(o.n+" ");
							}
							return;
						}
					}
				}
			}
		}
		System.out.println("NO");
	}
	static boolean isRect(point[] p) {
		for(int i = 0;i<3;i++) {
			if(i!=0) {
				point c = p[3];
				p[3] = p[2];
				p[2] = p[1];
				p[1]=c;
			}
			point diff1 = p[1].min(p[0]);
			point diff2 = p[2].min(p[3]);
			point diff3 = p[3].min(p[0]);
			point diff4 = p[2].min(p[1]);
			if(diff1.equals(diff2)&&diff3.equals(diff4)&&diff1.perp(diff3)) return true;
		}
		return false;
	}	static boolean isSquare(point[] p) {
		for(int i = 0;i<3;i++) {
			if(i!=0) {
				point c = p[3];
				p[3] = p[2];
				p[2] = p[1];
				p[1] = c;
			}
			point diff1 = p[1].min(p[0]);
			point diff2 = p[2].min(p[3]);
			point diff3 = p[3].min(p[0]);
			point diff4 = p[2].min(p[1]);
			if(diff1.equals(diff2)&&diff3.equals(diff4)&&diff1.perp(diff3)) {
				if(diff1.mag()==diff3.mag()) return true;
			}
		}
		return false;
	}
}