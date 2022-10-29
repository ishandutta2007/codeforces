#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid ((l+r)>>1)

using namespace std;
const int mod=998244353;
int n,f[2][2][2][2][2][2][2][2][2],g[2][2][2][2][2][2][2][2][2];
char s[200005];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void inc(int &x,int y)
{
	if((x+=y)>=mod) x-=mod;
}

void trf(int nw)
{
	rep(ga,0,1) rep(gb,0,1) rep(gc,0,1)
		rep(ca,0,1) rep(cb,0,1) rep(cc,0,1)
			rep(ta,ca,1) rep(tb,cb,1) rep(tc,cc,1) 
				g[ga][gb][gc][ca][cb][cc][ta][tb][tc]=0;

	rep(ga,0,1) rep(gb,0,1) rep(gc,0,1)
		rep(ca,0,1) rep(cb,0,1) rep(cc,0,1)
			rep(ta,ca,1) rep(tb,cb,1) rep(tc,cc,1) 
				if(f[ga][gb][gc][ca][cb][cc][ta][tb][tc])
				{
					int tmp=f[ga][gb][gc][ca][cb][cc][ta][tb][tc];
					rep(a,0,1) rep(b,0,1) rep(c,0,1)
					{
						int _ga=(a^nw)?a>nw:ga;
						int _gb=(b^nw)?b>nw:gb;
						int _gc=(c^nw)?c>nw:gc;
						
						int ab=a^b,ac=a^c,bc=b^c;

						int _ca=(ca+ab+ac)>>1;
						int _cb=(cb+ab+bc)>>1;
						int _cc=(cc+ac+bc)>>1; 

						int _ta=(_ca || (ca+ab+ac>bc) || (ca+ab+ac==bc && ta));
						int _tb=(_cb || (cb+ab+bc>ac) || (cb+ab+bc==ac && tb));
						int _tc=(_cc || (cc+ac+bc>ab) || (cc+ac+bc==ab && tc));

						inc(g[_ga][_gb][_gc][_ca][_cb][_cc][_ta][_tb][_tc],tmp);
					}
				}
	rep(ga,0,1) rep(gb,0,1) rep(gc,0,1)
		rep(ca,0,1) rep(cb,0,1) rep(cc,0,1)
			rep(ta,ca,1) rep(tb,cb,1) rep(tc,cc,1) 
				f[ga][gb][gc][ca][cb][cc][ta][tb][tc]=g[ga][gb][gc][ca][cb][cc][ta][tb][tc];
}	

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	f[0][0][0][0][0][0][0][0][0]=1;
	repd(i,n,1) trf(s[i]-'0');
	int ans=0;
	rep(ca,0,1) rep(cb,0,1) rep(cc,0,1)
		inc(ans,f[0][0][0][ca][cb][cc][1][1][1]);
	printf("%d\n",ans);
	return 0;
}