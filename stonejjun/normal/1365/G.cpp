#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back


ll arr[1010101];
ll go[101010][15];

void dod(){
	vector<int> n;

    // 1 6 
    for(int i=0; i<13; i++){
        n.push_back(i+1);
    }

    // 01    
    vector<int> ind;

    // k=4, 4 
    int k = 6;

    // k 1 
    for(int i=0; i<k; i++){
        ind.push_back(1);
    }

    // 2(6-2) 0 
    for(int i=0; i<n.size()-k; i++){
        ind.push_back(0);
    }

    // 
    sort(ind.begin(), ind.end());
    ll x=0;
    //
    do{
        // 
        x++;
        for(int i=0; i<ind.size(); i++){
            if(ind[i] == 1){
                go[x][i]=1;
            }
        }

    }while(next_permutation(ind.begin(), ind.end()));
}


int main(){
    ll i,j,k,l,m,n;
    cin>>n;
    dod();
    for(i=0;i<13;i++){
    	ll cnt=0;
    	for(j=1;j<=n;j++){
    		if(go[j][i]) cnt++;
    	}
    	if(cnt==0) continue;
    	cout<<'?'<<' '<<cnt;
    	for(j=1;j<=n;j++){
    		if(go[j][i]) cout<<' '<<j;
    	}
    	cout<<'\n';
    	ll ans;
    	cin>>ans;
    	for(j=1;j<=n;j++){
    		if(!(go[j][i])) arr[j]=arr[j]|ans;
    	}
    }

    cout<<'!';
    for(i=1;i<=n;i++)
    	cout<<' '<<arr[i];
    cout<<'\n';
}