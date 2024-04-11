#include <iostream>
#include <algorithm>
using namespace std;

int N, X;
long long chap[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> X;
    for(int i=0; i<N; i++)
        cin >> chap[i];
    sort(chap, chap + N);

    long long ans = 0;
    for(int i=0; i<N; i++){
        ans += chap[i] * X;
        if(X > 1) X--;
    }
    cout << ans << endl;
}