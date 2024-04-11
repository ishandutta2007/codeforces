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
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N=3e5+5,mod=1e9+7;
int a[N],n,T,z;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        bool flag=1;
        rep(i,n)if(a[i]!=0){flag=0;break;}
        if(flag){puts("0");continue;}
        int l=1,r=n;
        while(a[l]==0)++l;while(a[r]==0)--r;
        flag=1;
        for(int i=l;i<=r;++i)if(a[i]==0){flag=0;break;}
        if(flag){puts("1");continue;}
        puts("2");
    }
    return 0;
}
/*
3 
1 -1 
1 1
-1 2
*/