#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
const ll INF = 0x7f7f7f7f7f;

int N;
ll x[MAXN];
ll h[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    x[0] = -INF;
    for(int i=1; i<=N; i++)
        cin >> x[i] >> h[i];
    x[N+1] = INF;

    int ans = 0;
    for(int i=1; i<=N; i++){
        if(x[i] - x[i-1] > h[i]){
            ans++;
        }
        else if(x[i+1]-x[i] > h[i]){
            ans++;
            x[i] += h[i];
        }
    }

    cout << ans << endl;
}