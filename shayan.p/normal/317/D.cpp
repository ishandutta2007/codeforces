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

const int MLG=31;

int f[MLG]={-1,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,12};
int cnt[MLG],n;
set<int>s;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    cin>>n;
    for(int i=2;1ll*i*i<=n;i++){
	if(s.count(i)) continue;
	int num=0;
	for(ll j=i;j<=n;j*=i){
	    num++;
	    s.insert(j);
	}
	cnt[num]++;
    }
    cnt[1]+=n-sz(s);
    int ans=0;
    for(int i=1;i<MLG;i++){
	if(cnt[i]&1)
	    ans^=f[i];
    }
    if(ans)
	cout<<"Vasya\n";
    else
	cout<<"Petya\n";
    return 0;
}