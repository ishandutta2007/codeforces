#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,s;
const int inf=((int)1e14)+1;
int L,R;
int M,TOT=0;;
bool flag=0;
int qry(int x){
	if(!flag){
		cout<<"? "<<x<<endl;
		string st;cin>>st;
		if(st[0]=='L') {s+=x;L=max(L,x);return 1;}
		else {s-=x;return 0;}
	}
	else{
		TOT++;
		if(x<=M){s+=x;L=max(L,x);return 1;}
		else {s-=x;return 0;}
	}
}
signed main(){
	//	cerr<<"? "<<((1ll<<46)+1ll)<<endl;
	srand(time(0));
	T=read();
	int mx=0;
	while(T--){
		if(flag){
			//cin>>M;
			M=((int)rand()<<32|(rand()))%inf;
		}
		TOT=0;
		s=1;
		L=R=0;
		while(qry(min(s,inf-1)))if(L==inf-1)break;
		R=min(inf,L*2);
		int ti=0;
		while(L+1<R){
			int mid=(L+R)>>1;
			ti++;
			if(s<(sqrt(5)+1)*mid){
				mid=L+ceil(1.0*(R-L+1)/(sqrt(5)+1));	
			}
			while(s<mid)qry(L);
			if(qry(mid));
			else R=mid;
		}
		mx=max(mx,TOT);
		if(flag&&TOT>105)break;
		cout<<"! "<<L<<endl;
	}
	if(flag)	cerr<<"mx: "<<mx<<endl;
	return 0;
}