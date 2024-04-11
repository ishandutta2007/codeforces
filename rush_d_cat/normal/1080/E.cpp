#include <iostream>
using namespace std;
const int N = 250+2;
typedef long long LL;
const int MOD = 1e9 + 7;
const int B = 10007;

int n,m;char s[N][N];
int cnt[N][200],odd[N]; int h[N],str[N<<1];
int p[N],r[N<<1];

int cac() {
    for(int i=1;i<=n;i++){
        if(odd[i]<=1)str[i*2]=h[i];
        else str[i*2]=-i;
        str[i*2+1]='#';
    }
    str[0]='?',str[1]='#',str[2*n+2]='\0';
    int res=0,k=0,maxk=0; 
    for(int i=2;i<2*n+2;i++)
    {
        r[i] = i < maxk ? min(maxk - i, r[2*k-i]) : 1;
        while(str[i-r[i]] == str[i+r[i]]) r[i]++;
        if(str[i]>=0){
            res+=(i/2) - (i-r[i]+1)/2; 
        }
    }
    return res;
}

int main() {
    p[0]=1; for(int i=1;i<N;i++)p[i]=(LL)p[i-1]*B%MOD;

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    int ans=0;
    for(int l=1;l<=m;l++){
        for(int i=1;i<=n;i++){
            odd[i]=0,h[i]=0;for(int j='a';j<='z';j++)cnt[i][j]=0;
        }
        for(int r=l;r<=m;r++){
            for(int i=1;i<=n;i++){
                cnt[i][s[i][r]] ++; 
                if(cnt[i][s[i][r]]%2==1) odd[i]++; else odd[i]--;
                (h[i] += p[s[i][r]]) %= MOD;
            }
            ans += cac(); //printf("\n");
        }
    }
    cout<<ans<<endl;
}