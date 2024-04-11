#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

const int N = 3e5+5;

int n;
struct element{
	int v;
	LL s;
}a[N];

int main(){
//	freopen("data.in","r",stdin);
	cin>>n;
	LL S=0;
	fo(i,1,n){
		scanf("%d%I64d",&a[i].v,&a[i].s);
		S+=a[i].v;
	}
	if (S<0){
		S=-S;
		fo(i,1,n)a[i].v*=-1;
	}
	LL ret=0;
	fo(w,0,61){
		LL t=0;
		fo(i,1,n)
		if ((a[i].s>>w)==1)t+=a[i].v;
		if (t>0){
			ret=ret|(1ll<<w);
			fo(i,1,n)
			if ((a[i].s&(1ll<<w))>0)a[i].v*=-1;
		}
	}
	cout<<ret<<endl;
	return 0;
}