// Phoenix

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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int cnt[10];
bool pr[10];
int fac[10];

int main(){
    pr[2]=1;pr[3]=1;pr[5]=1;pr[7]=1;
    fac[1]=1;
    for(int i=2;i<10;i++)
	fac[i]=i*fac[i-1];
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++){
	int num=fac[s[i]-'0'];
	if(num>1){
	    for(int j=7;j>1;j--){
		while(pr[j]==1 && num%fac[j]==0){
		    cnt[j]++;
		    num/=fac[j];
		}
	    }
	}
    }
    for(int i=9;i>0;i--){
	for(int j=0;j<cnt[i];j++)
	    cout<<i;
    }
    cout<<endl;
    return 0;
}