// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

const int N=514000;

const double PI=acos(-1.0);
struct vir{
    double re,im;
    vir( double _re=0, double _im=0 ):re(_re),im(_im){}
};
vir operator +( vir a, vir b ) { return vir(a.re+b.re,a.im+b .im); }
vir operator -( vir a, vir b ) { return vir(a.re-b.re,a.im-b .im); }
vir operator *( vir a, vir b ) { return vir(a.re*b.re-a.im*b .im,a.re*b.im+a.im*b.re); }
vir x1[2*N],x2[2*N];

int rev( int x, int len ) {
    int r=0,i;
    for ( i=0; i<len; i++,x>>=1 ) r=(r<<1)+(x&1);
    return r;
}
void change( vir *x, int len, int loglen ) {
    for ( int i=0; i<len; i++ )
        if ( rev(i,loglen)<i ) swap(x[rev(i,loglen)],x[i]);
}
void fft( vir *x, int len, int loglen ) {
    change(x,len,loglen);
    int i,j,s,t=1;
    for ( i=0; i<loglen; i++,t<<=1 ) {
        for ( s=0; s<len; s+=t+t ) {
            vir a,b,wo(cos(PI/t),sin(PI/t)),wn(1,0);
            for ( j=s; j<s+t; j++ ) {
                a=x[j]; b=x[j+t]*wn;
                x[j]=a+b; x[j+t]=a-b;
                wn=wn*wo;
            }
        }
    }
}
void dit_fft( vir *x, int len, int loglen ) {
    int i,j,s,t=len>>1;
    for ( i=0; i<loglen; i++,t>>=1 ) {
        for ( s=0; s<len; s+=t+t ) {
            vir a,b,wn(1,0),wo(cos(PI/t),-sin(PI/t));
            for ( j=s; j<s+t; j++ ) {
                a=x[j]+x[j+t]; b=(x[j]-x[j+t])*wn;
                x[j]=a; x[j+t]=b;
                wn=wn*wo;
            }
        }
    }
    change(x,len,loglen);
    for ( i=0; i<len; i++ ) x[i].re/=len;
}

void mul( int n, int a[], int b[], int c[] ) {

}


int n,m,k;
char s[N],t[N];
int pre[N],nxt[N];
bool ban[N];

void solve( char ch ) {
    const int INF=1e8;
    pre[0]=(s[0]==ch?0:-INF);
    REP1(i,1,n-1) {
        pre[i]=pre[i-1];
        if ( s[i]==ch ) pre[i]=i;
    }
    nxt[n-1]=(s[n-1]==ch?n-1:INF);
    for ( int i=n-2; i>=0; i-- ) {
        nxt[i]=nxt[i+1];
        if ( s[i]==ch ) nxt[i]=i;
    }
    int len=1,loglen=0;
    while ( len<=2*n ) {
        len*=2;
        loglen++;
    }
    REP(i,len) x1[i]=x2[i]=0;
    REP(i,n) if ( min(i-pre[i],nxt[i]-i)>k ) x1[i]=1;
    REP(i,m) if ( t[i]==ch ) x2[m-i-1]=1;
    fft(x1,len,loglen);
    fft(x2,len,loglen);
    REP(i,len) x1[i]=x1[i]*x2[i];
    dit_fft(x1,len,loglen);
    REP(i,n+m-1) {
        int v=round(x1[i].re);
        int p=i-m+1;
        if ( v && 0<=p && p<=n-m ) {
            //printf("%c: ban %d\n",ch,p);
            ban[p]=1;
        }
    }
}

int main() {
    RI(n,m,k);
    scanf("%s%s",s,t);
    solve('A');
    solve('T');
    solve('C');
    solve('G');
    int ans=0;
    REP(i,n-m+1) if ( !ban[i] ) ans++;
    printf("%d\n",ans);
    return 0;
}