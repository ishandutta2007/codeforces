#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int R[1<<16],B[1<<16];
string c[16];
int r[16],b[16],f[1<<16][200];
int n,le,ri,res,sr,sb;

void Upd(int &x,int y){
	x=max(x,y);
}
bool check(int T){
	for (int i=max(sr-T,0);i<200;i++){
		if (f[(1<<n)-1][i]>=sb-T) return 1;
	}
	return 0;
}

int main(){
	n=IN();
	For(i,0,n){
		cin>>c[i]>>r[i]>>b[i];
		sr+=r[i],sb+=b[i];
	}
	For(t,0,1<<n){
		For(i,0,n)
			if (t>>i&1){
				R[t]+=(c[i]=="R");
				B[t]+=(c[i]=="B");
			}
	}
	memset(f,200,sizeof(f));
	f[0][0]=0;
	For(t,0,1<<n)
		For(s,0,200)
			if (f[t][s]>=0){
				For(i,0,n)
					if (!(t>>i&1)){
						Upd(f[t|1<<i][s+min(R[t],r[i])],f[t][s]+min(B[t],b[i]));
					}
			}
	le=0,ri=int(1e9);
	while (le<=ri){
		int mid=(le+ri>>1);
		if (check(mid)) res=mid,ri=mid-1;else le=mid+1;
	}
	printf("%d\n",res+n);
}