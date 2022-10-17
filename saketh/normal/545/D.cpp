#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
int v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> v[i];

    sort(v, v+N);
    
    int ans = 0;
    long long wait = 0;
    
    for(int i=0; i<N; i++){
        if(v[i] >= wait){
            wait += v[i];
            ans++;
        }
    }

    cout << ans << endl;
}