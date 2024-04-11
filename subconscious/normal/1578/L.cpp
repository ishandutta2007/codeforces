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
const ld PI=acos(-1);
const int N=1e6+5;
int T,n,a[N];
bool is[N];
int main(){
    for(int i=2;i<N;++i)
        if(!is[i])for(int j=i*2;j<N;j+=i)is[j]=1;
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d",&n);
        int sum=0;
        rep(i,n)scanf("%d",a+i),sum+=a[i];
        if(is[sum]){printf("%d\n",n);rep(i,n)printf("%d%c",i," \n"[i==n]);}
        else{
            rep(i,n)if(is[sum-a[i]]){
                {
                    printf("%d\n",n-1);
                    rep(j,n)if(j!=i)printf("%d ",j);puts("");}
                break;
            }
        }

    }
    return 0;
}
/*
a<=b
c<=d
ac+db-(ad+bc)
=a(c-d)+b(d-c)
=(d-c)(b-a)>=0


*/