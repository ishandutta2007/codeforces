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

const int mo = 1e9+7;
const int N = 2e6+5;

int cnt[N];
int val[N];
int lst[N];
int pri[N],k;
int n;
int tim[N];
bool bz[N];

int main(){
	n=get();
	fo(i,1,n){
		int x=get();
		cnt[x]++;
	}
	lst[1]=1;
	fo(i,2,2e6){
		if (!lst[i])pri[++k]=lst[i]=i;
		fo(j,1,k){
			if (1ll*pri[j]*i>2e6)break;
			lst[i*pri[j]]=pri[j];
			if (i%pri[j]==0)break;
		}
	}
	fo(i,1,2e6)val[i]=1;
	int C=0;
	fd(i,2e6,2){
		fo(T,1,cnt[i]){
			if (val[i]<i)bz[i]=1,tim[i]=1,val[i]=i;
			else{
				bz[i-1]=1;
				int x=i-1;
				while(x>1){
					int v=lst[x];
					int t=1;
					while(x%v==0){
						x/=v;
						t=t*v;
					}
					if (t>val[v]){
						val[v]=t;
						tim[v]=1;
					}
					else if(val[v]==t)tim[v]++;
				}
			}
		}
	}
	fo(i,1,2e6)
	if (bz[i]){
		bool can=1;
		for(int x=i;x>1;){
			int v=lst[x],t=1;
			for(;x%v==0;)x/=v,t*=v;
			if (val[v]==t&&tim[v]==1)can=0;
		}
		if (can){C=1;break;}
	}
	int ans=1;
	fo(i,1,2e6)ans=1ll*ans*val[i]%mo;
	ans=(ans+C)%mo;
	cout<<ans<<endl;
	return 0;
}