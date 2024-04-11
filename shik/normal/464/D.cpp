#include <cstdio>
const int N=550;
double dp[N];
double mul[N];
int n,k;
int main(){
    while(~scanf("%d %d",&n,&k)){
        for(int i=1;i<N;i++){dp[i]=0;}
        dp[1]=k;
        for(int j=1;j<N;j++)mul[j]=((double)j/2+(double)j/(j+1))/k;
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=N-2;j>=0;j--){
                double tmp=dp[j];
                if (tmp<1e-100) continue;
                double div=(j+1)*k;
                ans+=tmp*mul[j];
                dp[j+1]+= tmp /div;
                dp[j]= tmp*(1-1/div);
            }
        }
        printf("%.10lf\n",ans);
    }
}