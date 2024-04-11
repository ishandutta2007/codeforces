#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 12020
int n,m,pr[M],ans,gg;
string w;
inline void clr(){cout<<"R"<<endl;fflush(stdout);}
inline bool ins(int x){
	gg++;
	cout<<"? "<<x<<endl;fflush(stdout);
	cin>>w;
	
	return w[0]=='Y';
}
inline void solve(){
	cin>>n,cin>>m;
	ans=n;
	int lim=n*n*3/(m*2);
	if(m==1){
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if((!pr[i])&&(!pr[j])){
			clr(); ins(i);
			if(ins(j)) pr[j]=1;
		}
	}
	else{
		for(int i=1;i<=n;i++) if(ins(i)) pr[i]=1;clr();
		m>>=1; int tot=n/m;
		for(int d=2;d<=tot-1;d++)
			for(int fs=1;fs<=d&&fs+d<=tot;fs++){
				clr();
				for(int bk=fs;bk<=tot;bk+=d)
					for(int x=(bk-1)*m+1;x<=bk*m;x++)
						if(!pr[x]) pr[x]=ins(x);
			}
	}
	ans=n;
	for(int i=1;i<=n;i++) if(pr[i]) ans--;
	// debug(n)sp,debug(gg)sp,debug(lim)el;
	cout<<"! "<<ans<<endl;

}
int main(){
	for(int Cas=1;Cas;--Cas) solve();
	return 0;
}