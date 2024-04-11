#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define Maxn 200000
#define Mod 998244353
int a[Maxn+5];
int b[Maxn+5];
int n;
int f[Maxn+5];
map<int,int> mp;
int id;
struct Seg{
	int left,right;
	friend bool operator <(Seg p,Seg q){
		return p.left<q.left;
	}
}seg[Maxn+5];
int get_Id(int x,int num){
	if(mp.count(x)>0){
		seg[mp[x]].right=num;
		return mp[x];
	}
	id++;
	mp[x]=id;
	seg[id].left=num;
	return id;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=get_Id(a[i],i);
	}
	sort(seg+1,seg+1+id);
	int len=0;
	seg[0].right=(-1<<30);
	for(int i=1;i<=n;i++){
		if(seg[i].left>seg[len].right){
			len++;
			seg[len]=seg[i];
		}
		else{
			seg[len].right=mx(seg[len].right,seg[i].right);
		}
	}
	f[1]=1;
	for(int i=2;i<=len;i++){
		f[i]=(f[i-1]<<1);
		f[i]%=Mod;
	}
	printf("%d\n",f[len]);
	return 0;
}