#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=2e5+5,inf=1e9+7;
int n;
int que(int w){
    printf("? %d\n",w);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    if(ret==0)ret=inf;
    return ret;
}
void answer(int s){
    printf("! %d\n",s);
    fflush(stdout);
}
int main(){
    scanf("%d",&n);
    int l=0,r=n*2001;
    while(l+1<r){
        int mid=(l+r)/2;
        if(que(mid)==1)r=mid;else l=mid;
    }
    int ans=r;
    for(int i=2;i<=n;++i){
        int low=r-(i-1);
        int w=(low/i+(low%i!=0));
        ans=min(1ll*ans,1ll*que(w)*w);
    }
    answer(ans);
    return 0;
}
/*
10 5
2 8
6 7
3 7
2 10
7 10
9 5
9 1
5 3
4 5

6 5
1 5
2 1
3 5
4 3
6 5
*/