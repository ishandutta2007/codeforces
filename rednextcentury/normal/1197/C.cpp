    //amitgomi
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define fi first
    #define se second
    #define pb push_back
    #define mp(x,y) make_pair(x,y)
    #define mod 998244353
    //double PI=3.1415926535897932384626;
    // ll bin_expo(ll a,ll b, ll m){ ll res =1; a %= m; while(b!=0){ if(b%2==1) res = (res*a)%mod; a = (a*a)%mod; b = b/2; } return res; }
    //ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); } 
     
     
    int main(){
    	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
     
    	int n,k;
    	cin>>n>>k;
    	int ar[n];
    	vector <int> v;
    	for(int i=0;i<n;i++){
    		cin>>ar[i];
    		if(i!=0)
    			v.push_back(ar[i]-ar[i-1]);
    	}
    	sort(v.begin(),v.end());
    	ll sum=0;
    	for(int i=0;i<n-k;i++){
    		sum = sum+v[i];
    	}
    	cout<<sum<<endl;
    	return 0;
    }