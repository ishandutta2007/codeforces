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
 
const int N=505,mod=1e9+7;
 
int n,k,res,ok,p,X,a[N][N],mark[N];
queue<int> q;
 
int main(){
    cin>>n>>k;
    if((n&1) && (k&1)==0) return cout<<-1,0;
    res=(n+k-1)/k;
    if(res==2 && res*k>n) res++;
    if((res*k-n)&1) res++;
    f(i,1,n+1) q.push(i);
    if((k&1)==(n&1) && (n&1)){
        cout<<"? ";
        f(i,0,k){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
        cin>>p;
        X^=p;
    }
    while(q.size() && q.size()!=k){
        fill(mark,mark+N,0);
        vector<int> v1,v2;
        int u=min(int(q.size()/2),min(n-k,k));
        if(q.size()-u*2<k && q.size()-u*2>0 && (q.size()-k)%2==0) minm(u,int(q.size()-k)/2);
        f(i,0,u){
            v1.pb(q.front());
            mark[q.front()]=1;
            q.pop();
        }
        f(i,0,u){
            v2.pb(q.front());
            mark[q.front()]=1;
            q.pop();
        }
        f(i,1,n+1)
            if(v1.size()<k && !mark[i])
                v1.pb(i),v2.pb(i);
        cout<<"? ";
        f(i,0,k) cout<<v1[i]<<" ";
        cout<<endl;
        cin>>p;
        X^=p;
        cout<<"? ";
        f(i,0,k) cout<<v2[i]<<" ";
        cout<<endl;
        cin>>p;
        X^=p;
    }
    if(q.size()){
        cout<<"? ";
        f(i,0,k){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
        cin>>p;
        X^=p;
    }
    cout<<"! "<<X<<endl;
}