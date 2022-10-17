#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

int N, Z;
double nums[4048];

int main(){
    setup();
    
    double tot = 0;

    cin >> N;
    for(int i=0; i<2*N; i++){
        cin >> nums[i];
        nums[i] -= floor(nums[i]);
        if(nums[i] < 1e-7) Z++;
        tot -= nums[i];
    }

    double ans = 1e9;
    for(int zu = 0; zu <= min(Z, N); zu++){
        double dif = tot + N - zu;
        ans = min(ans, fabs(dif));
    }

    printf("%.3f\n", ans);
}