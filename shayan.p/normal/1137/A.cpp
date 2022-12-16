// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e3+10,mod=1e9+7;
const ll inf=1e18;

int n,m,a[maxn][maxn],ls[2][maxn][maxn],gr[2][maxn][maxn],ans[maxn][maxn];
pii arr[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++)
	    cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++)
	    arr[j]={a[i][j],j};
	sort(arr,arr+m);
	int CNT=0;
	for(int j=0;j<m;j++)
	    ls[0][i][arr[j].S]=(CNT=CNT+(j==0?0:arr[j-1].F!=arr[j].F));
	CNT=0;
	for(int j=m-1;j>=0;j--)
	    gr[0][i][arr[j].S]=(CNT=CNT+(j==m-1?0:arr[j+1].F!=arr[j].F));
    }
    for(int j=0;j<m;j++){
	for(int i=0;i<n;i++)
	    arr[i]={a[i][j],i};
	sort(arr,arr+n);
	int CNT=0;
	for(int i=0;i<n;i++)
	    ls[1][arr[i].S][j]=(CNT=CNT+(i==0?0:arr[i-1].F!=arr[i].F));
	CNT=0;
	for(int i=n-1;i>=0;i--)
	    gr[1][arr[i].S][j]=(CNT=CNT+(i==n-1?0:arr[i+1].F!=arr[i].F));
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    cout<<max(ls[0][i][j],ls[1][i][j])+1+max(gr[0][i][j],gr[1][i][j])<<" ";
	}
	cout<<"\n";
    }
    return 0;
}