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
const int N=2e5+5;
const ll inf=1e18+7;
int n,T,a[N];
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        int l=-1,r=n+1;
        rep(i,n-1)if(a[i]==a[i+1]){
            if(l==-1)l=i;
            r=i+1;
        }
        if(l==-1||l+1==r){
            puts("0");
        }else{
            printf("%d\n",max(1,r-l-2));
        }
    }
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