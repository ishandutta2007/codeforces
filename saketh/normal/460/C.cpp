#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, W, M;
long long height[100005];
long long waters[100005];

int main(){
    cin >> N >> M >> W;
    for(int i=0; i<N; i++)
        cin >> height[i];

    long long high = 2000000000;
    long long low = 1;
    long long best = 1;

    while(low <= high){
        long long mid = (low + high) / 2;
        long long days_needed = 0;
        long long waters_active = 0;

        for(int i = 0; i<N; i++){
            if(i >= W) waters_active -= waters[i - W];
            long long needed_here = max(0LL, mid - height[i] - waters_active);
            waters[i] = needed_here;
            waters_active += waters[i];
            days_needed += waters[i];
        }

        if(days_needed <= M){
            best = max(best, mid);
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << best << endl;
    return 0;
}