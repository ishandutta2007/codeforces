//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 1e5 + 9;
const int Mod = 2e9 + 7;
int arr[Maxn];
int ans[Maxn];
int n,k;
vector<pair<int,int> > num[Maxn];
vector<int> next[Maxn];
vector<int> poshteham[Maxn];
void rec(int now,int l,int s){
	if(!(l + 1))
		return;
	if(num[now][l].first == Mod){
		s++;
	}else
		s = 0;
	rec(now,l-1,s);
	poshteham[now].push_back(s);
}
void build(int now){
	int cnt = 0;
	int last = -2e9 -1;
	int s = 0;
	bool f = 0;
	rec(now,num[now].size()-1,0);
	int done = -1;
	for(int i = 0; i < num[now].size();i++){
		if(num[now][i].first == Mod && i > done){
			if(last < 0 && next[now][cnt] > 0){
				int st = -(poshteham[now][i]/2);
				if(last >= st)
					st = last + 1;
				if(next[now][cnt] <= st + poshteham[now][i] - 1)
					st = next[now][cnt] - poshteham[now][i];
				for(int j = i; j < i + poshteham[now][i];j++){
					ans[num[now][j].second] = st++;
				}
				done = i + poshteham[now][i] - 1;
			}
			if(last < 0 && next[now][cnt] <= 0){
				int hi = next[now][cnt]-1;
				for(int j = i+poshteham[now][i]-1; j != i-1; --j)
					ans[num[now][j].second] = hi--;
				done = i + poshteham[now][i] - 1;
			}
			if(last >= 0 && next[now][cnt] > 0)
				ans[num[now][i].second] = last+1;
			
		}else if(num[now][i].first != Mod)
			cnt++,ans[num[now][i].second] = num[now][i].first;
		last = ans[num[now][i].second];
	}
}
int Int(string S){
	int cnt = 0;
	int st = 0;
	if(S[0] == '-')
		st++;
	for(int i = st; i < S.size();i++){
		cnt *= 10;
		cnt += S[i]-'0';
	}
	if(st == 1)
		return -cnt;
	return cnt;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n;i++){
		string no;
		int now = 0;
		cin >> no;
		if(no == "?"){
			now = Mod;
		}else{
			now = Int(no);
			next[i % k].push_back(now);
		}
		arr[i] = now;
		num[i % k].push_back(make_pair(arr[i],i));
	}
	for(int i = 0; i < k;i++)
		next[i].push_back(Mod-6);
	for(int i = 0; i < k;i++)
		build(i);
	for(int i = 0; i < n;i++){
		cerr << ans[i] << ' ';
	}
	for(int i = 0; i < n;i++){
		if(ans[i] == Mod){
			cout << "Incorrect sequence" << endl;
			return 0;
		}
	}
	for(int j = 0; j < k;j++)
		for(int i = j+k; i < n;i+=k){
			if(ans[i] <= ans[i-k]){
				cout << "Incorrect sequence" << endl;
				return 0;
			}
		}
	for(int i = 0; i < n;i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}