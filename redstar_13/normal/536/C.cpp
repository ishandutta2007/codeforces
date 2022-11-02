#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define MOD 1000000007
#define pb push_back
#define x first
#define y second
#define eps 1e-8

using namespace std;
typedef long long INT;

const int NN=200200;

int s[NN];
int r[NN];
int x[NN];
int mx[NN];
int arr[NN];
int flag[NN];

bool neednt(int a,int b,int d){
  return 1ll*mx[x[a]]*x[d]*(x[a]-x[b])*(mx[x[d]]-mx[x[b]])>1ll*x[a]*mx[x[d]]*(x[b]-x[d])*(mx[x[b]]-mx[x[a]]);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
#endif
	int n,i,j;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d%d",s+i,r+i);
    if(r[i]>mx[s[i]]) mx[s[i]]=r[i];
		x[i]=s[i];
	}
	sort(x,x+n);
	int nn=unique(x,x+n)-x,ed=0;
	for(i=nn; i--; ){
	  if(!ed || mx[x[arr[ed-1]]]<mx[x[i]]){
  		for(;ed>1 && neednt(arr[ed-2],arr[ed-1],i); ed--);
  		arr[ed++]=i;
  	}
	}
	for(i=0; i<ed; i++){
	  flag[arr[i]]=1;
	}
	for(i=0; i<n; i++){
	  j=lower_bound(x,x+nn,s[i])-x;
	  if(mx[s[i]]==r[i] && flag[j]){
	    printf("%d ",i+1);
	  }
	}
	puts("");
	return 0;
}