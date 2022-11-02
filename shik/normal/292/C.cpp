// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<string> sol;
int ip[12],now[4];
void add() {
    static char buf[20];
    sprintf(buf,"%d.%d.%d.%d",now[0],now[1],now[2],now[3]);
    sol.push_back(buf);
}
void sep( int p, int q, int l ) {
    if ( p==l && q==4 ) {
        add();
        return;
    }
    if ( p==l || q==4 ) return;
    int x=0;
    for ( int i=0; i<3 && p+i<l; i++ ) {
        x=x*10+ip[p+i];
        if ( x>255 ) break;
        now[q]=x;
        sep(p+i+1,q+1,l);
        if ( x==0 ) break;
    }
}
void check( int p ) {
    int l=2*p;
    for ( int i=0; i<p; i++ ) ip[l-i-1]=ip[i];
    sep(0,0,l);
    l=2*p-1;
    for ( int i=0; i<p-1; i++ ) ip[l-i-1]=ip[i];
    sep(0,0,l);
}
void gen( int p ) {
    if ( p>=2 && p<=6 ) check(p);
    if ( p==6 ) return;
    for ( int i=0; i<10; i++ ) {
        ip[p]=i;
        gen(p+1);
    }
}
void predo() {
    gen(0);
}
int n,a[10],vis[130],ucs;
bool can[130];
vector<string> ans;
int main()
{
    predo();
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    can['.']=1;
    for ( int i=0; i<n; i++ ) can[a[i]+'0']=1;
    FOR(it,sol) {
        ucs++;
        bool ok=1;
        int cnt=0;
        for ( int i=0; i<SZ(*it) && ok; i++ ) {
            int c=(*it)[i];
            ok&=can[c];
            if ( vis[c]!=ucs ) cnt++,vis[c]=ucs;
        }
        if ( ok && cnt==n+1 ) ans.push_back(*it);
    }
    printf("%d\n",SZ(ans));
    FOR(it,ans) puts(it->c_str());
    return 0;
}