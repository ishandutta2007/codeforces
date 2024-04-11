#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<string>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100+19;
const ll top=1e12;

int A[N];
int n;
ll k,res;

int main(){
	cin>>n>>k;
	For(i,1,n+1){
		A[i]=IN();
		k+=A[i];
	}
	for (ll l=1,r;l<=top;l=r+1){
		r=top;
		For(i,1,n+1){
			if (A[i]-1>=l){
				r=min(r,(A[i]-1)/((A[i]-1)/l));
			}
		}
		ll sum=0,sumk=0;
		For(i,1,n+1){
			sum+=1ll*((A[i]-1)/l+1)*l;
			sumk+=(A[i]-1)/l+1;
		}
		if (sum<=k){
			ll tmp=min((k-sum)/sumk,r-l);
			assert(sum+tmp*sumk<=k);
			res=max(res,l+tmp);
		}
	}
	cout<<res<<endl;
}