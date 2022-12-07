#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

long long a,b,k,ans,n,x;
int kk=0,e[111111],f[111111];

void rec(long long x,int w,int p){
	if (x>n)return;
	ans+=n/x*w;
	for (int i=p;i>=0;i--)rec(x*e[i],-w,i-1);
}

int o(int x){
	n=x;
	if (k*k>n)return k<=n;
	int t;
	for (int i=0;i<kk;i++)if (e[i]==k)t=i;
	ans=0;
	rec(k,1,t-1);
	return ans;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	for (int i=2;i<80000;i++)if (!f[i]){
		e[kk++]=i;
		long long j=i*1ll*i;		
		while (j<80000){
			f[j]=1;
			j+=i;
		}
	}
	cin >> a >> b >> k;
	for (int i=0;i<kk;i++)if (e[i]!=k&&k%e[i]==0){
		puts("0");
		return 0;
	}
	cout << o(b)-o(a-1) << endl;
	return 0;
}