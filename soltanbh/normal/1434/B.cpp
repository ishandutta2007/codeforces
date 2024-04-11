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

const int N=1e6+99;

int n,a[N],b[N];
vector<int> v;
set<int> s;

int main(){
    cin>>n;
    f(i,0,2*n){
        char c;
        cin>>c;
        if(c=='+') v.pb(i);
        else{
            if(v.size()==0) return cout<<"NO",0;
            int x;
            cin>>x;
            a[v[v.size()-1]]=x;
            v.pop_back();
            b[i]=x;
        }
    }
    f(i,0,2*n){
        if(a[i]) s.insert(a[i]);
        else{
            int x=*s.begin();
            if(x!=b[i]) return cout<<"NO",0;
            s.erase(x);
        }
    }
    cout<<"YES"<<endl;
    f(i,0,2*n) if(a[i]) cout<<a[i]<<" ";
}