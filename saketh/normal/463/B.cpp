#include <iostream>
using namespace std;

int N, H;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin >> N;
    int ans = 0;
    for(int i=0; i<N; i++){
        cin >> H;
        ans = max(ans, H);
    }
    cout << ans << endl;
    return 0;
}