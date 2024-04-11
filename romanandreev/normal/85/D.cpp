#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
const int sh=1<<18;
int kl[2*sh+5];
int tp[1000000];
int x[1000000];
ll sm[2*sh+5][5];
int n;
char s[100];
vector<int> V;
void add(int v,int l,int r,int x,int p){
	if (l==r){
		kl[v]=p;
		sm[v][0]=V[x-1]*p;
		sm[v][1]=0;
		sm[v][2]=0;
		sm[v][3]=0;
		sm[v][4]=0;
		return;
	}
	if (x<=(l+r)/2) add(v*2,l,(l+r)/2,x,p);
	           else add(v*2+1,(l+r)/2+1,r,x,p);
	kl[v]=(kl[v*2]+kl[v*2+1])%5;
	for (int i=0;i<5;i++){
		sm[v][i]=sm[v*2][i]+sm[v*2+1][(i-kl[v*2]+5)%5];
	}
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",s);
		if (s[0]=='a'){
			tp[i]=0;
			scanf("%d",&x[i]);
			V.pb(x[i]);
		}
		if (s[0]=='d'){
			tp[i]=1;
			scanf("%d",&x[i]);
			V.pb(x[i]);
		}
		if (s[0]=='s'){
			tp[i]=2;
		}
	}
	sort(V.begin(),V.end());
	for (int i=0;i<n;i++){
		if (tp[i]==0){
			add(1,1,sh,lower_bound(V.begin(),V.end(),x[i])-V.begin()+1,1);
		}
		if (tp[i]==1){
			add(1,1,sh,lower_bound(V.begin(),V.end(),x[i])-V.begin()+1,0);
		}
		if (tp[i]==2){
			printf("%I64d\n",sm[1][2]);
		}
	}
    return 0;
}