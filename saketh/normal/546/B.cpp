#include <iostream>
#include <algorithm>
using namespace std;

int N;
int b[3005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> b[i];

    sort(b, b+N);

    int ans = 0;
    for(int i=1; i<N; i++){
        if(b[i] <= b[i-1]){
            ans += b[i-1] + 1 - b[i];
            b[i] = b[i-1] + 1;
        }
    }

    cout << ans << endl;
}