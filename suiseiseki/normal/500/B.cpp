#include <bits/stdc++.h>
#define inf 1000000000
#define int long long
#define ll long long
using namespace std;
int n;
int a[305],fa[305];
char ch[305];
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=n;j++){
			if(ch[j]=='1'){
				int p=find(i),q=find(j);
				if(p!=q){
					fa[p]=q;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		int t=i;
		for(int j=i+1;j<=n;j++){
			if(find(j)==find(i)&&a[j]<a[t]){
				t=j;
			}
		}
		swap(a[i],a[t]);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}