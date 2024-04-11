#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int ans=1e9,n,r,a,b,o,d,k,sa;
char q[1111111],bb[1000111];

void ff(){
		int p=-1;
		o=d=0;
		k=1;
		for(;;){
			if (b==0){
				d=1e9;
				break;
			}
			if (a==0){
				if (b>1)d=1e9;
				break;
			}
			if (a<b){
				d+=(b-1)/a;
				o+=(b-1)/a-1;
				if (p==1)o++;
//				for (int i=0;i<(b-1)/a;i++)q[k++]='B';
				p=1;
				b-=a*((b-1)/a);
			}else if (a>b){
				d+=a/b;
				o+=a/b-1;
				if (p==0)o++;
//				for (int i=0;i<a/b;i++)q[k++]='T';
				p=0;
				a-=b*(a/b);
			}else{
				if (a!=1){
					d=1e9;
					break;
				}else{
					d++;
					q[k++]='T';
					if (p==0)o++;
					p=0;
					break;
				}
			}
		}
}

void gg(){
		o=d=0;
		k=1;
		for(;;){
			if (b==0){
				d=1e9;
				break;
			}
			if (a==0){
				if (b>1)d=1e9;
				break;
			}
			if (a<b){
				d+=(b-1)/a;
				for (int i=0;i<(b-1)/a;i++)q[k++]='B';
				b-=a*((b-1)/a);
			}else if (a>b){
				d+=a/b;
				for (int i=0;i<a/b;i++)q[k++]='T';
				a-=b*(a/b);
			}else{
				if (a!=1){
					d=1e9;
					break;
				}else{
					d++;
					q[k++]='T';
					break;
				}
			}
		}
		if (q[1]=='T')q[0]='B';else q[0]='T';
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> r;
	for (int i=0;i<r;i++){
		a=i;
		b=r-i;
		ff();
		if (d==n-1&&o<ans){
			ans=o;
			sa=i;
		}
	}
	if (ans>1e7){
		puts("IMPOSSIBLE");
		return 0;
	}
	CC(ans);
	a=sa;
	b=r-a;
	gg();
	for (int i=0;i<n;i++)bb[i]=q[i];
	reverse(bb,bb+n);
	puts(bb);
	return 0;
}