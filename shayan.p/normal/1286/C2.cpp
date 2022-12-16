// They can't break me, as long as I know who I am...

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

const int maxn = 110, mod = 1e9 + 7;
const ll inf = 1e18;

istream& operator >> (istream& in, vector<int> &v){
    string s; cin>>s;
    v.resize(26);
    for(int &x:v)
	x = 0;
    for(char ch : s)
	v[ ch - 'a' ] ++;
    return in;
}
map< vector<int>, int > ask(int l, int r){
    map< vector<int>, int > ans;
    if(l>r)
	return ans;
    cout<<"? "<<l<<" "<<r<<endl;
    for(int L = l; L<=r; L++){
	for(int R = L; R<=r; R++){
	    vector<int> v;
	    cin>>v;	    
	    ans[v]++;
	}
    }
    return ans;
}
int operator ! (vector<int> v){
    int sm = 0;
    for(int x : v)
	sm+= x;
    return sm;
}
vector<int> operator - (vector<int> a, vector<int> b){
    for(int i = 0; i < 26; i++)
	a[i]-=b[i];
    return a;
}
vector<int> operator + (vector<int> a, vector<int> b){
    for(int i = 0; i < 26; i++)
	a[i]+=b[i];
    return a;
}
vector<int> operator * (int k, vector<int> v){
    for(int &x : v)
	x*=k;
    return v;
}
int only(vector<int> v){
    for(int i = 0; i < 26; i++)
	if(v[i] != 0)
	    return i;
    assert(0);
}

int ans[maxn];
vector<int> vec[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin>>n;
    int N = (n+1)/2;
    int M = n - N;
    
    auto mp1 = ask(1, N);
    auto mp2 = ask(2, N);
    auto mp3 = ask(1, n);

    vec[0].resize(26);
    for(auto it:mp1){
	if(mp2[it.F] == it.S)
	    continue;
	vec[ !it.F ] = it.F;
    }
    for(int i = 1; i <= N; i++){
	ans[i] = only( vec[i] - vec[i-1] );
    }
    for(int i = 0; i < maxn; i++){
	vec[i].resize(26);
	for(int &x : vec[i])
	    x = 0;
    }
    for(auto it : mp3){
	int cnt = it.S - mp1[it.F];
	vec[ !it.F ]= vec[ !it.F ] + ( cnt * it.F );
    }
    if(M > 1){
	for(int i = 1; i<=N; i++){
	    vector<int> vv =  ( vec[N + 1 - i] - vec[N + 0 - i] ) - ( vec[N + 2 - i] - vec[N + 1 - i] );
	    vv[ ans[i] ] ++;
	    ans[i + M] = only(vv);
	}
    }
    else if(M == 1){
	ans[n] = only(vec[1]);
    }
    cout<<"! ";
    for(int i = 1; i<=n; i++)
	cout << char('a' + ans[i]);
    return cout << endl ,0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")