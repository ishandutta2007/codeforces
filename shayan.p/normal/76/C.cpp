// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxN=2e5+10,maxC=23,maxMSK=4194304+20;

int c[maxC],cs[maxC][maxC];
ll MSK[maxMSK],CMM;
pii lst[maxC];
char ch[maxN];

int main(){
    int n,k,t;scanf("%d%d%d",&n,&k,&t);
    scanf("%s",ch);
    for(int i=0;i<n;i++)
	CMM|=(1<<(ch[i]-'A'));
    CMM^=((1<<k)-1);
    for(int i=0;i<k;i++)
	scanf("%d",&c[i]);
    for(int i=0;i<k;i++)
	for(int j=0;j<k;j++)
	    scanf("%d",&cs[i][j]);
    for(int i=0;i<k;i++)
	lst[i]={n,i};
    for(int i=n-1;i>=0;i--){
	int bef=0,msk=0;
	for(int j=0;j<k && lst[j].F<n;j++){
	    int num=cs[ch[i]-'A'][lst[j].S]-bef;
	    MSK[msk]+=num;
	    MSK[msk^(1<<(ch[i]-'A'))]-=num;
	    bef=cs[ch[i]-'A'][lst[j].S];
	    msk|=(1<<lst[j].S);
	    if(lst[j].S==(ch[i]-'A'))break;
	}
	if(!bit(msk,(ch[i]-'A'))){
	    MSK[msk]-=bef;
	    MSK[msk^(1<<(ch[i]-'A'))]+=bef;
	}
	for(int j=0;j<k;j++)
	    swap(lst[j].F,lst[j].S);
	sort(lst,lst+k);
	lst[ch[i]-'A'].S=i;
	for(int j=0;j<k;j++)
	    swap(lst[j].F,lst[j].S);
	sort(lst,lst+k);
    }
    for(int i=0;i<k;i++){
	for(int j=(1<<k)-1;j>=0;j--){
	    if(bit(j,i)) MSK[j]+=MSK[j^(1<<i)];
	}
    }
    int ans=0;
    for(int i=0;i<(1<<k);i++){
	if(i&CMM)continue;
	if((CMM|i) == ((1<<k)-1))continue;
	for(int j=0;j<k;j++){
	    if(bit(i,j)) MSK[i]+=c[j];
	}
	if(MSK[i]<=t)
	    ans++;
    }
    printf("%d\n",ans);
    return 0;
}