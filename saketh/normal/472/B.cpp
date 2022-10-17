#include <iostream>
#include <queue>
using namespace std;

int N, K, T;
priority_queue<int> pp;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> T;
        pp.push(-1 * T);
    }

    int ans = 0;

    for(int i=2; i<=2000; i++){
        int trips = (pp.size() + K - 1) / K;
        ans += 2 * trips - 1;
        while(!pp.empty() && (-1*pp.top()) == i) pp.pop();
        if(pp.empty()){
            ans += i-1;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}