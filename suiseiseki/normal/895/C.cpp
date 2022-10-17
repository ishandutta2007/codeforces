#include <cstdio>
#define maxn 100000
#define mod 1000000007
const int prime[20]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int a[maxn+5];
int s[75];
int cnt[1005];
int f[75][1<<19|5];
int p2[maxn+5];
int main(){
	int n;
    scanf("%d",&n);
    int tmp;
    for(int i=1;i<=70;i++){
        tmp=i;
        for(int j=1;j<20;j++){
            while(tmp%prime[j]==0){
                s[i]^=1<<j-1;
                tmp/=prime[j];
            }
        }
    }
    p2[0]=1;
    for(int i=1;i<=n;i++){
    	p2[i]=(p2[i-1]*2)%mod;
	}
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
		++cnt[a[i]];
	}
    f[0][0]=1;
    for(int i=1;i<=70;i++){
        if(cnt[i]){
            for(int j=0;j<1<<19;j++){
                f[i][j^s[i]]=((long long)f[i][j^s[i]]+((long long)p2[cnt[i]-1]*(long long)f[i-1][j]))%mod;
                f[i][j]=((long long)f[i][j]+(long long)p2[cnt[i]-1]*f[i-1][j])%mod;
            }
        }
		else{
            for(int j=0;j<1<<19;j++){
            	f[i][j]=f[i-1][j];
			}
        }
    }
    printf("%d\n",(f[70][0]-1+mod)%mod);
    return 0;
}