#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define Mod 1000000007
#define Maxn 100000
int ad[15],mul[15];
int n;
string q[Maxn+5],s;
int main(){
	cin>>s>>n;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	for(int i=0;i<10;i++){
		mul[i]=10;
		ad[i]=i;
	}
	int c,tmp,na,nm;
	for(int i=n-1;i>=0;i--){
		tmp=q[i][0]-'0',na=0,nm=1;
		for(int j=3;j<(int)q[i].size();j++){
			c=q[i][j]-'0';
			nm=(int)(1ll*nm*mul[c]%Mod);
			na=(int)(1ll*na*mul[c]%Mod);
			na+=ad[c];
			na%=Mod;
		}
		ad[tmp]=na;
		mul[tmp]=nm;
	}
	int ans=0;
	for(int i=0;i<(int)s.size();i++){
		ans=(int)(1ll*ans*mul[s[i]-'0']%Mod);
		ans+=ad[s[i]-'0'];
		ans%=Mod;
	}
	printf("%d\n",ans);
	return 0;
}