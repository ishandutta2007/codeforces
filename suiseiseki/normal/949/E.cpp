#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int n;
vector<int> a;
vector<int> solve(vector<int> a,int dep=0){
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	if(dep>19){
		return vector<int>();
	}
	bool flag=1;
	for(int i=0;i<(int)a.size();i++){
		if(a[i]&1){
			flag=0;
			break;
		}
	}
	if(flag){
		for(int i=0;i<(int)a.size();i++){
			a[i]>>=1;
		}
		return solve(a,dep+1);
	}
	vector<int> b;
	vector<int> ans_1,ans_2;
	for(int i=0;i<(int)a.size();i++){
		if(a[i]&1){
			b.push_back((a[i]+1)>>1);
		}
		else{
			b.push_back(a[i]>>1);
		}
	}
	ans_1=solve(b,dep+1);
	b.clear();
	for(int i=0;i<(int)a.size();i++){
		if(a[i]&1){
			b.push_back((a[i]-1)>>1);
		}
		else{
			b.push_back(a[i]>>1);
		}
	}
	ans_2=solve(b,dep+1);
	b.clear();
	ans_1.push_back(-(1<<dep));
	ans_2.push_back(1<<dep);
	if(ans_1.size()<ans_2.size()){
		return ans_1;
	}
	else{
		return ans_2;
	}
}
vector<int> ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	ans=solve(a);
	printf("%u\n",ans.size());
	for(int i=0;i<(int)ans.size();i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}