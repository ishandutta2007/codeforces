#include<iostream>
#include<vector>
using namespace std;

int N;
int val[100005];
int sum[100005];

int main(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> val[i];
        sum[i] = val[i];
        if(i) sum[i] += sum[i-1];
    }
    
    long long ans = 1LL << 50;
    
    for(int l=1; l<N; l++){
        long long tmp = l*l;
        if(tmp >= ans) break;
        for(int i=1; i+l<=N; i++){
            int j = i+l;
            long long g = sum[j-1]-sum[i-1];
            ans = min(ans, tmp + g*g);
        }
    }
    
    cout << ans << endl;
    return 0;
}