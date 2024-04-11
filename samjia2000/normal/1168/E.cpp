#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = (1<<12)+5;

int n;
int p[N],q[N];
int a[N],v[N];
int pos[N];

void solve(int i,int j){
	if (a[i]==(p[i]^q[i])&&a[j]==(p[j]^a[j]))return;
	int t=pos[a[i]^q[i]];
	swap(p[i],p[t]);
	//swap(p[t],p[j]);
	pos[p[i]]=i,pos[p[j]]=j,pos[p[t]]=t;
	swap(q[t],q[j]);
	solve(t,j);
}

int main(){
	int k=get();
	n=(1<<k);
	int sum=0;
	fo(i,0,n-1){
		v[i]=get();
		sum^=v[i];
	}
	if (sum!=0)return printf("Fou\n"),0;
	fo(i,0,n-1)p[i]=q[i]=pos[i]=i,a[i]=0;
	fo(i,0,n-2){
		int x=a[i]^v[i];
		a[i]^=x,a[i+1]^=x;
		solve(i,i+1);
	}
	printf("Shi\n");
	fo(i,0,n-1)printf("%d ",p[i]);putchar('\n');
	fo(i,0,n-1)printf("%d ",q[i]);putchar('\n');
	return 0;
}