#include <cstdio>
#include <set>
using namespace std;
#define Maxn 200000
int d[305];
int f[Maxn+5];
int n,m;
bool del[Maxn+5];
void add(int x,int a){
	for(int i=x;i<=n;i+=(i&(-i))){
		f[i]+=a;
	}
}
int sum(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
char s[Maxn+5];
set<int> st[65];
int get(int x){
	int left=1,right=n,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(sum(mid)>=x){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	return left;
}
int main(){
	for(int i=0;i<10;i++){
		d[i+'0']=i;
	}
	for(int i=0;i<26;i++){
		d[i+'A']=10+i;
	}
	for(int i=0;i<26;i++){
		d[i+'a']=36+i;
	}
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		add(i,1);
		st[d[s[i]]].insert(i);
	}
	int x,y;
	char qu[3];
	set<int>::iterator it_1,it_2;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		scanf("%s",qu);
		x=get(x);
		y=get(y);
		it_1=st[d[*qu]].lower_bound(x);
		it_2=it_1;
		while(it_2!=st[d[*qu]].end()&&(*it_2)<=y){
			add((*it_2),-1);
			del[*it_2]=1;
			it_2++;
		}
		st[d[*qu]].erase(it_1,it_2);
	}
	for(int i=1;i<=n;i++){
		if(del[i]){
			continue;
		}
		putchar(s[i]);
	}
	puts("");
	return 0;
}
///////////