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

int n,t,k,ans,p[N];
string s;
set<pair<int,int> > S;

void add(int x){
    if(s[x]=='W'){
        S.insert(mp(0,x));
        return ;
    }
    S.insert(mp(1+(s[x-1]=='W'),x));
}
int main(){
    cin>>t;
    while(t--){
        vector<int> v;
        int tl=0;
        ans=0;
        S.clear();
        cin>>n>>k;
        cin>>s;
        s='L'+s;
        f(i,1,n+1){ tl+=(s[i]=='L'); if(s[i]=='W') ans+=1+(s[i-1]=='W'); }
        minm(k,tl);
        if(tl==n) cout<<max(k*2-1,0)<<endl;
        else{
            int mv=0;
            ans+=k*2;
            f(i,1,n+1){
                if(mv==0 || s[i]=='W') p[i]=0;
                else{
                    p[i]=p[i-1]+1;
                    if(i<n && s[i+1]=='W') v.pb(p[i]);
                }
                if(s[i]=='W') mv=1;
            }
            sort(v.begin(),v.end());
            v.pb(n+1);
            f(i,0,v.size()){
                if(i) v[i]+=v[i-1];
                if(k<v[i]){ ans+=i; break; }
            }
            cout<<ans<<endl;
        }
    }
}