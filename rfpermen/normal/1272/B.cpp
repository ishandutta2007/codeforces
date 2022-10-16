#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
ll tc,n,x[3],y,z,a,b,c,d,id,res,tmp;
string s,t;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
        cin>>s;
        a = b = c = d = 0;
        for(auto i:s){
            if(i=='L')++a;
            else if(i=='R')++b;
            else if(i=='U')++c;
            else ++d;
        }
        if(a&&b&&c&&d){
            a = b = min(a,b);
            c = d = min(c,d);
            cout<<a+b+c+d<<endl;
            while(a--)cout<<'L';
            while(c--)cout<<'U';
            while(b--)cout<<'R';
            while(d--)cout<<'D';
            cout<<endl;
        }
        else if(a&&b)cout<<"2\nLR\n";
        else if(c&&d)cout<<"2\nUD\n";
        else cout<<"0\n\n";
    }
    return 0;
}