#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck
#define y0 fuxk
#define x1 fxck
#define y1 fxxk
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-9;
int x0,y0,x1,y1,x2,y2;
set<pr> st;
int main(){
    scanf("%d%d%d%d%d%d",&x0,&y0,&x1,&y1,&x2,&y2);
    int ans=0x3f3f3f3f,X,Y;
    for(int i=0;i<=1000;++i)
        for(int j=0;j<=1000;++j){
            int tmp=abs(x0-i)+abs(y0-j)+abs(x1-i)+abs(y1-j)+abs(x2-i)+abs(y2-j)+1;
            if(tmp<ans)ans=tmp,X=i,Y=j;
        }
    for(int i=min(x0,X);i<=max(x0,X);++i)st.insert(mp(i,y0));
    for(int j=min(y0,Y);j<=max(y0,Y);++j)st.insert(mp(X,j));
    for(int i=min(x1,X);i<=max(x1,X);++i)st.insert(mp(i,y1));
    for(int j=min(y1,Y);j<=max(y1,Y);++j)st.insert(mp(X,j));
    for(int i=min(x2,X);i<=max(x2,X);++i)st.insert(mp(i,y2));
    for(int j=min(y2,Y);j<=max(y2,Y);++j)st.insert(mp(X,j));
    st.insert(mp(X,Y));
    printf("%d\n",st.size());
    for(auto p:st)printf("%d %d\n",p.first,p.second);
    return 0;
}