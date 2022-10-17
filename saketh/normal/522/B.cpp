#include <iostream>
using namespace std;

const int MAXN = 200005;

int N, w[MAXN], h[MAXN];
int wi[MAXN], hi[MAXN];
int wj[MAXN], hj[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> w[i] >> h[i];

    for(int i=1; i<=N; i++){
        wi[i] = wi[i-1] + w[i-1];
        hi[i] = max(hi[i-1], h[i-1]);
    }

    for(int j=N-1; j>=0; j--){
        wj[j] = wj[j+1] + w[j];
        hj[j] = max(hj[j+1], h[j]);
    }

    for(int k=0; k<N; k++){
        int w = wi[k] + wj[k+1];
        int h = max(hi[k], hj[k+1]);
        cout << w * h << " ";
    }

    cout << endl;
    return 0;
}