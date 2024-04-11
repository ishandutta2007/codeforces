#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
#define For(i,a,b) for(i=(a),i<=(b);++i)
#define Forward(i,a,b) for(i=(a),i>=(b);--i)
template<typename T>
void read(T &x){
    T f=1;
	x=0;
	char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+(c^48);
    x*=f;
}
using namespace std;
int n,k;
const int mod=1e9+7;
const int MAXN=5e3+7;
static int S[MAXN][MAXN];
void predone(int lim){
    S[0][0]=1;
    Rep(i,1,lim){
    	Rep(j,1,i){
    		S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j%mod)%mod;
		}
	}
}
int ans;
int power(int a,int b){
    int sum;
    for(sum=1;b;b>>=1,a=1ll*a*a%mod){
		if(b&1){
			sum=1ll*sum*a%mod;
		}
	}
    return sum;
}
int main(){
    read(n);
	read(k);
    predone(k);
    int lag=1,p2=power(2,n),inv2=power(2,mod-2);
	Rep(i,0,k){
		ans=(ans+1ll*lag*S[k][i]%mod*p2%mod)%mod;
		lag=1ll*lag*(n-i)%mod;
		p2=1ll*p2*inv2%mod;
    }
    if(!k){
    	ans--;
    }
    printf("%d\n",ans);
    return 0;
}