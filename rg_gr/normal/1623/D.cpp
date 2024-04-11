#include<bits/stdc++.h>
#define BetterIO ios::sync_with_stdio(false)
using namespace std;
#define int long long
const int Mod=1000000007;
inline int Qpow(int x,int p)
{
	int Res=1;while(p)
	{
		if(p&1)Res=Res*x%Mod;
		x=x*x%Mod;
		p>>=1;
	}
	return Res;
}
signed main(void)
{
    BetterIO;
   	int Case=1;cin>>Case;while(Case--)
   	{
   		int N,M,A,B,C,D;cin>>N>>M>>A>>B>>C>>D;
   		vector<vector<vector<int> > > Vis(N+3);
   		for(int i=0;i<=N+2;i++)Vis[i]=vector<vector<int> >(M+3);
   		for(int i=0;i<=N+2;i++)
   			for(int j=0;j<=M+2;j++)
   				Vis[i][j]=vector<int>(4);
   		vector<int>Anss;
   		int CN=1,CM=1,Ans=0,dD=0;
   		while(1)
   		{
   			if(A==N)CN=-1;
   			if(A==1)CN=1;
   			if(B==M)CM=-1;
   			if(B==1)CM=1;
   			if(CN>0&&CM>0)dD=0;
   			else if(CN>0)dD=1;
   			else if(CM>0)dD=2;
   			else dD=3;
   			if(Vis[A][B][dD])break;
   			// cout<<A<<' '<<B<<' '<<dD<<endl;
   			Vis[A][B][dD]=1;
   			
   			if(A==C||B==D)Anss.push_back(Ans);
   			Ans++;
   			A+=CN;
   			B+=CM;
   			// cout<<A<<' '<<B<<endl;
   		}
   		int Sol=Anss.size();
   		// cout<<Sol<<endl;
   		int Once=0,Prob=1;
   		int P;cin>>P;
   		P=P*Qpow(100,Mod-2)%Mod;
   		for(int i=0;i<Anss.size();i++)
   		{
   			Once=(Once+Prob*P%Mod*Anss[i])%Mod;
   			Prob=Prob*(Mod+1-P)%Mod;
   			// cout<<Anss[i]<<' ';
   		}
   		// cout<<Once*4%Mod<<endl;
   		// cout
   		// D=;
   		P=Qpow((Mod+1-P),Sol);
   		D=Mod+1-P;
   		assert(P==Prob);
   		// int Rr=Once*Qpow((Mod+1-P),Mod-2)%Mod%Mod;
   		// int Rr=Once;
   		// int Rr=Once*Qpow(Mod+1-P,Mod-2)%Mod*P%Mod;
   		int Rr=Once*Qpow(Mod+1-P,Mod-2)%Mod;
   		// odl(Once)
   		int T2=Ans*Qpow(Mod+1-P,Mod-2)%Mod*P%Mod;
   		
   		// int s=
   		// cout<<Rr*7%Mod<<endl;
   		// cout<<T2*7%Mod<<endl;
   		// int T2=Sol*Qpow(((1-P)*(1-P)%Mod+Mod)%Mod,Mod-2)%Mod*P%Mod*(D)%Mod;
   		// cout<<T2*7%Mod<<endl;
   		// cout<<Sol<<endl;
   		// cout<<Qpow(P+1,Mod-2)<<endl;
   		cout<<(Rr+T2)%Mod<<'\n'
;   		// cout<<Ans<<'\n';
   		// for()
   	}
    return 0;
}