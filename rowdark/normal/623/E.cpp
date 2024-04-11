#include<iostream>
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

typedef long long LL;

const int mod=1000000007;

int tmpA[20][30001];
int tmpB[20][30001];
int tmpC[20][30001];
int tmpD[20][30001];
int tmpE[20][30001];

#define add2(x, y) if((x+=y)>=mod)x-=mod

/*inline void add2(int &a,int const &b){
	a+=b;
	if(a>=mod) a-=mod;
}*/

unsigned long long tmpsD[40],tmpsE[40];

void multiply2(const int* const &A,const int* const &B,const int* const &C,int* const &D,int* const &E,int const &len,int const &id){
	if(len<19){
		REP_1(i,len) REP_1(j,len){
			tmpsD[i+j]+=(LL)A[i]*C[j];
			tmpsE[i+j]+=(LL)B[i]*C[j];
		}
		REP_1(i,len*2){
			D[i]=tmpsD[i]%mod;
			tmpsD[i]=0;
			E[i]=tmpsE[i]%mod;
			tmpsE[i]=0;
		}
		return;
	}
	int halflen=len>>1,halflen2=len-halflen;
	const int* const AA=A+halflen;
	const int* const BB=B+halflen;
	const int* const CC=C+halflen;
	int* const DD=D+halflen+halflen;
	int* const EE=E+halflen+halflen;
	multiply2(A,B,C,D,E,halflen,id);
	multiply2(AA,BB,CC,DD,EE,halflen2,id);
	int* const NA=tmpA[id];
	int* const NB=tmpB[id];
	int* const NC=tmpC[id];
	int* const ND=tmpD[id];
	int* const NE=tmpE[id];
	REP_1(i,halflen){
		NA[i]=A[i];
		add2(NA[i],AA[i]);
		NB[i]=B[i];
		add2(NB[i],BB[i]);
		NC[i]=C[i];
		add2(NC[i],CC[i]);
	}
	if(halflen2!=halflen){
		NA[halflen2]=AA[halflen2];
		NB[halflen2]=BB[halflen2];
		NC[halflen2]=CC[halflen2];
	}
	multiply2(NA,NB,NC,ND,NE,halflen2,id+1);
	REP_1(i,halflen*2){
		add2(ND[i],mod-D[i]);
		add2(ND[i],mod-DD[i]);
		add2(NE[i],mod-E[i]);
		add2(NE[i],mod-EE[i]);
	}
	if(halflen2!=halflen){
		add2(ND[halflen2*2-1],mod-DD[halflen2*2-1]);
		add2(ND[halflen2*2],mod-DD[halflen2*2]);
		add2(NE[halflen2*2-1],mod-EE[halflen2*2-1]);
		add2(NE[halflen2*2],mod-EE[halflen2*2]);
	}
	REP_1(i,halflen2*2){
		add2(D[i+halflen],ND[i]);
		add2(E[i+halflen],NE[i]);
		ND[i]=NE[i]=0;
	}
}

void multiply(const int* const &A,const int* const &B,int* const &D,int const &len,int const &id){
	if(len<19){
		REP_1(i,len) REP_1(j,len){
			tmpsD[i+j]+=(LL)A[i]*B[j];
		}
		REP_1(i,len*2){
			D[i]=tmpsD[i]%mod;
			tmpsD[i]=0;
		}
		return;
	}
	int halflen=len>>1,halflen2=len-halflen;
	const int* const AA=A+halflen;
	const int* const BB=B+halflen;
	int* const DD=D+halflen+halflen;
	multiply(A,B,D,halflen,id);
	multiply(AA,BB,DD,halflen2,id);
	int* const NA=tmpA[id];
	int* const NB=tmpB[id];
	int* const ND=tmpD[id];
	REP_1(i,halflen){
		NA[i]=A[i];
		add2(NA[i],AA[i]);
		NB[i]=B[i];
		add2(NB[i],BB[i]);
	}
	if(halflen2!=halflen){
		NA[halflen2]=AA[halflen2];
		NB[halflen2]=BB[halflen2];
	}
	multiply(NA,NB,ND,halflen2,id+1);
	REP_1(i,halflen*2){
		add2(ND[i],mod-D[i]);
		add2(ND[i],mod-DD[i]);
	}
	if(halflen2!=halflen){
		add2(ND[halflen2*2-1],mod-DD[halflen2*2-1]);
		add2(ND[halflen2*2],mod-DD[halflen2*2]);
	}
	REP_1(i,halflen2*2){
		add2(D[i+halflen],ND[i]);
		ND[i]=0;
	}
}

int polyA[60001];
int polyB[60001];
int polyC[60001];
int polyD[70001];
int polyE[70001];

LL N,K;

LL fact[30001];
LL invfact[30001];
LL inv[30001];

int main(){
	fact[0]=invfact[0]=1;
	REP_1(i,30000){
		fact[i]=fact[i-1]*i%mod;
		inv[i]=i==1?1LL:mod-mod/i*inv[mod%i]%mod;
		invfact[i]=invfact[i-1]*inv[i]%mod;
	}
	cin>>N>>K;
	if(N>K){
		printf("0\n");
		return 0;
	}
	LL NP=2;
	REP_1(i,K) polyA[i]=polyB[i]=1; 
	--N;
	int preZero=0;
	for(int msk=1;msk<=N;msk<<=1){
		REP_1(i,K){
			polyC[i]=polyB[i]*invfact[i]%mod;
		}
		if(N&msk){
			register LL NPP=NP;
			REP_1(i,K){
				polyA[i]=polyA[i]*NPP%mod*invfact[i]%mod;
				polyB[i]=polyC[i]*NPP%mod;
				NPP=NPP*NP%mod;
			}
			multiply2(polyA+preZero,polyB+msk-1,polyC+msk-1,polyD+preZero+msk-1,polyE+msk*2-2,K-preZero-msk+1,0);
			/*multiply(polyA+preZero,polyC+msk-1,polyD+preZero+msk-1,K-preZero-msk+1,0);
			multiply(polyB+msk-1,polyC+msk-1,polyE+2*msk-2,K-2*msk+2,0);*/
			REP_1(i,K){
				polyA[i]=polyD[i]*fact[i]%mod;
				polyD[i]=polyD[K+i]=0;
				polyB[i]=polyE[i]*fact[i]%mod;
				polyE[i]=polyE[K+i]=0;
			}
			preZero+=msk;
		}
		else{
			register LL NPP=NP;
			REP_1(i,K){
				polyB[i]=polyC[i]*NPP%mod;
				NPP=NPP*NP%mod;
			}
			multiply(polyB+msk-1,polyC+msk-1,polyE+2*msk-2,K-2*msk+2,0);
			REP_1(i,K){
				polyB[i]=polyE[i]*fact[i]%mod;
				polyE[i]=polyE[K+i]=0;
			}
		}
		NP=NP*NP%mod;
	}
	LL ans=0;
	REP_3(i,N,K){
		ans=(ans+polyA[i]*invfact[i]%mod*invfact[K-i])%mod;
	}
	cout<<ans*fact[K]%mod<<endl;
	cin>>N;
	return 0;
}