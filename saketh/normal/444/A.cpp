#include <iostream>
using namespace std;

int N, M;
double w[512];

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> w[i];

    double ans = 0;
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b; a--; b--;
        double c; cin >> c;
        ans = max(ans, (w[a] + w[b])/c);
    }

    cout.precision(20);
    cout << ans << endl;
    return 0;
}