#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+2;

int q,u,v;

int main(){
    cin>>q;
    f(i,0,q){
        vector<int> v1, v2;
        int ans=1,a,b;
        cin>>u>>v;
        if(v<u) ans=0;
        f(i,0,30)
            if(u&(1<<i))
                v1.pb(i);
        f(i,0,30)
            if(v&(1<<i))
                v2.pb(i);
        if(v1.size()<v2.size()) ans=0;
        else{
            f(i,0,v2.size())
                if(v2[i]<v1[i])
                    ans=0;
        } 
        cout<<(ans ? "YES" : "NO")<<'\n';
    }
}