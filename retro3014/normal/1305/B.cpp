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
#define test 1
#define TEST if(test)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000;
 
string str, str2;
int N;
vector<int> v[MAX_N+1];
 
int d1[MAX_N+1], d2[MAX_N+1];
 
int main(){
	cin>>str;
	int idx = 0;
	while(1){
		//cout<<str.size()<<endl;
		for(int i=0; i<str.size(); i++){
			//cout<<"*";
			if(i==0)	d1[i] = (str[i]=='(');
			else	d1[i] = d1[i-1] + (str[i]=='(');
		}
		for(int i=(int)str.size()-1; i>=0; i--){
			//cout<<"!";
			if(i==str.size()-1)	d2[i] = (str[i]==')');
			else d2[i] = d2[i+1] + (str[i]==')');
		}
		int n = 0, mx = 0;
		for(int i=0; i<(int)str.size()-1; i++){
			//cout<<"?";
			if(min(d1[i], d2[i+1])>mx){
				mx = min(d1[i], d2[i+1]);
				n = i;
			}
		}
		//cout<<mx<<endl;
		if(mx==0)	break;
		int cnt = mx;
		for(int i=0; i<str.size(); i++){
			if(str[i]=='('){
				v[idx].pb(i+1);
				str[i] = '.';
				cnt--;
				if(cnt==0)	break;
			}
		}
		cnt = mx;
		for(int i=str.size()-1; i>=0; i--){
			if(str[i]==')'){
				str[i] = '.';
				v[idx].pb(i+1);
				cnt--;
				if(cnt==0)	break;
			}
		}
		idx++;
		for(int i=0; i<str.size(); i++){
			if(str[i]=='(' || str[i]==')'){
				str2.pb(str[i]);
			}
		}
		while(!str.empty())	str.pop_back();
		for(int i=0; i<str2.size(); i++){
			str.pb(str2[i]);
		}
		while(!str2.empty())	str2.pop_back();
	}
	printf("%d\n", idx);
	for(int i=0; i<idx; i++){
		printf("%d\n", (int)v[i].size());
		sort(v[i].begin(), v[i].end());
		for(int j=0; j<v[i].size(); j++){
			printf("%d ", v[i][j]);
		}
	}
 
	return 0;
}