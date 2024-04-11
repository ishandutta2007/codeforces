#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define pb push_back
#define f first
#define s second
#define mp make_pair

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int n, a, b;
int toind[26];
int tochar[20];
pi lr[20];
int num[20];
bool dp[1<<20];

int main(){
	cin >> n >> a >> b;
	string s;
	cin >> s;
	for(int i = 0; i < 26; i++){
		toind[i] = -1;
	}
	for(int i = 0; i < sz(s); i++){
		if(toind[s[i]-'a'] == -1){
			toind[s[i]-'a'] = 0;
		}
	}
	int curind = 0;
	for(int i = 0; i < 26; i++){
		if(toind[i] == -1) continue;
		tochar[curind] = i;
		toind[i] = curind++;
	}

	n = curind;

	for(int i = 0; i < n; i++){
		lr[i] = mp(-1, -1);
	}
	for(int i = 0; i < sz(s); i++){
		int ind = toind[s[i]-'a'];
		if(lr[ind].f == -1){
			lr[ind].f = i;
		}
		lr[ind].s = i;

		num[ind]++;
	}
	dp[0] = true;

	// for(int i = 0; i < n; i++){
	// 	cout << i << " " << char('a'+tochar[i]) << "\n";
	// }
	for(int i = 1; i < (1<<n); i++){
		//single
		pi rang = mp(sz(s)+1, -1);
		int sum = 0;
		for(int h = 0; h < n; h++){
			if((i>>h)&1){
				rang.f = min(rang.f, lr[h].f);
				rang.s = max(rang.s, lr[h].s);
				sum+=num[h];
			}
		}

		if((rang.s-rang.f+1)*a <= sum*b){
			for(int h = 0; h < n; h++){
				if((i>>h)&1){
					if(dp[i-(1<<h)]){
						dp[i] = true;
					}
				}
			}
		}
		
		//multiple
		vpi eles;
		for(int h = 0; h < n; h++){
			if((i>>h)&1){
				eles.pb(mp(lr[h].f, h));
			}
		}
		sort(all(eles));

		int sub1 = 0;
		int sub2 = i;
		for(int j = 0; j < sz(eles); j++){
			sub1+=(1<<eles[j].s);
			sub2-=(1<<eles[j].s);

			if(sub1 != 0 && sub2 != 0 && dp[sub1] && dp[sub2]){
				dp[i] = true;
			}
		}

	}

	vector<char> ans;

	for(int i = 0; i < n; i++){
		if(dp[(1<<n)-1-(1<<i)]){
			ans.pb(char('a'+tochar[i]));
		}
	}

	cout << sz(ans) << " ";
	for(auto u: ans){
		cout << u << " ";
	}
	cout << "\n";

}