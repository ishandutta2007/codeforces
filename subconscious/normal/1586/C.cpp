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
int T,n,m;
vector<string>a;
int is[N];
int main(){
    T=1;
    rep(Cas,T){
        cin>>n>>m;
        rep(i,m)is[i]=0;
        a=vector<string>(n,"");
        rep(i,n){
            cin>>a[i-1];
        }
        rep(i,m-1){
            rep(j,n-1)if(a[j+1-1][i-1]=='X'&&a[j-1][i+1-1]=='X'){
                is[i]=1;break;
            }
        }
        int q;
        rep(i,m)is[i]+=is[i-1];
        cin>>q;
        rep(i,q){
            int x,y;
            cin>>x>>y;
            int cnt=is[y-1]-is[x-1];
            cout<<(cnt>0?"No":"Yes")<<"\n";
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