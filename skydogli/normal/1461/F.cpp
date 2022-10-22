#include<bits/stdc++.h>
using namespace std;
#define MN 100005
int n,a[MN];
int v[MN],tot,pre[MN];
int f[MN],lst[MN];
char ans[MN];
string s;
bool chk(int l,int r){
	int res=1;
	for(int i=l;i<=r;++i){
		res*=a[i];
		if(res>1e8)return 1;
	}
	return 0;
}
void solve(int l,int r){
	if(l>=r)return;
	while(a[l]==1){ans[l]='+';l++;}
	while(a[r]==1){ans[r-1]='+';r--;}
	if(l>=r)return;
	if(chk(l,r)){
		for(int i=l;i<r;++i)ans[i]='*';
		return;
	}
	int tot=0;
	for(int i=l;i<=r;++i){
		if(a[i]!=1){
			v[++tot]=i;
		}
	}
	v[0]=l-1;
	pre[0]=1;
	for(int i=1;i<=tot;++i){
		f[i]=0;
		pre[i]=pre[i-1]*a[v[i]];
		for(int j=0;j<i;++j){
			if(f[i]<f[j]+pre[i]/pre[j]+(v[j+1]-v[j]-1)){
				f[i]=f[j]+pre[i]/pre[j]+(v[j+1]-v[j]-1);
				lst[i]=j;
			}
		}
	}
	int p=tot;
	while(p){
		int to=lst[p];
		for(int j=v[to+1];j<v[p];++j)ans[j]='*';
		for(int j=v[to];j<v[to+1];++j)ans[j]='+';
		p=to;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>s;
	sort(s.begin(),s.end());//*+-
	if(s.size()==1||(s.size()==2&&s[0]=='+'&&s[1]=='-')){
		for(int i=1;i<=n;++i){
			printf("%d%c",a[i],i==n?'\n':s[0]);
		}
	}
	else if(s=="*-"){
		for(int i=1;i<=n;++i){
			if(!a[i]){
				for(int j=1;j<i;++j)
					printf("%d%c",a[j],j==i-1?'-':'*');
				printf("0");
				if(i!=n)printf("*");
				for(int j=i+1;j<=n;++j)
					printf("%d%c",a[j],j==n?'\n':'*');
				return 0;;
			}
		}
		for(int i=1;i<=n;++i){
			printf("%d%c",a[i],i==n?'\n':'*');
		}
	}
	else{
		int lst=1;
		for(int i=1;i<=n;++i){
			if(!a[i]){
				solve(lst,i-1);
				ans[i-1]='+';ans[i]='+';
				lst=i+1;
			}
		}
		solve(lst,n);
		for(int i=1;i<=n;++i){
			if(i!=n)assert(ans[i]);
			printf("%d%c",a[i],i==n?'\n':ans[i]);
		}
	}
	return 0;
}
///kel