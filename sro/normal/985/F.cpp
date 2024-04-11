#include <bits/stdc++.h>
using namespace std;
//Kodid in Dongo ifun 4
//IP ares: 192.168.12.233

long long Ha[27][200005];
long long mii[200005];
long long Mod=1887415157;
char s[200005];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	n=strlen(s+1);
	mii[0]=1;
	for(int i=1;i<=n;i++){
		mii[i]=mii[i-1]*7%Mod;
	}
	for(int i=0;i<26;i++){
		for(int j=1;j<=n;j++){
			Ha[i][j]=(Ha[i][j-1]*7+(s[j]=='a'+i)+1)%Mod;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,len;
		scanf("%d%d%d",&a,&b,&len);
		a--;b--;
		vector<long long> numsa,numsb;
		for(int j=0;j<26;j++){
			numsa.push_back((Ha[j][a+len]-mii[len]*Ha[j][a]%Mod+Mod)%Mod);
		}
		for(int j=0;j<26;j++){
			numsb.push_back((Ha[j][b+len]-mii[len]*Ha[j][b]%Mod+Mod)%Mod);
		}
		sort(numsa.begin(),numsa.end());
		sort(numsb.begin(),numsb.end());
		bool can=1;
		for(int j=0;j<26;j++){
			if(numsa[j]!=numsb[j]){
				//cerr<<numsa[j]<<' '<<numsb[j]<<' '<<j<<endl;
				can=0;
				break;
			}
		}
		puts(can?"YES":"NO");
	}
	return 0;
}