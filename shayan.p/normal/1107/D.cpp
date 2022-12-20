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

const int maxn=5300,mod=1e9+7;
const ll inf=1e18;

bitset<maxn> A[maxn];
bitset<maxn> B[maxn];
char s[maxn];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
	scanf("%s",s);
	for(int j=0;j<n/4;j++){
	    int num='0'<=s[j] && s[j]<='9' ? s[j]-'0' : s[j]-'A'+10 ;
	    for(int k=0;k<4;k++)
		A[i][4*j+k]=B[4*j+k][i]=bit(num,3-k);
	}
    }
    int prev=-1,ans=0;
    for(int i=0;i<n-1;i++){
	if(A[i]!=A[i+1])
	    ans=__gcd(ans,i-prev),prev=i;
    }
    ans=__gcd(ans,n-1-prev);

    prev=-1;
    for(int i=0;i<n-1;i++){
	if(B[i]!=B[i+1])
	    ans=__gcd(ans,i-prev),prev=i;
    }
    ans=__gcd(ans,n-1-prev);

    return cout<<ans<<endl,0;
}