#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e6+5;

int n;
int a[N];
int fi[N];
bool ans;
int w[N];
int lst[N],nxt[N];
int pre[N],suf[N];
int pos[N],k;
bool used[N];
int sta[N],top;
int Nxt[N],hd[N];

void getans(int l,int r){
	if (l==r)return;
	if (a[pos[l]]){
		int v=pre[l];
		int lst=l;
		for(;hd[v]&&hd[v]<=r;hd[v]=Nxt[hd[v]]){
			if (hd[v]>l&&!a[pos[hd[v]]]){
				a[pos[hd[v]]]=a[pos[l]];
				getans(lst+1,hd[v]-1);
				lst=hd[v];
			}
		}
		return;
	}
	if (a[pos[r]]){
		int lst=0;
		int v=pre[l];
		for(;hd[v]&&hd[v]<=r;hd[v]=Nxt[hd[v]]){
			if (hd[v]>=l&&!a[pos[hd[v]]]){
				a[pos[hd[v]]]=a[pos[r]];
				if (lst)getans(lst+1,hd[v]-1);
				lst=hd[v];
			}
		}
		getans(lst+1,r-1);
		return;
	}
	int v=pre[r];
	for(;hd[v]&&hd[v]<l;hd[v]=Nxt[hd[v]]);
	getans(l,hd[v]);
	getans(hd[v],r);
}

bool solve(int l,int r,int tp){
	if (l==r){
		if (!a[l])a[l]=sta[top--];
		return 1;
	}
	for(int x=l;x<=r;){
		if (nxt[x]){
			if (!solve(x+1,nxt[x]-1,a[x]))return 0;
			x=nxt[x];
		}
		else x++;
	}
	k=0;
	for(int x=l;x<=r;){
		if (nxt[x])x=nxt[x];
		else pos[++k]=x++;
	}
	int known=0;
	fo(i,1,k)if (a[pos[i]])known++;
	if (k%2==0||known>k/2+1)return 0;
	known=k/2+1-known;
	if (!a[pos[1]]){
		fd(i,k,1)
		if (!a[pos[i]]&&known){
			known--;
			a[pos[i]]=sta[top--];
		}
	}
	else{
		fo(i,1,k)
		if (!a[pos[i]]&&known){
			known--;
			a[pos[i]]=sta[top--];
		}
	}
	pre[0]=n;
	fo(i,1,k)if (a[pos[i]])pre[i]=pre[i-1]+1;else pre[i]=pre[i-1]-1;
	int t=k/2+1;
	fo(i,n-t,n+t)hd[i]=0;
	fd(i,k,1){
		Nxt[i]=hd[pre[i]];
		hd[pre[i]]=i;
	}
	if (k==1)return 1;
	if (tp){
		int lst=0;
		fo(i,1,k)
		if (!a[pos[i]]&&pre[i]==pre[0]){
			a[pos[i]]=tp;
			getans(lst+1,i-1);
			lst=i;
		}
		getans(lst+1,k);
	}
	else{
		if (a[pos[1]]&&a[pos[k]])return 0;
		getans(1,k);
	}
	return 1;
}

int main(){
	n=get();
	fo(i,1,n*2-1)a[i]=get();
	ans=1;
	fo(i,1,n*2-1)
	if (a[i]){
		used[a[i]]=1;
		if (!fi[a[i]])fi[a[i]]=i;
		else{
			if (fi[a[i]]%2!=i%2)ans=0;
		}
	}
	fo(i,1,n)if (!used[i])sta[++top]=i;
	if (!ans)return printf("no\n"),0;
	fo(i,1,n*2-1)if (a[i]){lst[i]=w[a[i]];w[a[i]]=i;}
	fo(i,1,n)w[i]=0;
	fd(i,n*2-1,1)if (a[i]){nxt[i]=w[a[i]];w[a[i]]=i;}
	if (ans){
		fo(i,1,n)
		if (lst[i]){
			for(int x=i-1;x>lst[i];){
				if (nxt[x]>i){ans=0;break;}
				if (lst[x])x=lst[x];
				else x--;
			}
			if (!ans)break;
		}
	}
	if (!ans)return printf("no\n"),0;
	if (n>1&&a[1]&&a[n*2-1]&&a[1]!=a[n*2-1])return printf("no\n"),0;
	fo(i,1,n*2-1)pre[i]=suf[i]=0;
	ans=solve(1,n*2-1,0);
	if (!ans)printf("no\n");
	else{
		printf("yes\n");
		fo(i,1,n*2-1)printf("%d%c",a[i],i==n*2-1?'\n':' ');
	}
	return 0;
}