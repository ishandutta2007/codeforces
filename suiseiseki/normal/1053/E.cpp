#include <bits/stdc++.h>
const int Maxn=1000000;
int a[Maxn+5],vis[Maxn+5],nxt[Maxn+5],pre[Maxn+5],suf[Maxn+5];
int n,m,now=1;
void Fail(){
	puts("no");	
	exit(0);
}
int Get(){
	while(vis[now]){
		now++;
	}
	if(now>n){
		Fail();
	}
	vis[now]=1;
	return now;
}
void Delete(int l,int r){
	int tl=pre[l],tr=suf[r];
	suf[tl]=tr;
	pre[tr]=tl;
}
void Merge(int l,int r,int &x){
	while(x>l&&suf[suf[x]]&&suf[suf[x]]<=r&&!a[x]&&a[suf[x]]&&a[suf[suf[x]]]){
		a[x]=a[suf[suf[x]]];
		Delete(suf[x],suf[suf[x]]);
		x=pre[pre[x]];
	}
	while(x>l&&suf[suf[x]]&&suf[suf[x]]<=r&&a[x]&&a[suf[x]]&&!a[suf[suf[x]]]){
		a[suf[suf[x]]]=a[x];
		Delete(suf[x],suf[suf[x]]);
		x=pre[pre[x]];
	}
}
void solve(int l,int r){
	if ((r-l)&1){
		Fail();
	}
	for(int i=l;i<=r;i=suf[i]){
		while(nxt[i]){
			if(nxt[i]>r){
				Fail();
			}
			solve(suf[i],pre[nxt[i]]);
			Delete(suf[i],nxt[i]);
			nxt[i]=nxt[nxt[i]];
		}
	}
	int num1=0,num2=0,rt=a[pre[l]];
	for(int i=l;i<=r;i=suf[i]){
		num1+=(a[i]>0);
		num2++;
	}
	num2=(num2>>1)+1;
	if(num1>num2){
		Fail();
	}
	num2-=num1;
	for(int i=l;num2&&i<=r;i=suf[i]){
		if(!a[i]){
			a[i]=Get();
			num2--;
		}
	}
	for(int i=l;i<=r;i=suf[i]){
		Merge(l-1,r,i);
	}
	for(int i=l;i<=r;i=suf[i]){
		if(!a[i]){
			a[i]=rt;
		}
	}
}
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("yes");
		puts("1");
		return 0;
	}
	m=(n<<1)-1;
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=m;i++){
		if(a[i]&&a[i-1]&&a[i]==a[i-1]){
			Fail();
		}
	}
	if(a[1]&&a[m]&&a[1]!=a[m]){
		Fail();
	}
	a[1]=a[m]=a[1]|a[m];
	for(int i=0;i<=m+1;i++){
		pre[i]=i-1;
		suf[i]=i+1;
	}
	pre[0]=0;
	for(int i=m;i>0;i--){
		if(a[i]){
			nxt[i]=vis[a[i]];
			vis[a[i]]=i;
		}
	}
	solve(1,m);
	puts("yes");
	for(int i=1;i<=m;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}