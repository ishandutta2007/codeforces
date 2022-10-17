#include <iostream>
#include <algorithm>
using namespace std;

int N;
string a, b;

int best(int i, int j){
    return min(abs(i-j), 10-abs(i-j));
}   

int main(){
    cin >> N >> a >> b;

    int ans = 0;
    for(int i=0; i<N; i++){
        ans += best(a[i] - '0', b[i] - '0');
    }

    cout << ans << endl;
}