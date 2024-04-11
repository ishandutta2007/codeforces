#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string str;
string ask[4], ans[4];

const int MAX_N = 10000;

string query(string x){
	cout<<"? "<<x<<endl;
	fflush(stdout);
	string y;
	cin>>y;
	return y;
}

int idx[30][30][30];
int label[MAX_N+1][4];
int N;
string answer;

int main(){
	cin>>str;
	N = str.size();
	for(int i=0; i<N; i++){
		answer.push_back('a');
		label[i][1] = i%26;
		label[i][2] = (i/26)%26;
		label[i][3] = (i/26)/26;
		for(int j=1; j<=3; j++)	ask[j].push_back('a'+label[i][j]);
		idx[label[i][1]][label[i][2]][label[i][3]] = i;
	}
	for(int i=1; i<=3; i++)	ans[i] = query(ask[i]);
	for(int i=0; i<N; i++){
		int k = idx[ans[1][i]-'a'][ans[2][i]-'a'][ans[3][i]-'a'];
		answer[k] = str[i];
	}
	cout<<"! "<<answer;
	return 0;
}