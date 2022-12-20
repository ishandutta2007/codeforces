// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int dp[9][9][9][2];// what would the length be??
pair<pii,int> lst[9][9][9][2],tdl[2];// ragham haye akhar be soorat feshordeh // mask edtefade shode dar akhar
int tdo[2];

inline void UPD(int i,int j,int k,int rm,int msk,int MSK,int AA,int BB,int CC,int delta){
    if(msk==0 && MSK==0){
	if(delta!=rm && tdo[delta]>(3-(i==0)-(j==0)-(k==0)) ){
	    tdo[delta]=3-(i==0)-(j==0)-(k==0);
	    tdl[delta]={{100*AA+10*BB+CC,msk},MSK};
	}
	return;
    }
    int num=dp[i-bit(msk,0)-bit(MSK,0)][j-bit(msk,1)-bit(MSK,1)][k-bit(msk,2)-bit(MSK,2)][rm]+3-__builtin_popcount(msk)-(i==0)-(j==0)-(k==0);
    if(dp[i][j][k][delta]>num){
	dp[i][j][k][delta]=num;
	lst[i][j][k][delta]={{100*AA+10*BB+CC,msk},MSK};
    }
}

int main(){
    string s;cin>>s;
    string a,b,c;
    int num=0;
    for(int i=0;i<sz(s);i++){
	if(s[i]=='+' || s[i]=='='){
	    num++;
	    continue;
	}
	if(num==0)
	    a+=s[i];
	if(num==1)
	    b+=s[i];
	if(num==2)
	    c+=s[i];
    }
    
    int na=sz(a)+1,nb=sz(b)+1,nc=sz(c)+1;

    for(int i=0;i<=na;i++){
	for(int j=0;j<=nb;j++){
	    dp[i][j][0][0]=dp[i][j][0][1]=100;
	}
    }
    dp[0][0][0][0]=0;
    
    for(int i=0;i<=na;i++){
	for(int j=0;j<=nb;j++){
	    for(int k=1;k<=nc;k++){// 0 nadare
		
		for(int delta=0;delta<=1;delta++){
		    dp[i][j][k][delta]=100;// inf
		    
		    tdo[0]=tdo[1]=100;
		    
		    for(int msk=0;msk<8;msk++){
			if((i<2 && bit(msk,0)) || (j<2 && bit(msk,1)) || (k<2 && bit(msk,2)) )continue;
			for(int A=0;A<10;A++){
			    for(int B=0;B<10;B++){
				int AA=(bit(msk,0)?(a[i-2]-'0'):(A));
				int BB=(bit(msk,1)?(b[j-2]-'0'):(B));
				int CC=(bit(msk,2)?(c[k-2]-'0'):(-1));
				if(i==0) AA=0;
				if(j==0) BB=0;
				if(CC!=-1 && (AA+BB+delta)%10 != CC) continue;
				if(CC==-1) CC=(AA+BB+delta)%10;
				int rm=(AA+BB+delta)>9;
				int MMM=((i==1||(i==2&&bit(msk,0))) && AA!=0)+2*((j==1||(j==2&&bit(msk,1))) && BB!=0)+4*((k==1||(k==2&&bit(msk,2))) && CC!=0);
				int MSK=MMM;
				while(MSK>0){
				    UPD(i,j,k,rm,msk,MSK,AA,BB,CC,delta);
				    MSK=(MSK-1)&MMM;
				}
				UPD(i,j,k,rm,msk,0,AA,BB,CC,delta);
			    }
			}
		    }
		}

		if((dp[i][j][k][1]+tdo[0])<dp[i][j][k][0]){
		    dp[i][j][k][0]=dp[i][j][k][1]+tdo[0];
		    lst[i][j][k][0]=tdl[0];
		}
		if((dp[i][j][j][0]+tdo[1])<dp[i][j][k][0]){
		    dp[i][j][k][1]=dp[i][j][k][0]+tdo[1];
		    lst[i][j][k][1]=tdl[1];
		}

	    }
	}
    }

    string A,B,C;
    int rm=0;
    while(na>=2 || nb>=2 || nc>=2 || rm>0){
	int NUM=lst[na][nb][nc][rm].F.F,msk1=lst[na][nb][nc][rm].F.S,msk2=lst[na][nb][nc][rm].S;
	int aa=(NUM/100),bb=((NUM/10)%10),cc=(NUM%10);
	if(na>0)
	    A=char(aa+'0')+A;
	if(nb>0)
	    B=char(bb+'0')+B;
	if(nc>0)
	    C=char(cc+'0')+C;
	rm=(rm+aa+bb)/10;
	na-=bit(msk1,0)+bit(msk2,0);
	nb-=bit(msk1,1)+bit(msk2,1);
	nc-=bit(msk1,2)+bit(msk2,2);
    }
    cout<<A<<"+"<<B<<"="<<C<<endl;
}