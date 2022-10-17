#include <iostream>
#include <algorithm>
using namespace std;

int N, V;
int a[100005], b[100005];

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> V;

        a[i] = V;
        b[i] = V;
    }

    sort(b, b+N);

    int l = N, h = -1;

    for(int i=0; i<N; i++)
        if(a[i] != b[i]){
            l = min(l, i);
            h = max(h, i);
        }

    if(l == N){
        cout << "yes" << endl << "1 1" << endl;
        return 0;
    }

    reverse(a+l, a+h+1);

    bool good = true;
    for(int i=0; i<N; i++)
        good &= a[i] == b[i];

    if(good) cout << "yes" << endl << l+1 << " " << h+1 << endl;
    else cout << "no" << endl;

    return 0;
}