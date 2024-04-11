#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vb vector< bool >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define sort(a) sort(a.begin(),a.end())
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define moddd (1000*1000*1000+9)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define endl "\n"
#define flush fflush(stdout) 
#define pi 3.14159265358979323846264338327950
#define primeDEN 727999983
//cout<<fixed<<setprecision(15)<<ans;
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

vector<vi> arr(1001);
vi vec;
ll ans=0;
ll comb[1005][1005];

ll mypower(ll a,ll b){
	if(b==0) return 1;
	ll temp=mypower(a,b/2);
	temp=(temp*temp)%mod;
	if(b%2==0) return temp;
	else return (temp*a)%mod;
}

int setbits(int a){
	int ans=0;
	while(a!=0){
		if(a%2==1) ans++;
		a/=2;
	}
	return ans;
}

void func(int a){
	if(a==0){
		vec.pb(1);
		return;
	}
	func(a-1);
	vi vec2;
	int i;
	for(i=0;i<vec.size();i++){
		//cout<<vec[i]<<endl;
		vec2.insert(vec2.end(),arr[vec[i]].begin(),arr[vec[i]].end());
	}
	vec=vec2;
}

void findans(string str,vi vecc){
	if(str.length()==0){
		for(int i=0;i<vecc.size();i++){
			if(vecc[i]==0) ans=(ans+1)%mod;
		}
		return;
	}
	int i,j;
	int len=str.length();
	//for(i=1;i<len;i++){
	for(j=0;j<vecc.size();j++){
		ans=(ans+comb[len-1][vecc[j]])%mod;
	}
	//}
	string temp;
	reverse(str.begin(),str.end());
	int lenn=str.length()-1;
	str.resize(lenn);
	len=str.length();
	for(i=len-1;i>=0;i--){
		int lenn=str.length();
		if(str[lenn-1]=='1') break;
		else str.resize(lenn-1);
	}
	reverse(str.begin(),str.end());
	vi temp2;
	for(i=0;i<vecc.size();i++){
		if(vecc[i]>=1) temp2.pb(vecc[i]-1);
	}
	//cout<<ans<<endl;
	//cout<<temp<<endl;
	//printvec(temp2);

	findans(str,temp2);
}

int main(){
	std::ios::sync_with_stdio(false); 
	int ttt=1;
	//cin>>ttt;
	while(ttt--){
		string str;
		int n,i,k,j;
		cin>>str>>k;
		if(k==0){
			cout<<"1";
			return 0;
		}
		if(k==1){
			cout<<str.length()-1;
			return 0;
		}
		if(str.length()==1){
			if(k==0) cout<<"1";
			else cout<<"0";
			return 0;
		}
		for(i=2;i<1001;i++){
			arr[setbits(i)].pb(i);
		}
		//func(1);
		//printvec(vec);
		func(k-1);
		ll fact[1005],ifact[1005];
		fact[0]=1;
		for(ll i=1;i<1005;i++){
			fact[i]=(fact[i-1]*i)%mod;
		}
		for(i=0;i<1005;i++){
			ifact[i]=mypower(fact[i],mod-2);
		}
		for(i=0;i<1005;i++){
			for(j=0;j<1005;j++){
				comb[i][j]=0;
			}
		}
		for(i=0;i<1005;i++){
			for(j=0;j<1005;j++){
				if(i<j) continue;
				comb[i][j]=(fact[i]*ifact[j])%mod;
				comb[i][j]=(comb[i][j]*ifact[i-j])%mod;
			}
		}
		//printvec(vec);
		findans(str,vec);
		cout<<ans;
	}
	return 0;
}