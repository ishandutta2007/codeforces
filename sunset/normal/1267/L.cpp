#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,l,k,cnt[30];
char s[1010000];
string f[1010];

int main() {
	scanf("%d%d%d",&n,&l,&k);
	scanf("%s",s);
	rep(i,0,n*l) cnt[s[i]-'a']++;
	int fl=0,fr=k-1;
	rep(i,0,l) {
		rep(j,fl,fr+1) {
			rep(k,0,26) if (cnt[k]>0) {
				f[j].pb(k+'a');
				cnt[k]--;
				break;
			}
		}
		rep(j,fl,fr+1) if (f[j][i]!=f[k-1][i]) {
			while (SZ(f[j])<l) {
				per(k,0,26) if (cnt[k]>0) {
					f[j].pb(k+'a');
					cnt[k]--;
					break;
				}
			}
			fl=j+1;
		}
	}
	rep(j,k,n) {
		while (SZ(f[j])<l) {
			per(k,0,26) if (cnt[k]>0) {
				f[j].pb(k+'a');
				cnt[k]--;
				break;
			}
		}
	}
	sort(f,f+n);
	rep(i,0,n) printf("%s\n",f[i].c_str());
}