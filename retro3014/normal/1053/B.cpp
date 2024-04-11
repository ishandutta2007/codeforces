#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
#define MAX_N 300000
typedef long long ll;

int N;
int arr[MAX_N+1];
int sum[MAX_N+1];
int cnt[2][MAX_N+1];
ll ans=0;

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        ll t;int k=0;
        scanf("%lld", &t);
        while(t>0){
            if(t%2==1){
                k++;
            }
            t/=2;
        }
        arr[i]=k;
        sum[i]=sum[i-1]+arr[i];
        cnt[0][i]=cnt[0][i-1]; cnt[1][i]=cnt[1][i-1];
        cnt[sum[i]%2][i]++;
    }
    for(int i=1; i<=N; i++){
        int mx=arr[i];
        for(int j=i+1; j<=N; j++){
            if(sum[j]-sum[i-1]>=150){
                ans+=(ll)(cnt[sum[i-1]%2][N]-cnt[sum[i-1]%2][j-1]);
                break;
            }
            else{
                mx=max(mx, arr[j]);
                if((sum[j]-sum[i-1])%2==0){
                    if(sum[j]-sum[i-1]>=mx*2){
                        ans++;
                    }
                }
            }
        }
    }
    printf("%lld", ans);
    return 0;
}