// Can U hack it?

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

const int maxn=1010;

int n,m;
bool is[maxn][maxn];
string s[maxn];

bool ok(int x,int y){
    if((x+2)>=n || (y+2)>=m)return 0;
    bool ans=1;
    for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	    if(j==1 && i==1)continue;
	    ans&=s[x+i][y+j]=='#';
	}
    }
    return ans;
}

void Do(int x,int y){
    for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	    if(i==1 && j==1)continue;
	    is[x+i][y+j]=1;
	}
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(ok(i,j))
		Do(i,j);
	}
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(s[i][j]=='#' xor is[i][j]){
		cout<<"NO\n";
		return 0;
	    }
	}
    }
    cout<<"YES\n";
    return 0;
}