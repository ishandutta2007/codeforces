#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int char_to_id[150];
void init(){
	char_to_id['A']=1,char_to_id['N']=2,char_to_id['T']=3,char_to_id['O']=4;
}
int n;
char s[Maxn+5];
namespace BIT{
	int f[Maxn+5];
	void clear(){
		for(int i=1;i<=n;i++){
			f[i]=0;
		}
	}
	void add(int x,int a){
		for(int i=x;i>0;i-=(i&(-i))){
			f[i]+=a;
		}
	}
	int query(int x){
		int ans=0;
		for(int i=x;i<=n;i+=(i&(-i))){
			ans+=f[i];
		}
		return ans;
	}
}
std::vector<int> lis[5];
int ans_lis[Maxn+5];
ll answer;
void solve(){
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=4;i++){
		lis[i].clear();
	}
	for(int i=1;i<=n;i++){
		lis[char_to_id[s[i]]].push_back(i);
	}
	int p[5];
	for(int i=1;i<=4;i++){
		p[i]=i;
	}
	answer=-1;
	do{
		ll ans=0;
		BIT::clear();
		for(int i=1;i<=4;i++){
			for(int j=0;j<(int)lis[p[i]].size();j++){
				ans+=BIT::query(lis[p[i]][j]);
				BIT::add(lis[p[i]][j],1);
			}
		}
		if(ans>answer){
			answer=ans;
			int len=0;
			for(int i=1;i<=4;i++){
				for(int j=0;j<(int)lis[p[i]].size();j++){
					ans_lis[++len]=p[i];
				}
			}
		}
	}while(std::next_permutation(p+1,p+5));
	for(int i=1;i<=n;i++){
		if(ans_lis[i]==1){
			putchar('A');
		}
		else if(ans_lis[i]==2){
			putchar('N');
		}
		else if(ans_lis[i]==3){
			putchar('T');
		}
		else{
			putchar('O');
		}
	}
	putchar('\n');
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}