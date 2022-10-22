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

int n,t,a[N];

int main(){
    cin>>t;
    while(t--){
        int c=0;
        cin>>n;
        f(i,0,n){
            cin>>a[i];
            a[i]=(a[i]%2);
            if(a[i]==0) c++;
        }
        if(n/2!=c && (n+1)/2!=c) cout<<-1<<endl;
        else{
            int ans=0;
            if(c!=n/2){
                f(i,0,n) a[i]=1-a[i];
            }
            //f(i,0,n) cout<<a[i]<<" "; cout<<endl;
            int c0=0,c1=0;
            f(i,0,n){
                if(a[i]==0){
                    c0++;
                    ans+=max(0,c1-c0);
        			//cout<<c1-c0<<endl;
                }
                else{
                	ans+=max(0,c0-c1);
                    c1++;
                }
            }
            if(n%2==0){
            	int res=0;
            	f(i,0,n) a[i]=1-a[i];
            	int c0=0,c1=0;
            	f(i,0,n){
                if(a[i]==0){
                    c0++;
                    res+=max(0,c1-c0);
                }
                else{
                	res+=max(0,c0-c1);
                    c1++;
                }
            	}
            	minm(ans,res);
			}
            cout<<ans<<endl;
        }
    }
}