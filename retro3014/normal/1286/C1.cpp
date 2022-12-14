#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 0
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 100;

int N;
string c1, s, ans;
vector<string> str1[MAX_N+1], str2[MAX_N+1];

vector<string> v;
int cnt1[30], cnt2[30], cnt[30];
string s1, s2;

void solve(){
	for(int i=0; i<str1[N][0].size(); i++){
		cnt1[str1[N][0][i]-'a']++;
	}
	for(int i=0; i<str2[N-1][0].size(); i++){
		cnt2[str2[N-1][0][i]-'a']++;
	}
	int idx = N-1, p, l;
	while(1){
		if(ans[idx]!='0')	break;
		p = N - 1 - idx;
		l = idx;
		while(!v.empty())	v.pop_back();
		for(int j=0; j<str1[l].size(); j++){
			TEST cout<<str1[l][j]<<" ";
			for(int k=0; k<30; k++)	cnt[k] = cnt1[k];
			while(!s.empty())	s.pop_back();
			c1 = str1[l][j];
			for(int k=0; k<c1.size(); k++){
				cnt[c1[k]-'a']--;
			}
			for(int k=0; k<30; k++){
				while(cnt[k]>0){
					s.pb('a'+k);
					cnt[k]--;
				}
			}
			v.pb(s);
			TEST cout<<s<<endl;
		}
		for(int j=0; j<p; j++){
			while(!s.empty())	s.pop_back();
			for(int i=0; i<=j; i++){
				s.pb(ans[i]);
			}
			for(int i=j+l+1; i<N; i++){
				s.pb(ans[i]);
			}
			sort(s.begin(), s.end());
			for(int j=0; j<v.size(); j++){
				if(v[j]==s){
					if(j!=v.size()-1){
						c1 = v[j];
						v[j] = v.back();
						v[v.size()-1] = c1;
					}
					v.pop_back();
					break;
				}
			}
		}
		s1 = v[0]; s2 = v[1];
		TEST cout<<s1<<" "<<s2<<endl;
		while(!s.empty())	s.pop_back();
		for(int i=0; i<=p; i++){
			s.pb(ans[i]);
		}
		sort(s.begin(), s.end());
		TEST  cout<<s<<endl;
		if(s1==s){
			s = s2;
		}else{
			s = s1;
		}
		for(int i=0; i<30; i++){
			cnt[i] = 0;
		}
		for(int i=0; i<s.size(); i++){
			cnt[s[i]-'a']++;
		}
		for(int i=idx+1; i<N; i++){
			cnt[ans[i]-'a']--;
		}
		for(int i=0; i<30; i++){
			if(cnt[i]!=0){
				ans[idx] = 'a'+i;
				TEST cout<<idx<<" "<<ans[idx]<<endl;
				break;
			}
		}
		idx = N - idx;
		p = N - idx;
		if(ans[idx]!='0')	return;
		l = p-1;
		while(!v.empty())	v.pop_back();
		for(int j=0; j<str2[l].size(); j++){
			for(int k=0; k<30; k++)	cnt[k] = cnt2[k];
			while(!s.empty())	s.pop_back();
			c1 = str2[l][j];
			for(int k=0; k<c1.size(); k++){
				cnt[c1[k]-'a']--;
			}
			for(int k=0; k<30; k++){
				while(cnt[k]>0){
					s.pb('a'+k);
					cnt[k]--;
				}
			}
			v.pb(s);
		}
		for(int j=1; j<idx; j++){
			while(!s.empty())	s.pop_back();
			for(int i=1; i<=j; i++){
				s.pb(ans[i]);
			}
			for(int i=j+l+1; i<N; i++){
				s.pb(ans[i]);
			}
			sort(s.begin(), s.end());
			for(int j=0; j<v.size(); j++){
				if(v[j]==s){
					if(j!=v.size()-1){
						c1 = v[j];
						v[j] = v.back();
						v[v.size()-1] = c1;
					}
					v.pop_back();
					break;
				}
			}
		}
		s1 = v[0]; s2 = v[1];
		while(!s.empty())	s.pop_back();
		for(int i=p; i<N; i++){
			s.pb(ans[i]);
		}
		sort(s.begin(), s.end());
		if(s1==s){
			s = s2;
		}else{
			s = s1;
		}
		for(int i=0; i<30; i++){
			cnt[i] = 0;
		}
		for(int i=0; i<s.size(); i++){
			cnt[s[i]-'a']++;
		}
		for(int i=1; i<idx; i++){
			cnt[ans[i]-'a']--;
		}
		for(int i=0; i<30; i++){
			if(cnt[i]!=0){
				ans[idx] = 'a'+i;
				TEST cout<<idx<<" "<<ans[idx]<<endl;
				break;
			}
		}
		idx = N-idx-1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0; i<N; i++){
		ans.pb('0');
	}
	cout<<"? 1 1"<<endl;
	cout.flush();
	cin>>c1;
	ans[0] = c1[0];
	if(N==1){
		cout<<"! "<<ans<<endl;
		cout.flush();
		return 0;
	}
	cout<<"? 1 "<<N<<endl;
	cout.flush();
	for(int i=1; i<=N; i++){
		for(int j=i; j<=N; j++){
			cin>>c1;
			sort(c1.begin(), c1.end());
			str1[c1.size()].pb(c1);
		}
	}
	if(N==2){
		c1 = str1[2][0];
		if(c1[0]==ans[0]){
			ans[1] = c1[1];
		}else{
			ans[1] = c1[0];
		}
		cout<<"! "<<ans<<endl;
		cout.flush();
		return 0;
	}
	cout<<"? 2 "<<N<<endl;
	cout.flush();
	for(int i=2; i<=N; i++){
		for(int j=i; j<=N; j++){
			cin>>c1;
			sort(c1.begin(), c1.end());
			str2[c1.size()].pb(c1);
		}
	}
	solve();
	cout<<"! "<<ans<<endl;
	cout.flush();
	return 0;
}